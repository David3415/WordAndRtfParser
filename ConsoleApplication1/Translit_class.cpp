#pragma once
#pragma warning( disable : 4996 )
#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING

#include<iostream>
#include<fstream>
#include<istream>
#include <string> 
#include <conio.h>
#include<iostream>
#include<vector>

#include"Translit_class.h"
#include"TextFromClipboardClass.h"

string text_from_Buffer{};
string Translit_class::LoadEngVocab(string path) {

	setlocale(LC_ALL, "rus");
	fstream fout;
	ifstream fout_last;
	int buff_count{};
	string rtf_path = "c:\\Users\\dgagi\\Desktop\\6.rtf";
	string temp_punto_str{};
	std::ifstream fin_punto;
	std::vector<char> str_to_translit{};
	bool b_circle_end = false;
	for (int k = 0; k < text_from_Buffer.size(); k++) {
		while (std::getline(fin_punto, temp_punto_str)) {//b_circle_end == false) {
			cout << temp_punto_str;
			for (int j = 0; j < temp_punto_str.size(); j++) {
				if (temp_punto_str[0] == text_from_Buffer[buff_count]) {
					buff_count += 2;
					str_to_translit.push_back(temp_punto_str[buff_count]);
					b_circle_end = true;
					break;
				}
				else { str_to_translit.push_back(text_from_Buffer[buff_count]); }

				buff_count++;
				if (buff_count >= 13) { buff_count = 0; break; }
				if (b_circle_end == true) { break; }
			}
		}
	}

	string temp{};


	string fTemp{};
	fout_last.open(rtf_path);
	while (getline(fout_last, fTemp)) {
		for (int u = 0; u < fTemp.size(); u++) {
			cout << "***" << fTemp[u] << "***";
		}
	};

	/*int d = 0;
	while (getline(fout_last_func, fTemp)) {
		size_t insrsid_index = fTemp.find("insrsid", d);
		size_t insrsid_first_space_index = fTemp.find(" ", insrsid_index);
		cout << '\n' << insrsid_first_space_index << '\n'; cout << '\n' << insrsid_index << '\n';
	}*/
	fout_last.close();



	return path;
};
char Translit_class::parsePunto(char temp_str) {
	return temp_str;
};
