#include <windows.h>

#include "MainProcCallBackClass.h"

int hWnd_Texts_arr_num = 2;
HWND hWnd_Texts[10];//������ �


LRESULT WINAPI MainProcCallBackClass::MainProcCallBack(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CREATE:
	{
		bool isEven = false;
		int count = 0;
		int count1 = 0;
		int shift = 20;
		/*struct StateInfo
		{
			map<wchar_t, wchar_t> vocab_map;
		};*/
		//StateInfo* pState = new (std::nothrow) StateInfo;

		for (int i = 0; i < hWnd_Texts_arr_num; i++) {
			if (count < 2) {

				hWnd_Texts[i] = CreateWindow(L"STATIC", L" ", // ��� ������ HWND ������� � ������ � ������
					WS_CHILD | WS_VISIBLE | SS_LEFT,
					shift, 10, 100, 15,
					hWnd, reinterpret_cast<HMENU>(999), nullptr, nullptr);
				CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);

				//pState = reinterpret_cast<StateInfo*>(pCreate->lpCreateParams);


				count++;
				if (isEven == true) {
					shift = 0;
				}
				else {
					shift += 230;
					isEven = true;

				}
				continue;
			}
			if (count >= 2) {

				hWnd_Texts[i] = CreateWindow(L"STATIC", L" ",// ��� ������ HWND ������� � ������ � ������
					WS_CHILD | WS_VISIBLE | SS_LEFT,
					10, 40, 100, 15,
					hWnd, reinterpret_cast<HMENU>(999), nullptr, nullptr);
				count++;
				if (isEven == false) {
					count = 0;
					shift = 0;
				}
				else {
					isEven = false;
					shift += 50;
				}
			}
		}

		HWND hButton = CreateWindow(
			L"Button",
			L"OK",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT,
			570, 420, 80, 30, hWnd, reinterpret_cast<HMENU>(1000), nullptr, nullptr
		);

	}
	return 0;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			//case 999:
			//	//����� ��� ������ � map vocab_map
			//	//PutDataToVocab();
			//	SetWindowText(hWnd_Texts[0], L"1weeree");
			//	break;
		case 1000:
			//����� ��� ������ � map vocab_map
	//PutDataToVocab();
			DestroyWindow(hWnd);
			break;
		}
	}
	return 0;

	case WM_DESTROY:// ���� ����� �� �������, �� ��� ���� ������ ������� ������� ���� ����� ���������������
	{
		PostQuitMessage(0);// ���������� ���������� ��������� WM_QUIT. ��������� ��� ������, ������� ��������� � wParam ��������� WM_QUIT
		break;
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);//������������ ��� ��������� ��������� ������������ "�� ���������"
}

//map<wchar_t, wchar_t>PutDataToVocab() {
//
//	//����� ��� ������ � map vocab_map
//	return 0;
//}