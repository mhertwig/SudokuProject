#include "include.h"


void sudoku_header(void)
{
	// Definition
	char sNameLeer[26] = "                         ";
	char cObenRechtEcke = 201;		// ╔
	char cUntenRechtEcke = 200;		// ╚
	char cObenLinksEcke = 187;		// ╗
	char cUntenLinksEcke = 188;		// ╝
	char cGerade = 205;				// ═
	char cHoch = 186;				// ║
	

	// Baue Rahmen
	printf("\n\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%\n", cObenRechtEcke,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cGerade, cGerade, cGerade, cGerade, cGerade, cGerade,
		cObenLinksEcke);

	// Schreibe Sudoku in Ascii Zeichen
	printf("\t  %c\t  _____           _       _\t\t   %c\n"
		"\t  %c\t / ____|         | |     | |\t\t   %c\n"
		"\t  %c\t| (___  _   _  __| | ___ | | ___   _\t   %c\n"
		"\t  %c\t \\___ \\| | | |/ _` |/ _ \\| |/ / | | |\t   %c\n"
		"\t  %c\t ____) | |_| | (_| | (_) |   <| |_| |\t   %c\n"
		"\t  %c\t|_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_|\t   %c\n"
		"\t  %c\t\t\t\t\t\t   %c\n",
		cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch, cHoch,
		cHoch, cHoch, cHoch, cHoch, cHoch);

	// Schreibe Benutzernamen
	if (iLoginChange == 0)
	{
		printf("\t  %c\t\tBenutzer: %s%c\n", cHoch, sNameLeer, cHoch);
	}
	else
	{
		printf("\t  %c\t\tBenutzer: %s%c\n", cHoch, sUser, cHoch);
	}

	// Baue Ramhmen
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
	// Erstelle den Header
	system("cls");
	printf("\n\n");
	sudoku_header();


	//Menu
	if (iLoginChange == 0) {
		// Ohne Login
		printf("\t\t(1) Schnellstart\n\n");
		printf("\t\t(2) Login\n\n");
		printf("\t\t(3) Benutzer anlegen\n\n");
		printf("\t\t(4) Hall of Fame\n\n");
		printf("\t\t(5) Regeln anzeigen\n\n");
		printf("\t\t(X) Beenden\n\n\n");
	}
	else {
		// mit Login
		printf("\t\t(1) Neues Spiel starten\n\n");
		printf("\t\t(2) Log Out\n\n");
		printf("\t\t(3) Hall of Fame\n\n");
		printf("\t\t(4) Regeln anzeigen\n\n");
		printf("\t\t(X) Beenden\n\n\n");
	}
}


// Menu der Hall of Fame
void hallOfFameAnzeige(void)
{
	// Header
	system("cls");
	printf("\n\n");
	sudoku_header();

	// Anzeige
	printf("\t\t(1) Leicht\n\n");
	printf("\t\t(2) Mittel\n\n");
	printf("\t\t(3) Schwer\n\n");
	printf("\t\t(X) Beenden\n\n\n");
}

