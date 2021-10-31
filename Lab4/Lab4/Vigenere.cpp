#include "Vigenere.h"
#include <iostream>

// Задать список ключевых слов
void Vigenere::setKeywords(std::vector<std::string> _keywords)
{
	keywords.resize(_keywords.size());
	keywords = _keywords;
}

void Vigenere::setAlphabet()
{
	alphabet = { {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6},
				 {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10}, {'L', 11}, {'M', 12}, 
				 {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, 
				 {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, {'Y', 24},
				 {'Z', 25}, {' ', 26} };
}

// Очистить список ключевых слов
void Vigenere::clearKeywords()
{
	keywords.clear();
}

// Очистить список пробелов
void Vigenere::clearSpaces()
{
	spaces.clear();
}

// Сформировать ключ
std::string Vigenere::getKey(std::string text, std::string keyword)
{
	for (size_t i = 0; keyword.size() < text.size(); i++)
		keyword.push_back(keyword[i %= text.size()]);

	return keyword;
}

// Зашифровать текст по ключу
std::string Vigenere::encode(std::string text, std::string key)
{
	std::string encoded_text;

	// Сложение двух символов по модулю мощности алфавита и получение зашифованного
	for (std::string::size_type i = 0; i < text.size(); i++) 
	{
		char newChar = 'a';
		size_t newCharPos = (alphabet[text[i]] + alphabet[key[i]]) % alphabetPow;
		for (auto sym : alphabet)
			if (sym.second == newCharPos)
			{
				newChar = sym.first;
				break;
			}

		encoded_text.push_back(newChar);
	}

	return encoded_text;
}

// Расшифровать текст по ключу
std::string Vigenere::decode(std::string encoded_text, std::string key)
{
	std::string decoded_text;

	for (std::string::size_type i = 0; i < encoded_text.size(); i++) 
	{
		char originChar = 'a';
		size_t originCharPos = ((alphabet[encoded_text[i]] - alphabet[key[i]]) + alphabetPow) % alphabetPow;
		for (auto sym : alphabet)
			if (sym.second == originCharPos)
			{
				originChar = sym.first;
				break;
			}

		decoded_text.push_back(originChar);
	}

	return decoded_text;
}

// Запомнить позиции разделяющих символов
void Vigenere::rememberSpacesPos(std::string text) 
{
	for (size_t i = 0; i < text.size(); i++)
		if (text[i] == ' ')
			spaces.push_back(i);
}

// Восстановить разделяющие символы в тексте
std::string Vigenere::getSpaces(std::string text) 
{
	for (auto spacePos : spaces)
		text[spacePos] = ' ';

	return text;
}

// Зашифровать текст по нескольким ключевым словам
std::string Vigenere::encrypt(std::string text) 
{
	std::string encoded_text = text;
	clearSpaces();
	rememberSpacesPos(text);

	// Последовательное (один или более раз) шифрование текста по
	// указанным ключевым словам
	for (auto it = keywords.begin(); it != keywords.end(); it++)
		encoded_text = encode(encoded_text, getKey(encoded_text, *it));

	return getSpaces(encoded_text);
}

// Расшифровать текст по нескольким ключевым словам
std::string Vigenere::decrypt(std::string text) 
{
	std::string decoded_text = text;

	// Последовательное (один или более раз) расшрование текста по
	// указанным ключевым словам (в обратном порядке)
	for (auto it = keywords.rbegin(); it != keywords.rend(); it++)
		decoded_text = decode(decoded_text, getKey(decoded_text, *it));

	return getSpaces(decoded_text);
}