#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <vector>
#include <map>

 class Vigenere
{
public:
	Vigenere(size_t alphPow) :
		alphabetPow(alphPow) 
	{
		setAlphabet();
	};

	void setAlphabet();

	void setKeywords(std::vector<std::string> keywords);

	void clearKeywords();

	void clearSpaces();

	std::string encrypt(std::string text);

	std::string decrypt(std::string text);

private:
	std::map<char, size_t> alphabet;
	size_t alphabetPow;

	std::vector<std::string> keywords;
	std::vector<size_t> spaces;

	std::string getKey(std::string text, std::string keyword);
	std::string encode(std::string text, std::string keyword);
	std::string decode(std::string text, std::string keyword);

	void rememberSpacesPos(std::string text);
	std::string getSpaces(std::string text);
};

#endif