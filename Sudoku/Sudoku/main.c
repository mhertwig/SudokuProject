/*
Programmname:
Erstellungs-Datum:
Autor:
Beschreibung:
Compiler: 			VS12
*/

// Include
#include "include.h"


int main(void)
{

	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	MoveWindow(hwnd, 350, 10, 800, 700, TRUE);

	menu();


	//system("Pause");
	return 0;
}



