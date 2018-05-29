//menu.h



int menuAusgabe()
{
	int imenu;
	int iError = 0;

	do
	{
		system("cls");
		printf("\n\n");
		printf("\t   ___           _       _			\n"
			"\t  / __|         | |     | |         \n"
			"\t | (_  _   _  _| | __ | | _   _ \n"
			"\t  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |\n"
			"\t  _) | || | (| | () |   <| |_| |\n"
			"\t |__/ \\,|\\_,|\\__/||\\_\\\\_,|\n");



		printf("\t(1) Schnellstart\n\n");
		printf("\t(2) Neues Spiel starten\n\n");
		printf("\t(3) Login\n");
		printf("\t(4) Benutzer anlegen\n\n");
		printf("\t(5) Bestenliste\n\n");
		printf("\t(6) Regeln anzeigen\n\n");
		printf("\t(7) Beenden\n\n");
		fflush(stdin);
		iError = scanf("%i", &imenu);
	} while (iError == 0 || imenu < 1 || imenu > 7);

	printf("\n");

	system("Pause");

	return imenu;
}

void menu(void)
{
	int imenu;
	imenu = menuAusgabe();

	switch (imenu)
	{
	case 1:
		// Schnellstart

		break;

	case 2:
		// Neues Spiel starten
		break;

	case 3:
		// Login
		break;

	case 4:
		// Benutzer anlegen
		break;

	case 5:
		// Bestenliste
		break;

	case 6:
		// Regeln anzeigen
		openFile();
		menu();
		break;

	case 7:
		// Beenden
		exit(0);

	default:
		menu();
	}

}

