#include<stdio.h>
#include<conio.h>
#include"WndOpenClass.h"



void WndOpenClass::WndOpenVoid() {
	char openMenuChar{};
	unsigned int clockStartTime = 1;


	printf("2 sec to press \"a\"\n");
	while (clockStartTime < 30000)
	{
		if (_kbhit()) {
			openMenuChar = _getch();
			if (openMenuChar == 97 || openMenuChar == 244) {
				//Wnd();
				clockStartTime = 1;
			}
		}
		clockStartTime++;
	}
}