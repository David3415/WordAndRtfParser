#include <map>
#include <string>
#include "Vocab.h"
#include <filesystem>
#include <codecvt>

#include "TextReplaceClass.h"
#include "ParseDirClass.h"

std::map<wchar_t, wchar_t> ParseDirClass::ParseDirVoid(std::map<wchar_t, wchar_t>& vocab_map, std::string& desktopPath) {
	std::string path = desktopPath;	// путь рабочего стола
	Vocab vocab;	//экзеспл€р класса словар€
	namespace fs = std::filesystem;
	fs::current_path(path); //устанавливаю путь
	for (const auto& file : fs::directory_iterator(path)) {

		std::wstring  _file = file.path();
		int len = 0;
		fs::path p{ fs::u8path(desktopPath) };
		std::string path_string{ p.u8string() };
		std::wstring temp = file.path();//-------------------путь к файлу
		len = static_cast<int>(temp.size());
		//wcout << temp.substr(len - 4, len) << '\t';
		std::string str = "docx";
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		std::wstring wstr = converter.from_bytes(str);

		if (temp.substr(len - 3, len) == wstr) {
			if (count(temp.begin(), temp.end(), '~') == 0) {
				TextReplaceClass::TextReplaceVoid(vocab_map, temp);//--------------------------‘”Ќ ÷»я «јћ≈Ќџ 
			}
		};
	}
	return vocab_map;
};

