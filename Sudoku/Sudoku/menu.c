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
		system("cls");
		printf("\n\n");
		sudoku_header();

		printf("\t\t(1) Schnellstart\n\n");
		printf("\t\t(2) Neues Spiel starten\n\n");
		printf("\t\t(3) Login\n\n");
		printf("\t\t(4) Benutzer anlegen\n\n");
		printf("\t\t(5) Bestenliste\n\n");
		printf("\t\t(6) Regeln anzeigen\n\n");
		printf("\t\t(X) Beenden\n\n\n");

		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		//if(cMenu)
		printf("\n");
		switch (cMenu)
		{
		case 1:
			// Schnellstart

			//schleife = 0;
			break;

		case 2:
			// Neues Spiel starten
			//schleife = 0;
			break;

		case 3:
			// Login
			printf("\t\033[4mLogin\033[0m\n\n");
			login_user();
			system("Pause");
			break;

		case 4:
			// Benutzer anlegen
			printf("\t\033[4mRegistrierung\033[0m\n\n");

			register_user(sUser, sPasswort, sNachname, sVorname);
			system("Pause");
			break;

		case 5:
			// Bestenliste
			break;

		case 6:
			// Regeln anzeigen
			ShellExecute(NULL, NULL, "sudoku - anleitung.pdf", NULL, NULL, SW_SHOW);
			break;

		case 'x':
			// Beenden

			if (cMenu == 'x')
			{
				schleife = 0;
			}
		}
	} while (schleife == 1);

}



