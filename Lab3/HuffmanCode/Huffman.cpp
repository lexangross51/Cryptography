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
		pq.push(makeParent(el2, el1));
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
		{
			bool find = true;
			for(auto i = code_table.begin(); i != code_table.end() && find; i++)
				if (i->sym == tree->sym)
				{
					i->prob = tree->prob;
					i->code = code;
					find = false;
				}
		}

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
	auto parent = new tree_node(left, right);
	return parent;
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

	for (auto chr : text) 
	{	
		bool find = true;
		for (auto i = code_table.begin(); i != code_table.end() && find; ++i)
			if (i->sym == chr) 
			{			
				encoded_text += i->code;	

				encoded_text += getBit(i->code);

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
			if (prob != 0.0)
			{
				code_table.push_back({ sym, prob, std::string() });
				pq.push(new tree_node(sym, prob));
			}

		alph.close();
		probs.close();

		if (isEven(code_table.size()))
		{
			// Строим дерево кодов
			buildTree(pq);

			// Создаем таблицу кодов
			buildCodeTable(tree);

			// Записываем таблицу
			writeTable(_codes);
		}
		else
			clearTable();
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
	for (auto chr : text)
		++probs[chr];

	double prob = 0;
	for (auto sym : probs)
	{
		prob = static_cast<double>(sym.second) / text.size();
		code_table.push_back({ sym.first, prob, std::string() });
		pq.push(new tree_node(sym.first, prob));
	}

	if (isEven(code_table.size()))
	{
		// Создаем кодовое дерево
		buildTree(pq);

		// Создаем кодовую таблицу
		buildCodeTable(tree);

		// Кодируем на основе созданной таблицы
		encode_by_table(outtext);

		// Записываем коды в файл
		writeTable(codes);
	}
	else
		clearTable();
}

// Декодируем заданный текст
void Huffman::decode(std::string intext, std::string outtext)
{
	std::ifstream in(intext);
	std::ofstream out(outtext);
	std::string decoded_text;
	std::string txt, line;

	if (in.is_open())
	{
		while (getline(in, line))
			txt += line;
		in.close();
	}
	else
		std::cerr << "File can't be opened!" << std::endl;

	size_t wordLen = code_table[0].code.length();

	for (size_t i = 0; i < txt.size() - 1 ; i++)
	{
		int bit = charToInt(txt[i]);
		for (size_t j = 1; j < wordLen + 1; j++)
			bit = (bit ^ charToInt(txt[i + j]));

		if (bit == 0)
		{
			auto treePtr = tree;
			while (!isLeaf(treePtr))
				treePtr = txt[i++] == '0' ? treePtr->left : treePtr->right;

			decoded_text += treePtr->sym;
			treePtr = tree;
		}
		else
		{
			for (size_t j = 0; j < wordLen + 1; j++)
				txt[i + j] = 'X';

			i += wordLen;
		}
	}

	if (out.is_open())
	{	
		out << decoded_text;
		out.close();
	}
	else
		std::cerr << "File can't be opened!" << std::endl;

	std::ofstream inc(intext);
	if (inc.is_open())
	{
		inc << txt;
		inc.close();
	}
	else
		std::cerr << "File can't be opened!" << std::endl;
}

// Получить контрольный бит
char Huffman::getBit(std::string code)
{
	char bit = 0;

	if (!code.empty())
	{
		bit = charToInt(code[0]);

		for (size_t i = 1; i < code.size(); i++)
			bit = (bit ^ charToInt(code[i]));
	}
	return intToChar(bit);
}

bool Huffman::isEven(size_t x)
{
	return (0 < x && !(x & (x - 1)));
}