//menu.h



int menu()
{
	int imenu;
	int iError = 0;

	do
	{
		printf("(1) Schnellstart\n\n");
		printf("(2) Neues Spiel starten\n\n");
		printf("(3) Login\n");
		printf("(4) Benutzer anlegen\n\n");
		printf("(5) Bestenliste\n\n");
		printf("(6) Regeln anzeigen\n\n");
		printf("(7) Beenden\n\n");
		fflush(stdin);
		iError = scanf("%i", &imenu);
	} while (iError == 0 || imenu < 1 || imenu > 7);

	printf("\n");

	system("Pause");

	return imenu;
}

void funk(void)
{
	int imenu;
	imenu = menu();

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
		break;

	case 7:
		// Beenden
		exit(0);
	}

