#include "include.h"

void sudoku_header()
{
	//sName = {C ,h ,r ,i ,s};

	/*if(sName != NULL)
	for (int i = 0; i<25; i++) {
	if (sName[i] == NULL)
	{
	sName[i] = ' ';
	}
	}*/

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