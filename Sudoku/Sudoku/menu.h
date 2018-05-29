//menu.h



void menu(void)
{
	int imenu;
	int iError = 0;
	int schleife = 1;




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
		printf("\t\t(7) Beenden\n\n\n");

		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%i", &imenu);

		switch (imenu)
		{
		case 1:
			// Schnellstart

			schleife = 0;
			break;

		case 2:
			// Neues Spiel starten
			schleife = 0;
			break;

		case 3:
			// Login
			login_user();
			schleife = 0;
			break;

		case 4:
			// Benutzer anlegen
			register_user(sUser, sPasswort, sNachname, sVorname);
			schleife = 0;
			break;

		case 5:
			// Bestenliste
			schleife = 0;
			break;

		case 6:
			// Regeln anzeigen
			openFile();
			break;

		case 7:
			// Beenden
			exit(0);

		default:
			break;
		}
	} while (schleife == 1);
	
}



