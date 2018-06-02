//menu.h

#include "include.h"

void menu(void)
{
	char cMenu;
	int iError = 0;
	int schleife = 1;
	char sUser[26];
	char sPasswort[20];
	char sNachname[20];
	char sVorname[20];
	char file[100] = "sudoku-anleitung.pdf";

	do
	{
		menuAnzeige();

		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		//if(cMenu)
		printf("\n");

		//Ohne Login
		if (iLoginChange == 0)
		{
			switch (cMenu)
			{
			case '1':
				// Schnellstart
				//schleife = 0;
				break;

			case '2':
				// Login
				printf("\t\033[4mLogin\033[0m\n\n");
				login_user();
				printf("\n\t");
				system("Pause");
				break;

			case '3':
				// Benutzer anlegen
				printf("\t\033[4mRegistrierung\033[0m\n\n");
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
				ShellExecute(NULL, NULL, file, NULL, NULL, SW_SHOW);
				break;

			case 'x':
				// Beenden
				schleife = 0;
			}
		}
		else {
		//Eingeloggt
			switch (cMenu)
			{
			case '1':
				// Neues Spiel starten
				//schleife = 0;
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
				ShellExecute(NULL, NULL, file, NULL, NULL, SW_SHOW);
				break;

			case 'x':
				// Beenden
				schleife = 0;
			}



		}
	} while (schleife == 1);

}