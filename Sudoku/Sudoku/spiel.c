#include "include.h"

#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS


void spielFeldAusgabe(void) {

	// Definition
	int iZeile = 100;
	int iSpalte = 100;
	int iZahl = 100;
	int iError;
	int itest = 0;

	do
	{

		//Layout
		system("cls");
		sudoku_header();
		layout();

		//system("\t");
		//system("Pause");


		do
		{
			if (iZeile < 0 || iZeile > 8 || iZeile != NULL)
			{
				printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!");
			}
			printf("\tZeile: ");
			fflush(stdin);
			iError = scanf_s("%i", iZeile - 1);
		} while (iError == 0 || iZeile < 0 || iZeile > 8 || iZeile != NULL);

		do
		{
			if (iSpalte < 0 || iSpalte > 8 || iSpalte != NULL)
			{
				printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!");
			}
			printf("\tSpalte: ");
			fflush(stdin);
			iError = scanf_s("%i", iSpalte - 1);
		} while (iError == 0 || iSpalte < 0 || iSpalte > 8 || iSpalte != NULL);

		do
		{
			if (iZahl < 0 || iZahl > 8 || iZahl != NULL)
			{
				printf("Ihre Zahlen dürfen nur von 1 - 9 gehen!");
			}
			printf("\tZeile: ");
			fflush(stdin);
			iError = scanf_s("%i", iZahl - 1);
		} while (iError == 0 || iZahl < 0 || iZahl > 8 || iZahl != NULL);

		iGrid[iSpalte][iZeile] = iZahl;

		spielFeldAusgabe();
	} while (itest == 0);
	

}

