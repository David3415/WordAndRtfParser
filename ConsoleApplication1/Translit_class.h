#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_STRSTREAM_DEPRECATION_WARNING
#pragma warning( disable : 4996 )
#include"TextFromClipboardClass.h"
#include<iostream>
#include<fstream>
#include <string> 
#include <conio.h>
#include<iostream>
#include<vector>

using namespace std;

 
static class Translit_class {
public:
	ifstream fout_last;
	static string LoadEngVocab(string path);
	static char parsePunto(char temp_str);
	fstream fin;
	string path;
};