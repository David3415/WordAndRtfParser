#include <windows.h>

#include "MainProcClass.h"
#include "MainProcCallBackClass.h"


int MainProcClass::MainProc() {

	//Получаем хендл приложения, потребуется при создании класса окна и самого окна.
	HINSTANCE histance = GetModuleHandleW(NULL);
	//Создаем класс окна.
	WNDCLASSEX wclass = { 0 };          //Обнуляем структуру с самого начала, так как заполнять будем не все поля.
	wclass.cbSize = sizeof(WNDCLASSEX);      //По размеру структуры Windows определит, какая версия API была использована.
	wclass.style = CS_HREDRAW | CS_VREDRAW;    //Говорим окну перерисовываться при изменении размеров окна.
	wclass.lpfnWndProc = &MainProcCallBackClass::MainProcCallBack;        //Указываем функцию обработки сообщений.
	wclass.hInstance = histance;        //Указываем хендл приложения.
	wclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);    //GetStockObject возвращает хендл на белую кисточку, для фона окна
	wclass.lpszClassName = L"MYCLASS";      //Имя данного класса, должно быть уникальным, иначе, если класс с таким именем уже зарегестрирован, то в регистрации будет отказано.
	//Регистрируем класс окна.
	RegisterClassEx(&wclass);

	HWND window = CreateWindowExW(
		0,
		L"MYCLASS",                //Имя класса.
		L"Title",                //Заголовок окна.
		WS_SYSMENU,          //Тип окна, влияет на отображение системного меню, кнопок в верхнем правом углу и т.п.
		50, 50,                  //Координаты окна.
		700, 500,                //Ширина окна.
		0,                    //Ссылка на родительское окно.
		0,                    //Хендл меню.
		histance,                //Хендл приложения, получаем его функцией GetModuleHandleW.
		0
	);
	//Показываем окно, если этого не сделать окно не будет отображено.
	ShowWindow(window, SW_SHOW);
	//Обновляем окно.
	UpdateWindow(window);

	//Запускаем цикл обработки сообщений окна.
	MSG msg = { };
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);  //Преобразуем виртуальную клавишу в ASCII-код и посылаем сообщение WM_CHAR (тут не нужно.Необходимо, если надо работать с текстом, вводимым с клавиатуры)
		DispatchMessage(&msg);  //Передаем сообщения для обработки в "главную функцию обработки сообщений"
	}
	return static_cast<int>(msg.wParam);
}



//--------------------------функция замены букв -----------------------------------------------
