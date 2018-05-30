#include "include.h"

void sudoku_header(void)
{
	char sName[26] = "1234567890123456789012345";

	if(sName != NULL)
	for (int i = 0; i<25; i++) {
	if (sName[i] == NULL)
	{
	sName[i] = ' ';
	}
	}

	char cObenRechtEcke = 201;		// ╔
	char cUntenRechtEcke = 200;		// ╚
	char cObenLinksEcke = 187;		// ╗
	char cUntenLinksEcke = 188;		// ╝
	char cGerade = 205;				// ═
	char cHoch = 186;				// ║

	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%\n", cObenRechtEcke,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cObenLinksEcke);

	printf("\t  %c\t  _____           _       _\t\t   %c\n"
		"\t  %c\t / ____|         | |     | |\t\t   %c\n"
		"\t  %c\t| (___  _   _  __| | ___ | | ___   _\t   %c\n"
		"\t  %c\t \\___ \\| | | |/ _` |/ _ \\| |/ / | | |\t   %c\n"
		"\t  %c\t ____) | |_| | (_| | (_) |   <| |_| |\t   %c\n"
		"\t  %c\t|_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_|\t   %c\n"
		"\t  %c\t\t\t\t\t\t   %c\n",
		cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch,
		cHoch, cHoch, cHoch, cHoch, cHoch);


	printf("\t  %c\t\tBenutzer: %s%c\n", cHoch, sName, cHoch);



	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%\n\n\n", cUntenRechtEcke,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cUntenLinksEcke);

}

void menuAnzeige(void)
{
	system("cls");
	printf("\n\n");
	sudoku_header();

	printf("\t\t(1) Schnellstart\n\n");
	printf("\t\t(2) Neues Spiel starten\n\n");
	printf("\t\t(3) Login\n\n");
	printf("\t\t(4) Benutzer anlegen\n\n");
	printf("\t\t(5) Bestenliste\n\n");
	printf("\t\t(6) Regeln anzeigen\n\n");
	printf("\t\t(X) Beenden\n\n\n");
}

