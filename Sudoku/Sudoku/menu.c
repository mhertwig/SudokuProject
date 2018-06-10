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
	int iError2 = 0;
	char cMenu2 = 0;
	int iSchleife2 = 1;
	//int iSchwierigkeitsgrad;

	do
	{
		iLoesung = 0;
		iZeit = 0;
		iStartZeit = 0;
		iSchwierigkeitsgrad = 0;

		// Anzeige des Menu's
		menuAnzeige();


		// Abfrage der Eingabe
		printf("\tEingabe: ");
		fflush(stdin);
		scanf("%c", &cMenu);
		printf("\n");

		// Ohne Login
		if (iLoginChange == 0)
		{
			switch (cMenu)
			{
			case '1':
				// Schnellstart
				do
				{
					schwierigkeitsMenu();

					//Auswahl des Menüpunkts bzw. Case auswahl
					printf("\tEingabe: ");
					fflush(stdin);
					iError2 = scanf("%c", &cMenu2);
					printf("\n");

					{
						switch (cMenu2)
						{
						case '1':
							//Leicht
							//setze Schwierigkeitsgrad Leicht
							iSchwierigkeitsgrad = 1;
							iStartZeit = iZeit = clock();
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();

							break;

						case '2':
							//Mittel
							//setze Schwierigkeitsgrad Mittel
							iSchwierigkeitsgrad = 2;
							iStartZeit = iZeit = clock();
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case '3':
							//Schwer
							//setze Schwierigkeitsgrad Schwer
							iSchwierigkeitsgrad = 3;
							iStartZeit = iZeit = clock();
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case '4':
							//Schwer
							//setze Schwierigkeitsgrad Schwer
							iSchwierigkeitsgrad = 4;
							iStartZeit = iZeit = clock();
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case 'x':
							// Beenden
							iSchleife2 = 0;
						}
					}

				} while (iSchleife2 == 1);

				
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
				do
				{
					hallOfFameAnzeige();

					//Auswahl des Menüpunkts bzw. Case auswahl
					printf("\tEingabe: ");
					fflush(stdin);
					iError2 = scanf("%c", &cMenu2);
					printf("\n");

					{
						switch (cMenu2)
						{
						case '1':
							//Leicht
							//setze Schwierigkeitsgrad Leicht
							iSchwierigkeitsgrad = 1;
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case '2':
							//Mittel
							//setze Schwierigkeitsgrad Mittel
							iSchwierigkeitsgrad = 2;
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case '3':
							//Schwer
							//setze Schwierigkeitsgrad Schwer
							iSchwierigkeitsgrad = 3;
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case '4':
							//Schwer
							//setze Schwierigkeitsgrad Schwer
							iSchwierigkeitsgrad = 4;
							iSchleife2 = 0;
							sudokuGenShift();
							spielFeldAusgabe();
							break;

						case 'x':
							// Beenden
							iSchleife2 = 0;
						}
					}

				} while (iSchleife2 == 1);


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