#define OnButtonClicked 1100
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <ShlObj_core.h>
#include <iostream>
#include <string>
#include "BrowseForFolderClass.h"

TCHAR szWindowClass[] = _T("DesktopApp");
TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");
HWND hwnd{};
std::wstring folder{};

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	BrowseForFolderClass browseForFolderClass;


	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = L"Hello, Windows desktop!";
	HWND hwndOwner{};

	int nFolder{};
	switch (message)
	{
	case WM_CREATE:
		hwnd = CreateWindowEx(0, L"STATIC", L"000", // это массив HWND который я указал в начаое
			WS_CHILD | BS_TEXT | WS_VISIBLE,
			0, 0, 250, 90,
			hWnd, (HMENU)OnButtonClicked, nullptr, nullptr);
		break;
	case WM_LBUTTONDOWN:
		switch (wParam) {
		case MK_LBUTTON:
		{
			std::wstring ret = browseForFolderClass.BrowseForFolderVoid(hWnd, L"dfyg", folder);
			LPCWSTR l = &ret[0];
			SetWindowText(hwnd, l);
		}
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{

	HWND hWnd{};
	HINSTANCE hInst;

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	hInst = hInstance;

	hWnd = CreateWindowEx(
		0,
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 200,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}