// Baue das Sudokufeld
void layout(void)
{
	// Definition
	char cObenRechtEcke = 201;		// ╔
	char cUntenRechtEcke = 200;		// ╚
	char cObenLinksEcke = 187;		// ╗
	char cUntenLinksEcke = 188;		// ╝
	char cObenMitte = 203;			// ╦
	char cUntenMitte = 202;			// ╩
	char cAlleMitte = 206;			// ╬
	char cRechtsMitte = 204;		// ╠
	char cLinksMitte = 185;			// ╣
	char cGerade = 205;				// ═
	char cHoch = 186;				// ║
	char cHochinnen = 179;			// |
	char cTrenner = 196;			// ─
	char cAlleTrenner = 197;		// ┼
	int iKoord = 1;					// Y koordinaten anzeige
	int iZeichneOderZahl;			// abfage ob Zeichen oder Zahl
	int iGridZ = 0;
	int iGridS = 0;

	hColor = GetStdHandle(STD_OUTPUT_HANDLE); // Farbe setzen
	SetConsoleTextAttribute(hColor, 15); // weiß



									// Freld erzeugung
	printf("\n\n");
	printf("\t    1   2   3   4   5   6   7   8   9\n");
	// Ramen oben
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t \033[4mMenu:\033[0m\n", cObenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenLinksEcke);
	for (int i = 1; i <= 17; i++)
	{
		printf("\t");
		if (i % 2 != 0) // wenn i Ungerade
		{
			iZeichneOderZahl = 0; // Überspringe die ersten beiden Fälle
			iGridS = 0;
			for (int j = 0; j <= 37; j++)
			{
				if (j == 0)
				{
					SetConsoleTextAttribute(hColor, 15);
					printf("%i ", iKoord); // schriebe an ersterstelle die Koordinate
				}
				else if(j % 2 == 0) // wenn j gerade setze leerzeichen
				{
					printf(" ");
				}
				else // wenn ungerade und nicht 0 ist
				{
					
					if (j == 1 || j == 13 || j == 25 || j == 37)
					{
						printf("%c", cHoch); // Pipe
					}
					else if (iZeichneOderZahl % 2 == 1) // Ungerade
					{
						if (iLoesung == 0)
						{
							// iGrid
							if (iGridmuster[iGridZ][iGridS] == 1)
							{
								SetConsoleTextAttribute(hColor, 11);
								printf("%i", iGrid[iGridZ][iGridS]);
								SetConsoleTextAttribute(hColor, 15);
							}
							else
							{
								printf(" ");
							}
						}
						else if (iLoesung == 1)
						{
							// iGrid
							if (iGridmuster[iGridZ][iGridS] == 1)
							{
								SetConsoleTextAttribute(hColor, 11);
								printf("%i", iGrid[iGridZ][iGridS]);
								SetConsoleTextAttribute(hColor, 15);
							}
							else
							{
								SetConsoleTextAttribute(hColor, 10);
								printf("%i", iGrid[iGridZ][iGridS]);
								SetConsoleTextAttribute(hColor, 15);
								
							}
						}
						else
						{
							if (iGridmuster[iGridZ][iGridS] == 1)
							{
								if (iGridplay[iGridZ][iGridS] == 1)
								{
									SetConsoleTextAttribute(hColor, 11);
									printf("%i", iGrid[iGridZ][iGridS]);
									SetConsoleTextAttribute(hColor, 15);
								}
								else
								{
									printf(" ");

								}
							}
							else
							{
								if (iGridplay[iGridZ][iGridS] == 1)
								{
									SetConsoleTextAttribute(hColor, 15);
									printf("%i", iGrid[iGridZ][iGridS]);
									SetConsoleTextAttribute(hColor, 15);
								}
								else
								{
									printf(" ");

								}
							}
							

							
						}
						iGridS++;

					}
					else
					{
						// Hoch
						printf("%c", cHochinnen); // setze Trenner
					}
					iZeichneOderZahl++;
				}
				
				
			}
			
			printf("\n");
			iGridZ++;
			iKoord++;
		}
		else
		{
			if (iKoord == 2)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t n = Neues Spiel\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
			}
			else if (iKoord == 3)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t l = Loesung anzeigen\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
			}
			else if (iKoord == 4)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t h = Hilfe anzeigen\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
			}
			else if (iKoord == 5)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t (nur in der Zahl Eingabe anwendbar)\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
			}
			else if (iKoord == 6)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t x = Beenden\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
			}
			else if (iKoord == 7)
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
			}
			else
			{
				printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
			}
		}
		
		/*printf("\t1 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c\t\t\t n = Neues Spiel\n", cHoch, iGrid[0][0], cHochinnen, iGrid[0][1], cHochinnen, iGrid[0][2], cHoch, iGrid[0][3], cHochinnen, iGrid[0][4], cHochinnen, iGrid[0][5], cHoch, iGrid[0][6], cHochinnen, iGrid[0][7], cHochinnen, iGrid[0][8], cHoch);*/
	}

	// Rahmen unten
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cUntenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenLinksEcke);
	printf("\n");


	//// Freld erzeugung
	//printf("\n\n");
	//printf("\t    1   2   3   4   5   6   7   8   9\n");
	//// Zeile 1
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t\t \033[4mMenu:\033[0m\n", cObenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cObenLinksEcke);
	//// Zeile 2
	//printf("\t1 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c\t\t\t n = Neues Spiel\n", cHoch, iGrid[0][0], cHochinnen, iGrid[0][1], cHochinnen, iGrid[0][2], cHoch, iGrid[0][3], cHochinnen, iGrid[0][4], cHochinnen, iGrid[0][5], cHoch, iGrid[0][6], cHochinnen, iGrid[0][7], cHochinnen, iGrid[0][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\t\t\t l = Loesung anzeigen\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 3
	//printf("\t2 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c\t\t\t x = Beenden\n", cHoch, iGrid[1][0], cHochinnen, iGrid[1][1], cHochinnen, iGrid[1][2], cHoch, iGrid[1][3], cHochinnen, iGrid[1][4], cHochinnen, iGrid[1][5], cHoch, iGrid[1][6], cHochinnen, iGrid[1][7], cHochinnen, iGrid[1][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 4
	//printf("\t3 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[2][0], cHochinnen, iGrid[2][1], cHochinnen, iGrid[2][2], cHoch, iGrid[2][3], cHochinnen, iGrid[2][4], cHochinnen, iGrid[2][5], cHoch, iGrid[2][6], cHochinnen, iGrid[2][7], cHochinnen, iGrid[2][8], cHoch);
	//// Zeile 5
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
	//// Zeile 6
	//printf("\t4 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[3][0], cHochinnen, iGrid[3][1], cHochinnen, iGrid[3][2], cHoch, iGrid[3][3], cHochinnen, iGrid[3][4], cHochinnen, iGrid[3][5], cHoch, iGrid[3][6], cHochinnen, iGrid[3][7], cHochinnen, iGrid[3][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 7
	//printf("\t5 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[4][0], cHochinnen, iGrid[4][1], cHochinnen, iGrid[4][2], cHoch, iGrid[4][3], cHochinnen, iGrid[4][4], cHochinnen, iGrid[4][5], cHoch, iGrid[4][6], cHochinnen, iGrid[4][7], cHochinnen, iGrid[4][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 8
	//printf("\t6 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[5][0], cHochinnen, iGrid[5][1], cHochinnen, iGrid[5][2], cHoch, iGrid[5][3], cHochinnen, iGrid[5][4], cHochinnen, iGrid[5][5], cHoch, iGrid[5][6], cHochinnen, iGrid[5][7], cHochinnen, iGrid[5][8], cHoch);
	//// Zeile 10
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cRechtsMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cAlleMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cLinksMitte);
	//// Zeile 11
	//printf("\t7 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[6][0], cHochinnen, iGrid[6][1], cHochinnen, iGrid[6][2], cHoch, iGrid[6][3], cHochinnen, iGrid[6][4], cHochinnen, iGrid[6][5], cHoch, iGrid[6][6], cHochinnen, iGrid[6][7], cHochinnen, iGrid[6][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 12
	//printf("\t8 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[7][0], cHochinnen, iGrid[7][1], cHochinnen, iGrid[7][2], cHoch, iGrid[7][3], cHochinnen, iGrid[7][4], cHochinnen, iGrid[7][5], cHoch, iGrid[7][6], cHochinnen, iGrid[7][7], cHochinnen, iGrid[7][8], cHoch);
	//// Trenner
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cHoch, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleMitte, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cAlleTrenner, cTrenner, cTrenner, cTrenner, cHoch);
	//// Zeile 13
	//printf("\t9 %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c %i %c \n", cHoch, iGrid[8][0], cHochinnen, iGrid[8][1], cHochinnen, iGrid[8][2], cHoch, iGrid[8][3], cHochinnen, iGrid[8][4], cHochinnen, iGrid[8][5], cHoch, iGrid[8][6], cHochinnen, iGrid[8][7], cHochinnen, iGrid[8][8], cHoch);
	//// Zeile 14
	//printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", cUntenRechtEcke, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenMitte, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cGerade, cUntenLinksEcke);
	//printf("\n");

	
}