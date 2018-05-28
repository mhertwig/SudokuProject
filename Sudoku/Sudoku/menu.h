//menu.h

void menu(void)
{
	int iError = 0;

	do
	{
		printf("(1) Schnellstart\n\n");
		printf("(2) Login\n");
		printf("(3) Benutzer anlegen\n\n");
		printf("(4) Bestenliste\n\n");
		printf("(5) Regeln anzeigen\n\n");
		printf("(6) Beenden\n\n");
		fflush(stdin);
		iError = scanf("%i", &imenu);
	} while (iError == 0 || imenu < 1 || imenu > 2);

	printf("\n");




	system("Pause");

}