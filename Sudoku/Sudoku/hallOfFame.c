#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"


int cMenu = 0;
int schleife = 1;
int iError = 0;

char sUser[26];

char testUser[26] = "Marwin";
int anzahlHilfe = 3;
int zeit = 20;
char schwierigkeit[7] = "leicht";

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
		printf("\n");

		{
			switch (cMenu)
			{
			case '1':
				//Leicht
				printf("\t\033[4mLeicht\033[0m\n\n");
				//anzeige HallofFame Leicht
				schreibe_hallOfFame(testUser, schwierigkeit, anzahlHilfe, zeit);
				printf("\n\t");
				system("Pause");
				break;

			case '2':
				//Mittel
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
*/

void schreibe_hallOfFame(char testUser, char schwierigkeit, int anzahlHilfe, int zeit) {
	int flag = 0;
	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	if (flag == 0)
	{

		sql = sqlite3_mprintf("INSERT INTO hallOfFame VALUES (NULL, \"Marwin\", \"Leicht\", 3, 25)");

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		if (rc == SQLITE_OK)
		{
			rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
			if (rc == SQLITE_OK)
			{
				sqlite3_close(db_handle);
				printf("\tUser %s erfolgreich in die Hall of Fame eingetragen!\n\n", sUser);
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