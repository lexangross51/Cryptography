#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <string>

struct tree_node
{
	tree_node* left;	// Левый потомок
	tree_node* right;	// Правый потомок
	char sym;			// Символ
	double prob;		// Вероятность появления символа

	// Конструктор для листового узла
	tree_node(char _sym, double _prob = 0, tree_node* _left = nullptr, tree_node* _right = nullptr) :
		sym(_sym), prob(_prob), left(_left), right(_right) {}

	// Конструктор для родительского узла
	tree_node(tree_node* _left, tree_node* _right) :
		tree_node(_left->sym + _right->sym, _left->prob + _right->prob, _left, _right) {}

	~tree_node()
	{
		delete left;
		delete right;
	}
};

struct compare
{
	bool operator()(tree_node* left, tree_node* right)
	{
		return left->prob > right->prob;
	}
};

#endif