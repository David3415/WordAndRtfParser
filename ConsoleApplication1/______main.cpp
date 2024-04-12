#include <windows.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <codecvt>

#include <filesystem>
#include <stdio.h>
#include <windows.h>
#include <direct.h>
#include <shlobj.h>

#include <errno.h>

#include "atlbase.h"
#include "atlstr.h"
#include "Vocab.h"
#include "RTF_parse_Class.h"
#include "ParseDirClass.h"


namespace fs = std::filesystem;

static HWND hStat;



std::string wstring_to_utf8(const std::wstring& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	return myconv.to_bytes(str);
}


int main()
{		
		setlocale(LC_ALL, "rus");
	
		//Получаю путь рабочего стола из переменной среды
		std::wstring path_str{};
		TCHAR appData[MAX_PATH];
		try {
			if (SUCCEEDED(SHGetFolderPath(NULL,
				CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE,
				NULL,
				SHGFP_TYPE_CURRENT,
				appData)))
			{
				path_str = appData;
			}
		}
		catch (...) {
			exit(0);
		}
		
		//перевожу путь в utf8------------------------------------------
		std::string desktopPath{};
		Rtf_parse_Class rtf_parse_Class;
		rtf_parse_Class.OpenFileVoid("c:\\Users\\dgagi\\Desktop\\6.rtf");
		desktopPath = wstring_to_utf8(path_str);//ПЕРЕВОДИМ ПУТЬ РАБОЧЕГО ТОЛА wstring_to_utf8
		bool base_replace_bool = false;//
		std::map<wchar_t, wchar_t>vocab_map; //не используется сейчас
		//Vocab vocab;//
	
	
	
		////-----ПЕРЕХОДИМ К Vocab.h----СЛОВАРЬ ЗАМЕНЯЕМЫХ БУКВ
		//vocab.LoadVocab(vocab_map, base_replace_bool);// 
	
	//	// сравнения буквы для открытия формы меню пока не использую----------------
	//	char openMenuChar{};
	//	unsigned int clockStartTime = 1;
	//	printf("2 sec to press \"a\"\n");
	//	while (clockStartTime < 30000)
	//	{
	//		if (_kbhit()) {
	//			openMenuChar = _getch();
	//			if (openMenuChar == 97 || openMenuChar == 244) {
	//				Wnd();
	//				clockStartTime = 1;
	//			}
	//		}
	//		clockStartTime++;
	//	}
	//
	//	//-------------------------------------------------ЗДЕСЬ НАЧАЛО-------------------------------------------------
	//	ParseDirClass::ParseDirVoid(vocab_map, desktopPath);

	//string TextFromClipboardStr;
	//HANDLE hData = GetClipboardData(CF_TEXT);//извлекаем текст из буфера обмена
	// TextFromClipboardStr = TextFromClipboardClass::TextFromClipboardVoid(hData);
	//cout << TextFromClipboardStr;


	////-------------------------------------------------ТРАНСЛИТЕРАЦИЯ-------------------------------------------------
	////string TranslitedStr=Translit_class::LoadEngVocab(TextFromClipboardStr);
	//Translit_class::LoadEngVocab(TextFromClipboardStr);





}