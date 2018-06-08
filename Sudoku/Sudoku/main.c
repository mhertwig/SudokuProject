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
int iGridmuster[9][9];
int iGridplay[9][9];
int iLoesung;
int iAnzahlhilfe;
int iSchwierigkeitsgrad;


int main(void)
{
	// Setze Fenseter Koordinaten, Länge und Breite
	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	MoveWindow(hwnd, 350, 10, 670, 700, TRUE);

	// Setze Login auf 0 (Ausgeloggt)
	iLoginChange = 0;

	int iAnzahlhilfe = 0;
	int iSchwierigkeitsgrad = 1;

	// Zeige Menü an
	menu();

	return 0;
}