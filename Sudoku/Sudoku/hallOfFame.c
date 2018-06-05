#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"


int cMenu = 0;
int schleife = 1;
int iError = 0;

char sUser[26];

char testUser[] = "Marwin";
int anzahlHilfe = 1;
int zeit = 20;
char sSchwierigkeit[] = "Mittel";

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
				schreibe_hallOfFame(testUser, sSchwierigkeit, anzahlHilfe, zeit);
				printf("\n\t");
				system("Pause");
				break;

			case '2':
				//Mittel
				printf("\t\033[4mMittel\033[0m\n\n");
				//anzeige HallofFame Mittel
				show_hallOfFame();
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

void schreibe_hallOfFame(char testUser, char sSchwierigkeit, int anzahlHilfe, int zeit) {
	int flag = 0;
	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	if (flag == 0)
	{
		sql = sqlite3_mprintf("INSERT INTO hallOfFame VALUES (NULL, \"TESt\", \"Leicht\", %i, %i)", anzahlHilfe, zeit);

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


void show_hallOfFame(void) {
	int flag = 0;
	char *sql;
	sqlite3_stmt *stmt;

	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;
	int cols;
	int col;

	if (flag == 0)
	{
		system("cls");
		sudoku_header();
		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("SELECT * FROM hallOfFame WHERE schwierigkeit = '%s' ORDER BY zeit ASC LIMIT 10", sSchwierigkeit);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		cols = sqlite3_column_count(stmt);
		printf("\t");
		for (col = 0; col < cols; col++) {
			printf("%s\t", (const char*)sqlite3_column_name(stmt, col));
		}
		printf("\n");
		const char *data;

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			for (col = 0; col < cols; col++) {
				data = (const char*)sqlite3_column_text(stmt, col);
				printf("\t");
				printf("%s\t", data ? data : "NULL");
			}
			printf("\n");
		}

		sqlite3_free(sql);
		sqlite3_finalize(stmt);
	}
}