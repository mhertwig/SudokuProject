#include "include.h"

int iAnzahlHilfe;

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
	int iFlag = 0;
	

	do
	{
		
		// Setze Zeit
		iZeit = clock() - iStartZeit;
		iZeit = iZeit / CLOCKS_PER_SEC;

		//Layout
		system("cls");
		sudoku_header();

		// Zeige Zeit
		//printf("\t\tSpielzeit: %2.0lf:%2.0lf:%2.0lf", dZeit/3600,dZeit/60,dZeit % 60);
		printf("\t\tSpielzeit: %2i:%2i:%2i", iZeit / 3600, iZeit / 60, iZeit % 60);
		printf("\n\n");

		// Feld
		layout();

		

		if (sudokuAbfrage() == 1)
		{
			// Schreibe in Die bestenliste falls Eingeloggt
			// -----------------------
			printf("\tSudoku wurde geloesst!\n");
			printf("\t");
			system("Pause");

			if(iLoginChange == 1){
				hallOfFameEintragen_menu();
			}
			return 1;
		}

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
				iSchwierigkeitsgrad = 0;
				menu();
				return 0;
			}
			if (cZeile == 'n')
			{
				// Generiere neues Sudokuarray und drucke es aus
				iStartZeit = iZeit = clock();
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
					iSchwierigkeitsgrad = 0;
					menu();
					return 0;
				}
				if (cSpalte == 'n')
				{
					// Generiere neues Sudokuarray und drucke es aus
					iStartZeit = iZeit = clock();
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
		iFlag = 0;
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
					iSchwierigkeitsgrad = 0;
					menu();
					return 0;
				}
				if (cZahl == 'n')
				{
					// Generiere neues Sudokuarray und drucke es aus
					iStartZeit = iZeit = clock();
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
				if (cZahl == 'h')
				{
					if (iGridmuster[iZeile - 1][iSpalte - 1] == 0)
					{
						iGrid[iZeile - 1][iSpalte - 1] = iGridCopy[iZeile - 1][iSpalte - 1];
						iGridplay[iZeile - 1][iSpalte - 1] = 1;
						iFlag = 1;
						iAnzahlHilfe++;
					}
				}
				if (iError != 0 && iFlag == 0)
				{
					// Wandel char in int um
					iLoesung = 2;
					iZahl = cZahl - '0';
					
				}
			} while (iError == 0 || iZahl == -38);
			fflush(stdin);

			// Setze Zahl in das Sudokufeld
			if (iFlag == 0)
			{
				if (iGridmuster[iZeile - 1][iSpalte - 1] == 0)
				{
					iGrid[iZeile - 1][iSpalte - 1] = iZahl;
					iGridplay[iZeile - 1][iSpalte - 1] = 1;
				}
			}
			
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

	iSchwierigkeitsgrad = 0;

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
	//iSchwierigkeitsgrad = 0;

	// setze Zeit
	iZeit += clock() - iStartZeit;
	iZeit = iZeit / CLOCKS_PER_SEC;

	return 1; // Richtig
}

