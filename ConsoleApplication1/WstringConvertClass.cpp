#include <conio.h>
#include <codecvt>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "WstringConvertClass.h"


char* WstringConvertClass::WstringConvertVoid(std::wstring _temp)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	const wchar_t* input = _temp.c_str();
	size_t _size = (wcslen(input) + 1) * sizeof(wchar_t);
	char* buffer = new char[_size];
	size_t convertedSize;
	size_t _count{};
	wcstombs_s(&convertedSize, buffer, _size, input, _size);
	return buffer;
};


