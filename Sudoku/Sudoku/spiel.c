#include "include.h"

int spielFeldAusgabe(void) {

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

		// Abfrage welche Zeile gesetzt werden soll
		do
		{
			printf("\tZeile: ");
			fflush(stdin);
			while (getchar() != '\n');
			iError = scanf("%c", &cZeile);
			// Abfragemenu
			if (cZeile == 'x')
			{
				// starte menu
				menu();
				return 0;
			}
			if (cZeile == 'n')
			{
				// Generiere neues Sudokuarray und drucke es aus
				sudokuGenShift();
				spielFeldAusgabe();
				return 0;
			}
			if (cZeile == 'l')
			{
				// Zeige Lösung und beende das Spiel
				iLoesung = 1;
				lösungAnzeigen();
				return 0;
			}
			if (iError != 0)
			{
				// Wandel char in int um
				iLoesung = 2;
				iZeile = cZeile - '0';
			}
		} while (iError == 0 || iZeile == -38);


		// Aus der Endlosschleife rauspringen
		if (iEndlos != 1)
		{
			// Abfrage welche Spalte gesetzt werden soll
			do
			{
				printf("\tSpalte: ");
				while (getchar() != '\n');
				iError = scanf("%c", &cSpalte);
				if (cSpalte == 'x')
				{
					// starte menu
					menu();
					return 0;
				}
				if (cSpalte == 'n')
				{
					// Generiere neues Sudokuarray und drucke es aus
					sudokuGenShift();
					spielFeldAusgabe();
					return 0;
				}
				if (cSpalte == 'l')
				{
					// Zeige Lösung und beende das Spiel
					lösungAnzeigen();
					return 0;
				}
				if (iError != 0)
				{
					// Wandel char in int um
					iLoesung = 2;
					iSpalte = cSpalte - '0';
				}
			} while (iError == 0 || iSpalte == -38);

		}

		// Aus der Endlosschleife rauspringen
		if (iEndlos != 1)
		{
			 // Abfrage welche Zahl gesetzt werden soll
			do
			{
				printf("\tZahl: ");
				while (getchar() != '\n');
				iError = scanf("%2c", &cZahl);
				if (cZahl == 'x')
				{
					// starte menu
					menu();
					return 0;
				}
				if (cZahl == 'n')
				{
					// Generiere neues Sudokuarray und drucke es aus
					sudokuGenShift();
					spielFeldAusgabe();
					return 0;
				}
				if (cZahl == 'l')
				{
					// Zeige Lösung und beende das Spiel
					lösungAnzeigen();
					return 0;
				}
				if (iError != 0)
				{
					// Wandel char in int um
					iLoesung = 2;
					iZahl = cZahl - '0';
				}
			} while (iError == 0 || iZahl == -38);
			fflush(stdin);

			// Setze Zahl in das Sudokufeld
			if (iGridmuster[iZeile - 1][iSpalte - 1] == 0)
			{
				iGrid[iZeile - 1][iSpalte - 1] = iZahl;
				iGridplay[iZeile - 1][iSpalte - 1] = 1;
			}
			
		}

		if (sudokuAbfrage() == 1)
		{
			// Schreibe in Die bestenliste falls Eingeloggt
			// -----------------------
			printf("\tSudoku wurde geloesst\n");
			return 1;
		}

	}while(iEndlos == 0);
}

void lösungAnzeigen(void)
{
	// Schreibe Lösungen in das Sudokuarray
	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			iGrid[iIndexV][iIndexH] = iGridCopy[iIndexV][iIndexH];
		}
	}

	//Layout und Spielende Ausgabe
	system("cls");
	sudoku_header();
	layout();
	printf("\tSPIEL VORBEI! \n\tLoesung wurde angezeigt\n\t");
	system("Pause");
}

int sudokuAbfrage(void)
{
	// Frage ab ob das Sudoku Fertig ist und gebe 0 oder 1 aus
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

