#include "Huffman.h"
#include <fstream>
#include <iostream>
#include <map>


// Формируем кодовое дерево Хаффмана
void Huffman::buildTree(std::priority_queue<tree_node*,
	std::vector<tree_node*>, compare>& pq)
{
	// Пока в очереди больше 1 элемента (т.е. есть пары элементов)
	while (pq.size() > 1)
	{
		// То извлекаем пары элементов
		tree_node* el1 = pq.top();
		pq.pop();
		tree_node* el2 = pq.top();
		pq.pop();

		// И формируем из них родительский узел, который будет
		// указывать на эти элементы
		pq.push(makeParent(el1, el2));
	}

	// Оставшийся в очереди элемент будет корнем кодового дерева
	tree = pq.top();
	pq.pop();
}

// Строим таблицу кодов Хаффмана
void Huffman::buildCodeTable(tree_node* tree, std::string code)
{
	// Если дерево не пусто
	if (tree)
	{
		// Тогда если узел является листом
		if (isLeaf(tree))
			// Записываем инфу о нем и его код в таблицу кодов
			code_table.push_back({ tree->sym, tree->prob, code });

		// Рекурсивно проходим по всем символам дерева
		buildCodeTable(tree->left, code + "0");
		buildCodeTable(tree->right, code + "1");
	}
}

// Проверить, что узел является листом
bool Huffman::isLeaf(tree_node* node)
{
	return node->left == NULL && node->right == NULL;
}

// Сформировать родительский узел
tree_node* Huffman::makeParent(tree_node* left, tree_node* right)
{
	return new tree_node(left, right);
}

// Получить среднюю длину кодового слова
double Huffman::getAverageLenght()
{
	double len = 0;

	for (elem sym : code_table)
		len += sym.prob * sym.code.length();

	return len;
}

// Получить энтропию
double Huffman::getEntropy()
{
	double entropy = 0;

	for (elem sym : code_table)
	{
		if (sym.prob != 0.0)
			entropy += sym.prob * log2(1 / sym.prob);
		else
			continue;
	}

	return entropy;
}

// Получить избыточность
double Huffman::getRedundancy()
{
	return getAverageLenght() - getEntropy();
}

// Проверить неравенство Крафта
bool Huffman::KraftInequality()
{
	double sum = 0;

	// 2 означает двоичный алфавит
	// По формуле: сумма(1 / pow(2, длина каждого кода)) <= 1
	for (elem sym : code_table)
		sum += 1 / pow(2, sym.code.length());

	return sum <= 1;
}

// Закодировать на основе имеющейся таблицы
void Huffman::encode_by_table(std::string out)
{
	std::ofstream outtext(out);

	// Закодированный текст
	std::string encoded_text = "";

	for (size_t j = 0; j < text.size(); j++)
	{
		bool find = true;

		for (auto i = code_table.begin(); i != code_table.end() && find; ++i)
			if (i->sym == text[j])
			{
				encoded_text += i->code;
				find = false;
			}
	}

	if (outtext.is_open())
	{
		outtext << encoded_text;
		outtext.close();
	}
}

// Записать таблицу кодов в файл
void Huffman::writeTable(std::string _codes)
{
	std::ofstream codes(_codes);
	if (codes.is_open())
	{
		for (size_t i = 0; i < code_table.size(); i++)
			codes << code_table[i].sym << ":\t" << code_table[i].code << std::endl;
		codes.close();
	}
	else
		std::cerr << "File can't be opened!!!" << std::endl;
}

// Очистить таблицу
void Huffman::clearTable() 
{
	code_table.clear();
	delete tree;
	tree = NULL;
}

// Считываем текст из файла
void Huffman::readText(std::string file)
{
	text.clear();
	std::ifstream in(file);
	if (in.is_open())
	{
		std::string line;
		char ch;
		while (std::getline(in, line))
			text += line;

		in.close();
	}
	else
		std::cerr << "File can't be opened" << std::endl;
}

// Кодируем алфавит
void Huffman::encodeAlphabet(std::string _alph, std::string _probs, std::string _codes)
{
	std::ifstream alph(_alph);
	std::ifstream probs(_probs);

	if (alph.is_open() && probs.is_open())
	{
		std::priority_queue<tree_node*, std::vector<tree_node*>, compare> pq;
		char sym;
		double prob;

		while (alph >> sym && probs >> prob)
			pq.push(new tree_node(sym, prob));

		alph.close();
		probs.close();

		// Строим дерево кодов
		buildTree(pq);

		// Создаем таблицу кодов
		buildCodeTable(tree);

		// Записываем таблицу
		writeTable(_codes);
	}
	else
		std::cerr << "Files can't be opened!!!" << std::endl;
}

// Кодируем исходный текст
void Huffman::encode(std::string outtext, std::string codes)
{
	std::priority_queue<tree_node*, std::vector<tree_node*>, compare> pq;
	std::map<char, size_t> probs;

	size_t chars_count = 0;
	for (size_t i = 0; i < text.size(); i++)
	{
		++probs[text[i]];
		++chars_count;
	}

	for (auto sym : probs)
		pq.push(new tree_node(sym.first, static_cast<double>(sym.second) / chars_count));

	// Создаем кодовое дерево
	buildTree(pq);

	// Создаем кодовую таблицу
	buildCodeTable(tree);

	// Записываем коды в файл
	writeTable(codes);

	// Кодируем на основе созданной таблицы
	encode_by_table(outtext);
}

// Декодируем заданный текст
void Huffman::decode(std::string intext, std::string outtext)
{
	std::ifstream in(intext);
	std::ofstream out(outtext);

	if (in.is_open() && out.is_open())
	{
		// Указатель на корень кодового дерева
		tree_node* treePtr = tree;

		char bit;
		while (in >> bit)
		{	// Вычисляем ветвь
			treePtr = bit == '0' ? treePtr->left : treePtr->right;

			// Если символ найден
			if (isLeaf(treePtr))
			{
				// Записываем декодированный символ в файл
				out << treePtr->sym;

				// И идем обратно к корню дерева
				treePtr = tree;
			}
		}
		in.close();
		out.close();
	}
	std::cerr << "Files can't be opened!!!" << std::endl;
}