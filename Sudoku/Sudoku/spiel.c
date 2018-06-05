#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"

void menuImSpiel(void)
{

}


void spielFeldAusgabe(void) {

	// Definition
	char cZeile = 0;
	char cSpalte = 0;
	char cZahl = 0;
	int iZahl = 0;
	int iZeile = 0;
	int iSpalte = 0;
	int iError;

	/*do
	{*/

	//Layout
	system("cls");
	sudoku_header();
	layout();

	//system("\t");
	//system("Pause");


	do
	{
		/*if (iZeile < 0 && iZeile > 8 && iZeile != NULL)
		{
		printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!\n");
		}*/
		printf("\tZeile: ");
		fflush(stdin);
		while (getchar() != '\n');
		iError = scanf("%c", &cZeile);
		if (cZeile == 'x')
		{
			menu();
		}
		if (cZeile == 'n')
		{
			sudokuGenShift();
			spielFeldAusgabe();
		}
		if (cZeile == 'l')
		{
			
		}
		if (iError != 0)
		{
			iZeile = cZeile - '0';
		}
	} while (iError == 0 || iZeile == -38);
	


	do
	{
		/*if (iSpalte < 0 && iSpalte > 8 && iSpalte != NULL)
		{
		printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!\n");
		}*/
		printf("\tSpalte: ");
		fflush(stdin);
		while (getchar() != '\n');
		iError = scanf("%c", &cSpalte);
		if (cSpalte == 'x')
		{
			menu();
		}
		if (cSpalte == 'n')
		{
			sudokuGenShift();
			spielFeldAusgabe();
		}
		if (cSpalte == 'l')
		{

		}
		if (iError != 0)
		{
			iSpalte = cSpalte - '0';
		}
	} while (iError == 0 || iSpalte == -38);
	

	do
	{
		/*if (iZahl < 0 && iZahl > 8 && iZahl != NULL)
		{
		printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!\n");
		}*/
		printf("\tZahl: ");
		fflush(stdin);
		while (getchar() != '\n');
		iError = scanf("%2c", &cZahl);
		if (cZahl == 'x')
		{
			menu();
		}
		if (cZahl == 'n')
		{
			sudokuGenShift();
			spielFeldAusgabe();
		}
		if (cZahl == 'l')
		{

		}
		if (iError != 0)
		{
			iZahl = cZahl - '0';
		}
	} while (iError == 0 || iZahl == -38);


	iGrid[iZeile - 1][iSpalte - 1] = iZahl;



	spielFeldAusgabe();
	


}

void lösungAnzeigen(void)
{

}

