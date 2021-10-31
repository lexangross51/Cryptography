#include "Hamming.h"
#include <fstream>
#include <iostream>

// Читаем алфавит и его кодовые слова
void Hamming::readAlphabbet()
{
	std::ifstream alph("alphHam.txt");
	std::ifstream codes("codesHam.txt");

	if (alph.is_open() && codes.is_open())
	{
		int sym;
		std::string code;
		while (alph >> sym && codes >> code)
			code_table.push_back({ sym, code, std::string() });
		alph.close();
		codes.close();
	}
	else
		std::cerr << "Files can't be opened!" << std::endl;
}

// Читаем проверочную матрицу
void Hamming::readMatrix()
{
	std::ifstream m("matrixHam.txt");
	if (m.is_open())
	{
		m >> n >> r;
		H.resize(r);
		for (size_t i = 0; i < H.size(); i++)
			H[i].resize(n, 0);

		for (size_t i = 0; i < H.size(); i++)
			for (size_t j = 0; j < H[i].size(); j++)
				m >> H[i][j];
	}
	else
		std::cerr << "File can't be opened!" << std::endl;
}

// Читаем текст, который нужно закодировать
void Hamming::readText()
{
	text.clear();
	std::ifstream in("toencodeHam.txt");
	if (in.is_open())
	{
		std::string line;
		while (getline(in, line))
			text += line;
		in.close();
	}
	else
		std::cerr << "File can't be opened!" << std::endl;
}

// Построить кодовые цепочки
void Hamming::makeCodeHash()
{
	if (!H.empty() && !code_table.empty())
	{
		std::vector<std::pair<size_t, size_t>> bits;

		// Определяем позиции, где будут контрольные биты
		for (size_t j = 0; j < n; j++)
		{
			size_t sum = 0;
			size_t curr = 0;
			for (size_t i = 0; i < r; i++)
				if (H[i][j] == '1')
				{
					sum++;
					curr = i;
				}
			if (sum == 1)
				bits.push_back(std::make_pair(curr, j));
		}

		for (auto& sym : code_table)
		{
			// Заполняем строку с кодом символа 
			sym.code_hash = std::string(n, '*');

			// Освобождаем те позиции, где будут контрольные биты
			for (size_t i = 0; i < bits.size(); i++)
				sym.code_hash[bits[i].second] = ' ';

			// Вставляем информационное слово на позиции, 
			// которые не будут заняты контрольными битами
			for (size_t code_ind = 0, i = 0; i < n; i++)
				if (sym.code_hash[i] != ' ')
					sym.code_hash[i] = sym.code[code_ind++];

			for (size_t i = 0; i < bits.size(); i++)
			{
				// Определяем единичные биты, которые контролируются 
				// контрольным битом
				std::string hash;
				for (size_t j = 0; j < n; j++)
					if (H[bits[i].first][j] == '1' && j != bits[i].second)
						hash += sym.code_hash[j];

				// Складываем все найденные контролируемые биты 
				// по модулю два (XOR)
				char bit = charToInt(hash[0]);
				for (size_t j = 1; j < hash.size(); j++)
					bit = (bit ^ charToInt(hash[j]));

				// Записываем полученное значение в кодовое слово
				sym.code_hash[bits[i].second] = intToChar(bit);
			}
		}
	}
}

// Получить кодовые цепочки
std::string Hamming::getCodeHash()
{
	if (!code_table.empty())
	{
		std::string codes;
		for (auto s : code_table)
		{
			codes += std::to_string(s.sign);
			codes += "\t";
			codes += s.code_hash + "\n";
		}
		return codes;
	}
}

// Декодировать текст
std::string Hamming::decode()
{
	std::ifstream in("todecodeHam.txt");
	if (in.is_open())
	{
		std::string txt, line;
		while (getline(in, line))
			txt += line;
		in.close();

		std::string decoded_text;
		std::vector<std::size_t>().swap(errPos);

		// Проходим по блокам закодированного текста
		// которые будем умножать на проверочную матрицу
		for (size_t chr = 0; chr < txt.size(); chr += n)
		{
			std::string syndrom;
			for (size_t i = 0; i < r; i++)
			{
				std::string code;
				 
				// Умножаем последовательность на проверочную матрицу
				for (size_t j = 0; j < n; j++)
					code += intToChar(charToInt(txt[chr + j]) * charToInt(H[i][j]));

				char bit = charToInt(code[0]);
				for (size_t j = 1; j < code.size(); j++)
					bit = (bit ^ charToInt(code[j]));

				// Добавляем полученный бит к синдрому
				syndrom += intToChar(bit);
			}

			std::string code;
			for (size_t i = 0; i < n; i++)
				code += txt[chr + i];

			// Синдром будет, если хотя бы один бит отличен от нуля
			size_t syndrom_size = std::strtoull(syndrom.c_str(), nullptr, 2);

			// Если ошибки есть, то с помощью синдрома определяем их позиции
			if (syndrom_size)
			{
				code[syndrom_size - 1] = code[syndrom_size - 1] == '1' ? '0' : '1';
				errPos.push_back(chr + syndrom_size);
			}

			// Проходим по всем символам закодированного текста и если
			// найдем совпадение с кодовой цепочкой, то декодируем этот символ
			bool find = true;
			for (auto i = code_table.begin(); i != code_table.end() && find; i++)
				if (i->code_hash == code)
				{
					find = false;
					decoded_text += std::to_string(i->sign);
				}
		}
		in.close();

		std::ofstream out("decodedHam.txt");
		if (out.is_open())
		{
			out << decoded_text;
			out.close();
		}
		else
			std::cerr << "File can't be opened!" << std::endl;

		return decoded_text;
	}
	else
		std::cerr << "File can't be opened!" << std::endl;
}

// Закодировать текст
std::string Hamming::encode()
{
	std::string encoded_text;

	for (auto c : text)
	{
		bool find = true;
		for (auto s = code_table.begin(); s != code_table.end() && find; s++)
			if (intToChar(s->sign) == c)
			{
				encoded_text += s->code_hash;
				find = false;
			}
	}

	std::ofstream out("todecodeHam.txt");
	if (out.is_open())
	{
		out << encoded_text;
		out.close();
	}
	else
		std::cerr << "File can't be opened!" << std::endl;

	return encoded_text;
}

// Получить позиции ошибок
std::vector<size_t> Hamming::getErrPos()
{
	return errPos;
}

// Получить число ошибок
size_t Hamming::getErrCount()
{
	return errPos.size();
}

// Очистить таблицу
void Hamming::clearTable()
{
	code_table.clear();
}