/*
Programmname:
Erstellungs-Datum:
Autor:
Beschreibung:
Compiler: 			VS12
*/

// Include
#include "include.h"

// Globale Variablen
char sUser[26];
int iLoginChange;
int iGrid[9][9];
int iGridCopy[9][9];

int main(void)
{

	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	MoveWindow(hwnd, 350, 10, 700, 700, TRUE);

	
	iLoginChange = 0;

	menu();

	return 0;
}