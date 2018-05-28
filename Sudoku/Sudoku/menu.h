//menu.h

void menu(void)
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

	switch (imenu)
	{
	case constant1:
		statements
			break;

	case constant2:
		statements
			break;

	case constant3:
		statements
			break;



	system("Pause");

}

