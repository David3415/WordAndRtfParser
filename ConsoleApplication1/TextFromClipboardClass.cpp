#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING
// _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <iostream>
#include <strstream>
#include <string>
#include "TextFromClipboardClass.h"
#include <fstream>
#include"Translit_class.h"
using namespace std;
extern string text_from_Buffer;
string text_from_Buffer_TEMP;
string TextFromClipboardClass::TextFromClipboardVoid(HANDLE hData) {
	setlocale(LC_ALL, "rus");
	string fromClipboard;//в эту переменную сохраним текст из буфера обмена




	if (OpenClipboard(NULL))//открываем буфер обмена
	{
		HANDLE hData = GetClipboardData(CF_TEXT);//извлекаем текст из буфера обмена
		char* chBuffer = (char*)GlobalLock(hData);//блокируем память

		int str_counter = 49;
		if (chBuffer != NULL) {
			istrstream cboard(chBuffer);
			while (!cboard.eof()) {
				getline(cboard, fromClipboard);
				if (fromClipboard.empty()) { continue; }
				text_from_Buffer += fromClipboard;

				text_from_Buffer_TEMP += str_counter;
				text_from_Buffer_TEMP += " IR ";
				text_from_Buffer_TEMP += fromClipboard;
				str_counter++;
			}
		}
		for (int i = 0; i < text_from_Buffer.size(); i++) {
			if (text_from_Buffer[i] == '\r')
				text_from_Buffer[i] = '\n';
		}

		for (int i = 0; i < text_from_Buffer.size(); i++) {
			if (text_from_Buffer_TEMP[i] == '\r')
				text_from_Buffer_TEMP[i] = '\n';
		}
		ofstream fout{};
		fout.open("c:\\Users\\dgagi\\Desktop\\6.rtf", ios::app);
		fout << text_from_Buffer;
		fout << '\n';
		fout << text_from_Buffer_TEMP;

		GlobalUnlock(hData);//разблокируем память
		CloseClipboard();//закрываем буфер обмена
	};
	return text_from_Buffer;
}
