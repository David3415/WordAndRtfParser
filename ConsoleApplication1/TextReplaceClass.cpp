#include <map>

#include "TextReplaceClass.h"
#include "WstringConvertClass.h"



void TextReplaceClass::TextReplaceVoid(std::map<wchar_t, wchar_t>& vocab_map, std::wstring& temp) {
	
	WstringConvertClass wstringConvertClass;// СОЗДАЁМ ЭКЗЕМПЛЯР КЛАССА

	char* buffer = wstringConvertClass.WstringConvertVoid(temp);//здесь переходим к Фун "Wstring_convert.h"

	wchar_t base_replace_char = L'æ';
	//duckx::Document doc(buffer);// ocx"s);

	//delete[] buffer;

	//for (auto& p = doc.paragraphs(); p.has_next(); p.next()) {
	//	for (auto& r = p.runs(); r.has_next(); r.next()) {
	//		std::wstring converted_str = wstring_convert.converter.from_bytes(r.get_text());
	//		bool q_mark = false;
	//		for (auto& v_map : vocab_map) {
	//			wchar_t yo = v_map.first;
	//			wchar_t replace_with = v_map.second;

	//			for (auto i = converted_str.begin(); i != converted_str.end(); i++) {
	//				if (*i == yo && *i != L'"' && isupper(*i)) {
	//					unsigned char temp_char = tolower(*i);
	//					temp_char = replace_with;
	//					*i = toupper(temp_char);
	//				}
	//				else if (*i == yo && *i != L'"') {
	//					*i = replace_with;
	//				}
	//				else if (*i == yo && *i == L'"') {

	//					if (q_mark == false) {
	//						replace_with = L'«';
	//						q_mark = true;
	//					}
	//					else {
	//						replace_with = L'»';
	//						q_mark = false;
	//					}
	//					*i = replace_with;
	//				}
	//			}
	//		}
	//		r.set_text(wstring_convert.converter.to_bytes(converted_str));
	//		std::cout << wstring_convert.converter.to_bytes(converted_str) << std::endl;
	//	}
	//}
	//doc.save();
};