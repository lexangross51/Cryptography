#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<string>
#include<vector>
#include<queue>
#include "node.h"

class Huffman
{
	// Элемент таблицы
	struct elem
	{
		char sym;
		double prob;
		std::string code;
	};

public:
	// Закодировать на основе имеющейся таблицы
	void encode_by_table(std::string out);

	// Метод для кодирования текста
	void encode(std::string outtext, std::string codes);

	// Метод для кодирования алфавита
	void encodeAlphabet(std::string alph, std::string probs, std::string codes);

	// Метод для декодирвоания данных
	void decode(std::string intext, std::string outtext);

	// Очистить таблицу кодов
	void clearTable();

	// Считать текст
	void readText(std::string file);

	// Проверить, пустая ли таблица
	bool isEmptyTable() { return code_table.empty(); }

	// Проверить, был ли считан текст
	bool isEmptyText() { return text.empty(); }

	// Получить избыточность
	double getRedundancy();

	// Проверить неравенство Крафта
	bool KraftInequality();

	// Получить среднюю длину кода
	double getAverageLenght();

private:
	// Кодовая таблица (для кодирвоания)
	std::vector<elem> code_table;

	// Кодовое дерево (для декодирования)
	tree_node* tree = NULL;

	// Считанный текст
	std::string text;

	// Сформировать родительский узел
	tree_node* makeParent(tree_node* left, tree_node* right);

	bool isLeaf(tree_node* node);

	// Построить дерево Хаффмана
	void buildTree(std::priority_queue<tree_node*, std::vector<tree_node*>, compare>& pq);

	// Построить кодовую таблицу
	void buildCodeTable(tree_node* tree, std::string code = std::string());
	
	// Записать таблицу кодов в файл
	void writeTable(std::string file);

	// Получить энтропию
	double getEntropy();
};


#endif

