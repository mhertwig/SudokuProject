#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"


char sUser[26];
int cMenu = 0;
int iError = 0;
int anzahlHilfe = 0;
int schleife = 1;

/*
================================================
Funktion hallOfFame_menu
================================================
*/
void hallOfFame_menu(void) {
	do
	{
		hallOfFameAnzeige();

		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		//if(cMenu)
		printf("\n");

		{
			switch (cMenu)
			{
			case '1':
				//Leicht
				printf("\t\033[4mLeicht\033[0m\n\n");
				//anzeige HallofFame Leicht
				printf("\n\t");
				system("Pause");
				break;

			case '2':
				// Mittel
				printf("\t\033[4mMittel\033[0m\n\n");
				//anzeige HallofFame Mittel
				printf("\n\t");
				system("Pause");
				break;

			case '3':
				//Schwer
				printf("\t\033[4mSchwer\033[0m\n\n");
				//anzeige HallofFame Schwer
				printf("\n\t");
				system("Pause");
				break;

			case 'x':
				// Beenden
				schleife = 0;
			}
		}

	} while (schleife == 1);
}


/*
================================================
Funktion schreibe_hallOfFame
================================================


void schreibe_hallOfFame(char *sUser) {

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	scan(sUser, sPasswort, sNachname, sVorname);
	if (flag == 0)
	{

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("INSERT INTO benutzer VALUES (NULL, %Q, %Q, %Q, %Q, \
				date('now'));", sUser, sPasswort, sNachname, sVorname);

		if (rc == SQLITE_OK)
		{
			rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
			if (rc == SQLITE_OK)
			{
				sqlite3_close(db_handle);
				printf("\tUser %s erfolgreich erstellt!\n\n", sUser);
				return 0;
			}
			else {
				printf("\tSQL Fehler: %s\n\n", zErrMsg);
				sqlite3_free(zErrMsg);
				sqlite3_close(db_handle);
				system("\tPause");
				menu();

			}
		}
	}
}

void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname) {

	printf("\tUsername: ");
	scanf("%s", sUser);
	if (*sUser == 'x')
	{
		flag = 1;
		return 0;
	}

}
*/