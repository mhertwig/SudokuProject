#include "include.h"

void sudoku_header(void)
{
	extern int iLoginChange;
	char sNameLeer[26] = "                         ";
	

	

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

	if (iLoginChange == 0)
	{
		printf("\t  %c\t\tBenutzer: %s%c\n", cHoch, sNameLeer, cHoch);
	}
	else
	{
		printf("\t  %c\t\tBenutzer: %s%c\n", cHoch, sUser, cHoch);
	}
	//



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

	//Ohne Login
	if (iLoginChange == 0) {
		printf("\t\t(1) Schnellstart\n\n");
		printf("\t\t(2) Login\n\n");
		printf("\t\t(3) Benutzer anlegen\n\n");
		printf("\t\t(4) Hall of Fame\n\n");
		printf("\t\t(5) Regeln anzeigen\n\n");
		printf("\t\t(X) Beenden\n\n\n");
	}
	else {
		printf("\t\t(1) Neues Spiel starten\n\n");
		printf("\t\t(2) Log Out\n\n");		
		printf("\t\t(3) Hall of Fame\n\n");
		printf("\t\t(4) Regeln anzeigen\n\n");
		printf("\t\t(X) Beenden\n\n\n");
	}
}

void hallOfFameAnzeige(void)
{
	system("cls");
	printf("\n\n");
	sudoku_header();

	printf("\t\t(1) Leicht\n\n");
	printf("\t\t(2) Mittel\n\n");
	printf("\t\t(3) Schwer\n\n");
	printf("\t\t(X) Beenden\n\n\n");
}

void Layout(void)
{

	char var[1000];
	char cObenRechtEcke = 201;		// ╔
	char cUntenRechtEcke = 200;		// ╚
	char cObenLinksEcke = 187;		// ╗
	char cUntenLinksEcke = 188;		// ╝
	char cObenMitte = 203;			// ╦
	char cUntenMitte = 202;			// ╩
	char cAlleMitte = 206;			// ╬
	char cRechtsMitte = 204;		// ╠
	char cLinksMitte = 185;		// ╣
	char cGerade = 205;				// ═
	char cHoch = 186;				// ║
	char cHochinnen = 179;			// |
	char cTrenner = 196;			// -
	int  iGrid[9][9];

	///*

	printf("\t   _____           _       _			\n"
		"\t  / ____|         | |     | |         \n"
		"\t | (___  _   _  __| | ___ | | ___   _ \n"
		"\t  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |\n"
		"\t  ____) | |_| | (_| | (_) |   <| |_| |\n"
		"\t |_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_|\n");




	printf("\n\n");
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cObenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenLinksEcke);
	printf("\t  %c   S U D O K U   %c\n", cHoch, cHoch);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cUntenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenLinksEcke);

	printf("\n\n");

	printf("\t   1 2 3 4 5 6 7 8 9\n");

	// Zeile 1
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cObenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cObenLinksEcke);
	// Zeile 2
	printf("\t1 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[1][1], cHochinnen, iGrid[1][2], cHochinnen, iGrid[1][3], cHoch, iGrid[1][4], cHochinnen, iGrid[1][5], cHochinnen, iGrid[1][6], cHoch, iGrid[1][7], cHochinnen, iGrid[1][8], cHochinnen, iGrid[1][9], cHoch);
	// Zeile 3
	printf("\t2 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[2][1], cHochinnen, iGrid[2][2], cHochinnen, iGrid[2][3], cHoch, iGrid[2][4], cHochinnen, iGrid[2][5], cHochinnen, iGrid[2][6], cHoch, iGrid[2][7], cHochinnen, iGrid[2][8], cHochinnen, iGrid[2][9], cHoch);
	// Zeile 4
	printf("\t3 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[3][1], cHochinnen, iGrid[3][2], cHochinnen, iGrid[3][3], cHoch, iGrid[3][4], cHochinnen, iGrid[3][5], cHochinnen, iGrid[3][6], cHoch, iGrid[3][7], cHochinnen, iGrid[3][8], cHochinnen, iGrid[3][9], cHoch);
	// Zeile 5
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
	// Zeile 6
	printf("\t4 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[4][1], cHochinnen, iGrid[4][2], cHochinnen, iGrid[4][3], cHoch, iGrid[4][4], cHochinnen, iGrid[4][5], cHochinnen, iGrid[4][6], cHoch, iGrid[4][7], cHochinnen, iGrid[4][8], cHochinnen, iGrid[4][9], cHoch);
	// Zeile 7
	printf("\t5 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[5][1], cHochinnen, iGrid[5][2], cHochinnen, iGrid[5][3], cHoch, iGrid[5][4], cHochinnen, iGrid[5][5], cHochinnen, iGrid[5][6], cHoch, iGrid[5][7], cHochinnen, iGrid[5][8], cHochinnen, iGrid[5][9], cHoch);
	// Zeile 8
	printf("\t6 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[6][1], cHochinnen, iGrid[6][2], cHochinnen, iGrid[6][3], cHoch, iGrid[6][4], cHochinnen, iGrid[6][5], cHochinnen, iGrid[6][6], cHoch, iGrid[6][7], cHochinnen, iGrid[6][8], cHochinnen, iGrid[6][9], cHoch);
	// Zeile 10
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
	// Zeile 11
	printf("\t7 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[7][1], cHochinnen, iGrid[7][2], cHochinnen, iGrid[7][3], cHoch, iGrid[7][4], cHochinnen, iGrid[7][5], cHochinnen, iGrid[7][6], cHoch, iGrid[7][7], cHochinnen, iGrid[7][8], cHochinnen, iGrid[7][9], cHoch);
	// Zeile 12
	printf("\t8 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[8][1], cHochinnen, iGrid[8][2], cHochinnen, iGrid[8][3], cHoch, iGrid[8][4], cHochinnen, iGrid[8][5], cHochinnen, iGrid[8][6], cHoch, iGrid[8][7], cHochinnen, iGrid[8][8], cHochinnen, iGrid[8][9], cHoch);
	// Zeile 13
	printf("\t9 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, iGrid[9][1], cHochinnen, iGrid[9][2], cHochinnen, iGrid[9][3], cHoch, iGrid[9][4], cHochinnen, iGrid[9][5], cHochinnen, iGrid[9][6], cHoch, iGrid[9][7], cHochinnen, iGrid[9][8], cHochinnen, iGrid[9][9], cHoch);
	// Zeile 14
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", cUntenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenLinksEcke);
}

