//menu.c

#include "include.h"

void menu(void)
{
	// Definiton
	char cMenu;
	int iSchleife = 1;
	char sUser[26];
	char sPasswort[20];
	char sNachname[20];
	char sVorname[20];
	char cFile[100] = "sudoku-anleitung.pdf";
	int iAnzahlhilfe = 0;


	do
	{
		iLoesung = 0;

		// Anzeige des Menu's
		menuAnzeige();


		// Abfrage der Eingabe
		printf("\tEingabe: ");
		fflush(stdin);
		scanf_s("%c", &cMenu);
		printf("\n");

		// Ohne Login
		if (iLoginChange == 0)
		{
			switch (cMenu)
			{
			case '1':
				// Schnellstart
				sudokuGenShift();
				spielFeldAusgabe();
				break;

			case '2':
				// Login
				login_user();
				printf("\n\t");
				system("Pause");
				break;

			case '3':
				// Benutzer anlegen
				register_user(sUser, sPasswort, sNachname, sVorname);
				printf("\n\t");
				system("Pause");
				break;

			case '4':
				// Bestenliste
				hallOfFame_menu();
				break;

			case '5':
				// Regeln anzeigen
				ShellExecute(NULL, NULL, cFile, NULL, NULL, SW_SHOW);
				break;

			case 'x':
				// Beenden
				iSchleife = 0;
			}
		}
		else {
		// Eingeloggt
			switch (cMenu)
			{
			case '1':
				// Neues Spiel starten
				sudokuGenShift();
				spielFeldAusgabe();
				break;

			case '2':
				// Logout
				printf("\t\033[4mLogout\033[0m\n\n");
				logout_user();
				printf("\n\t");
				system("Pause");
				break;

			case '3':
				// Bestenliste
				hallOfFame_menu();
				break;

			case '4':
				// Regeln anzeigen
				ShellExecute(NULL, NULL, cFile, NULL, NULL, SW_SHOW);
				break;

			case 'x':
				// Beenden
				iSchleife = 0;
			}



		}
	} while (iSchleife == 1);

}