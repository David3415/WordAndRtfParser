#include<iostream>
#include <string>
#include <map>
#include <fstream>
#include "Vocab.h"


std::map<wchar_t, wchar_t>Vocab::LoadVocab(std::map<wchar_t, wchar_t>& vocab_map, bool& b) {
	b = true;
	std::ifstream fin;
	std::string vocab_path = "c:\\Users\\dgagi\\Desktop\\temp\\vocab.txt";
	fin.open(vocab_path, std::ios::out);
	// СЛОВАРЯ НЕТ ПОЭТОМУ ЗАМЕНА ПО УМОЛЧАНИЮ
	if (!fin.is_open()) {
		try {
			vocab_map.insert(std::make_pair(L'ё', L'æ'));
			vocab_map.insert(std::make_pair(L'Ё', L'Ӕ'));
			vocab_map.insert(std::make_pair(L'"', L'«'));
			vocab_map.insert(std::make_pair(L'"', L'»'));
			vocab_map.insert(std::make_pair(L'/', L' '));
			vocab_map.insert(std::make_pair(L'-', L' '));
		}
		catch (...) {
			exit(0);
		}
	}
	else {
		std::string temp{};
		while (!fin.eof()) {
			fin >> temp;
			vocab_map.emplace(std::make_pair(temp[0], temp[1]));
			for (auto& it : vocab_map) {
				std::cout << (char)it.first << '\t' << (char)it.second << '\n';
			}
		}
	}
	fin.close();
	return vocab_map;
};




