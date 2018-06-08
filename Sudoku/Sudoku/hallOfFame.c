/*
================================================
Praeprozessoranweisungen
================================================
*/

#include "include.h"

/*
================================================
Initialisierung der Variablen
================================================
*/

char cMenu = 0;
int iSchleife = 1;
int iError = 0;
int iZeit = 0;
int iAnzahlHilfe;
int iSchwierigkeitsgrad;

/*
================================================
Funktion hallOfFame_menu
================================================
*/

void hallOfFame_menu(void) {
	do
	{
		hallOfFameAnzeige();
		//Auswahl des Menüpunkts bzw. Case auswahl
		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		printf("\n");

		{
			switch (cMenu)
			{
			case '1':
				//Leicht
				//anzeige HallofFame Leicht
				show_hallOfFameL();
				printf("\n\t");
				system("Pause");
				break;

			case '2':
				//Mittel
				//anzeige HallofFame Mittel
				show_hallOfFameM();
				printf("\n\t");
				system("Pause");
				break;

			case '3':
				//Schwer
				//anzeige HallofFame Schwer
				show_hallOfFameS();
				printf("\n\t");
				system("Pause");
				break;

			case 'x':
				// Beenden
				iSchleife = 0;
			}
		}

	} while (iSchleife == 1);
}


void hallOfFameEintragen_menu(void) {
	do
	{
		hallOfFameEintragen();
		//Auswahl des Menüpunkts bzw. Case auswahl
		printf("\tEingabe: ");
		fflush(stdin);
		iError = scanf_s("%c", &cMenu);
		printf("\n");

		{
			switch (cMenu)
			{
			case '1':
				//Ja
				schreibe_hallOfFame(sUser);
				printf("\n\t");
				system("Pause");
				break;

			case 'x':
				// Nein
				iSchleife = 0;
			}
		}

	} while (iSchleife == 1);
}


/*
================================================
Funktion schreibe_hallOfFame
================================================
*/

void schreibe_hallOfFame() {

	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/

	int flag = 0;
	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;
	sqlite3_stmt *stmt;
	char sSchwierigkeitsgrad[] = "       ";

	if (iSchwierigkeitsgrad == 1) {
		sSchwierigkeitsgrad[7] = "Leicht";
	}
	else if(iSchwierigkeitsgrad == 2) {
		sSchwierigkeitsgrad[7] = "Mittel";
	}
	else if (iSchwierigkeitsgrad == 3) {
		sSchwierigkeitsgrad[7] = "Schwer";
	}


	if (flag == 0)
	{
		//SQL statement wird vorbereitet
		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("INSERT INTO hallOfFame VALUES (NULL, \"%s\", \"%s\" ,%i, %i)"
								, sUser, sSchwierigkeitsgrad, iAnzahlHilfe, iZeit);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		if (rc == SQLITE_OK)
		{
			//SQL statement wird ausgeführt
			rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
			if (rc == SQLITE_OK)
			{
				//Datenbank wird geschlossen und eine entsprechende Ausgabe folgt
				sqlite3_close(db_handle);
				printf("\tUser\n\t%s\n\terfolgreich in die Hall of Fame eingetragen!\n\n", sUser);
				return 0;
			}
			else {
				//Bei einem Fehler wird eine entsprechende Fehlermeldung ausgegeben
				printf("\tSQL Fehler: %s\n\n", zErrMsg);
				sqlite3_free(zErrMsg);
				sqlite3_close(db_handle);
				system("\tPause");
				menu();

			}
		}
	}
}

/*
================================================
Funktion show_hallOfFameL()
================================================
*/

void show_hallOfFameL(void) {

	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/

	int flag = 0;
	char *sql;
	char sSchwierigkeit[] = "Leicht";
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

		//SQL statement wird vorbereitet und ausgeführt
		rc = sqlite3_open(DATABASE_FILE, &db_handle);
		
		sql = sqlite3_mprintf("SELECT * FROM hallOfFame WHERE schwierigkeit = '%s' ORDER BY anzahlHilfe ASC LIMIT 10", sSchwierigkeit);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		cols = sqlite3_column_count(stmt);
		printf("\t");
		//Die Spaltennamen der Tabelle werden ausgegeben
		for (col = 0; col < cols; col++) {
			printf("%s\t", (const char*)sqlite3_column_name(stmt, col));
			if (col == 3) {
				printf("\t");
			}
		}
		printf("\n");
		const char *data;

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			//Die Datensätze der Tabelle werden ausgegeben
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

/*
================================================
Funktion show_hallOfFameM()
================================================
*/


void show_hallOfFameM(void) {
	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/
	int flag = 0;
	char *sql;
	char sSchwierigkeit[] = "Mittel";

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
		//SQL statement wird vorbereitet und ausgeführt
		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("SELECT * FROM hallOfFame WHERE schwierigkeit = '%s' ORDER BY zeit ASC LIMIT 10", sSchwierigkeit);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		cols = sqlite3_column_count(stmt);
		printf("\t");
		//Die Spaltennamen der Tabelle werden ausgegeben
		for (col = 0; col < cols; col++) {
			printf("%s\t", (const char*)sqlite3_column_name(stmt, col));
			if (col == 3) {
				printf("\t");
			}
		}
		printf("\n");
		const char *data;

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			//Die Datensätze der Tabelle werden ausgegeben
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

/*
================================================
Funktion show_hallOfFameS()
================================================
*/

void show_hallOfFameS(void) {
	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/
	int flag = 0;
	char *sql;
	char sSchwierigkeit[] = "Schwer";

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
		//SQL statement wird vorbereitet und ausgeführt
		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("SELECT * FROM hallOfFame WHERE schwierigkeit = '%s' ORDER BY zeit ASC LIMIT 10", sSchwierigkeit);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		cols = sqlite3_column_count(stmt);
		printf("\t");
		//Die Spaltennamen der Tabelle werden ausgegeben
		for (col = 0; col < cols; col++) {
			printf("%s\t", (const char*)sqlite3_column_name(stmt, col));
			if (col == 3) {
				printf("\t");
			}
		}
		printf("\n");
		const char *data;

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			//Die Datensätze der Tabelle werden ausgegeben
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

