#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING
#include <iostream>
#include <strstream>
#include <string>
#include <windows.h>
#include"Translit_class.h"
using namespace std;



static class TextFromClipboardClass
{
public:
	
	static string TextFromClipboardVoid(HANDLE hData);
	//string fromClipboard;//в эту переменную сохраним текст из буфера обмена
	string fulltext;
	
	HANDLE hData;
	char* chBuffer;
};