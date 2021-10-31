#ifndef HAMMING_H
#define HAMMING_H

#include <string>
#include <vector>

class Hamming
{
	struct elem
	{
		int sign;
		std::string code;
		std::string code_hash;
	};

public:
	void readAlphabbet();
	void readMatrix();
	void readText();

	void makeCodeHash();
	std::string getCodeHash();
	std::string encode();
	std::string decode();

	size_t getErrCount();
	std::vector<size_t> getErrPos();
	
	void clearTable();
	bool isEmptyTable() { return code_table.empty(); }

private:
	size_t n;
	size_t r;

	std::string text;
	std::vector<elem> code_table;
	std::vector<std::vector<char>> H;
	std::vector<size_t> errPos;

	char intToChar(char x) { return x + '0'; }
	char charToInt(char x) { return x - '0'; }
};

#endif