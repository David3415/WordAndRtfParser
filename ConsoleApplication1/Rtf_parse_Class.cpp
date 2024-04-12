#include<iostream>
#include<fstream>
#include <string> 
#include <codecvt>
#include <vector>
#include <map>
#include <istream>

#include"Vocab_Rtf.cpp"
#include "RTF_parse_Class.h"

std::string Rtf_parse_Class::OpenFileVoid(std::string path)
{
	setlocale(LC_ALL, "rus");
	std::vector<std::string>tempStrVec;
	std::string keyWord = "insrsid";
	bool firstSpace = false;
	std::string temp{};
	int j = 0;		// итерация русских букв
	std::string tempSubStr{}; //временная строка для субстроки темп

	std::ofstream fout;
	std::fstream fin;
	fin.open(path);
	if (!fin.is_open()) { std::cout << "!!!!"; };
	//-----------------------------------------------------// замена только русских//---------------------------------------------//

	while (getline(fin, temp)) {
		std::cout << temp;
		for (auto& a : openVocabRtfVec) {
			std::cout << a.first << '\t' << "a.first" << '\n';
			std::string Vocab_Rtf_str = a.first;
			size_t indexRu = 0; // старт поиска

			while (indexRu < temp.size()) {
				indexRu = temp.find(Vocab_Rtf_str, j);	//новый старт поиска
				if (indexRu == std::string::npos) {

				}
				else {
					tempSubStr.clear();
					tempSubStr = temp.substr(indexRu + 3, temp.size());//index- первая после \ символ. indexRu + 3 - конец RUS
					//cout << '\n' << temp << "TEMPFULL" << '\n';
					for (int k = static_cast<int>(indexRu) + 1; k < temp.size(); k++) {
						temp[k] = ' ';
					}
					//cout << '\n' << tempSubStr << '\t' << "tempSubStr" << '\n';
					std::string x = a.second;// "\u230"s;
					temp.replace(indexRu, 4, x);
					//cout << '\n' << temp << '\t' << "temp" << '\n';
					j = static_cast<int>(indexRu) + 6;//j - следующий после ключ слова символ. Новый старт для temp.find()
					temp.replace(j, tempSubStr.size(), tempSubStr);
				}
			}
		}

		//----------------------------------------���� ������ ������

		for (unsigned i{}; i < temp.size(); i++) {

			size_t position = temp.find(keyWord, i);
			i = static_cast<int>(position) + 1;
			if (position == std::string::npos) {
				break;
			}
			firstSpace = false;

			//position  ��������� ����� keyWord
			for (i = static_cast<int>(position); temp[i] != '}'; i++) {
				if (i == temp.size()) { break; }
				if (firstSpace == false && temp[i] == ' ') {//������ ������
					firstSpace = true;
				}

				if (firstSpace == true) {
					//if (isRus == true) {
					//	i--;// �
					//	temp[i] = '\\';
					//	i++;
					//	temp[i] = '6';
					//	isRus = false;
					//}
				}
				switch (temp[i]) {
				case ' ': break;
				case '/':  temp[i] = ' '; break;
				case '-':  temp[i] = ' '; break;
				case '_':  temp[i] = ' '; break;
				case '\'':  temp[i] = ' '; break;

				}
			}
		}
		tempStrVec.push_back(temp);
		std::cout << '\n' << '\n';
	}
	/*fin.close();
	fout.open(path, ios::out | ios::trunc);
	for (auto& v : tempStrVec) {
		fout << v;
	}
	fout.close();*/
	return path;
};








