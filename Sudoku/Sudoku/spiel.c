#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"

void spielFeldAusgabe(void) {

	// Definition
	char cZeile = 0;
	char cSpalte = 0;
	char cZahl = 0;
	int iZahl = 0;
	int iZeile = 0;
	int iSpalte = 0;
	int iError;
	int iEndlos = 0;

	do
	{
		


		//Layout
		system("cls");
		sudoku_header();
		layout();

		do
		{
			// Eingabe der Zeile
			printf("\tZeile: ");
			fflush(stdin);
			while (getchar() != '\n');
			iError = scanf("%c", &cZeile);
			// Abfragemenu
			if (cZeile == 'x')
			{
				menu();
				iEndlos = 1;
			}
			if (cZeile == 'n')
			{
				sudokuGenShift();
				spielFeldAusgabe();
				iEndlos = 1;
			}
			if (cZeile == 'l')
			{
				lösungAnzeigen();
				iEndlos = 1;
			}
			if (iError != 0)
			{
				// Wandel char in int um
				iZeile = cZeile - '0';
			}
		} while (iError == 0 || iZeile == -38);


		// Aus der Endlosschleife rauspringen
		if (iEndlos != 1)
		{

			do
			{
				printf("\tSpalte: ");
				while (getchar() != '\n');
				iError = scanf("%c", &cSpalte);
				if (cSpalte == 'x')
				{
					menu();
					iEndlos = 1;
				}
				if (cSpalte == 'n')
				{
					sudokuGenShift();
					spielFeldAusgabe();
					iEndlos = 1;
				}
				if (cSpalte == 'l')
				{
					lösungAnzeigen();
					iEndlos = 1;
				}
				if (iError != 0)
				{
					// Wandel char in int um
					iSpalte = cSpalte - '0';
				}
			} while (iError == 0 || iSpalte == -38);

		}

		// Aus der Endlosschleife rauspringen
		if (iEndlos != 1)
		{
			 
			do
			{
				printf("\tZahl: ");
				//fflush(stdin);
				while (getchar() != '\n');
				iError = scanf("%2c", &cZahl);
				if (cZahl == 'x')
				{
					menu();
					iEndlos = 1;
				}
				if (cZahl == 'n')
				{
					sudokuGenShift();
					spielFeldAusgabe();
					iEndlos = 1;
				}
				if (cZahl == 'l')
				{
					lösungAnzeigen();
					iEndlos = 1;
				}
				if (iError != 0)
				{
					// Wandel char in int um
					iZahl = cZahl - '0';
				}
			} while (iError == 0 || iZahl == -38);
			fflush(stdin);

			// Setze Zahl in das Sudokufeld
			iGrid[iZeile - 1][iSpalte - 1] = iZahl;
		}

	}while(iEndlos == 0);
	return 0;
}

void lösungAnzeigen(void)
{
	// Schreibe Lösungen in 
	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			iGrid[iIndexV][iIndexH] = iGridCopy[iIndexV][iIndexH];
		}
	}

	//Layout
	system("cls");
	sudoku_header();
	layout();
	printf("\tSPIEL VORBEI! \n\tLoesung wurde angezeigt\n\t");
	system("Pause");
}

int sudokuAbfrage(void)
{
	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			if (iGrid[iIndexV][iIndexH] != iGridCopy[iIndexV][iIndexH])
			{
				return 0; // Falsch
			}
		}
	}
	return 1; // Richtig
}

