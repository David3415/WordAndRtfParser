#pragma once
#pragma warning( disable : 4996 )
#include <string>
#include <iostream>
#include <conio.h>
#include <map>
#include <Windows.h>
#include <map>


class Vocab
{
private:
public:
	std::map<wchar_t, wchar_t> vocab_map;
	std::map<wchar_t, wchar_t> LoadVocab(std::map<wchar_t, wchar_t>& vocab_map, bool& b);
};


