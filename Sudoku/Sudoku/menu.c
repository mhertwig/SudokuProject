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
	



	do
	{
		menuAnzeige();

		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		//if(cMenu)
		printf("\n");
		switch (cMenu)
		{
		case '1':
			// Schnellstart

			//schleife = 0;
			break;

		case '2':
			// Neues Spiel starten
			//schleife = 0;
			break;

		case '3':
			// Login
			printf("\t\033[4mLogin\033[0m\n\n");
			login_user();
			printf("\n\t");
			system("Pause");
			break;

		case '4':
			
			if (iLoginChange = 0)
			{
				// Benutzer anlegen
				printf("\t\033[4mRegistrierung\033[0m\n\n");

				register_user(sUser, sPasswort, sNachname, sVorname);
				printf("\n\t");
				system("Pause");
				break;
			}
			else
			{
				logout_user();
				printf("\tBenutzer wurde ausgeloggt\n\n");
				printf("\n\t");
				system("Pause");
				break;
			}
			

		case '5':
			// Bestenliste
			break;

		case '6':
			// Regeln anzeigen
			ShellExecute(NULL, NULL, "sudoku - anleitung.pdf", NULL, NULL, SW_SHOW);
			break;

		case 'x':
			// Beenden

				schleife = 0;
		}
	} while (schleife == 1);

}



