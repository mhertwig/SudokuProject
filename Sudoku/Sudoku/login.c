/*
================================================
Praeprozessoranweisungen
================================================
*/

#include "include.h"


/*
================================================
Funktion login_user
================================================
*/

int login_user(void) {
	
	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/

	char sPasswort[20];
	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int iRc;
	sqlite3_stmt *stmt;
	int iCol;
	int *data;
	iLoginChange = 0;
	int flag = 0;

	do {

		printf("\t\033[4mLogin\033[0m\n\n");
		//Eingabe des Spielernamens
		flag = 0;
		printf("\tSpielername: ");
		fflush(stdin);
		scanf("%s", sUser);
		if (*sUser == 'x')
		{
			return 0;
		}
		//Eingabe des Passworts
		printf("\tPasswort: ");
		fflush(stdin);
		scanf("%s", sPasswort);
		if (*sPasswort == 'x')
		{
			return 0;
		}

		/*
		================================================
		Decrypt (Passwort wird entschlüsselt)
		================================================
		*/
		char keyToEncrypt = 's';
		int pwLaenge = strlen(sPasswort);

		for (int temp = 0; temp < pwLaenge; temp++) {
			sPasswort[temp] ^= keyToEncrypt;
		}

		//SQL statement wird vorbereitet und ausgeführt und die Datenbank geöffnet bzw geschlossen
		//Das statement wählt den User aus der Datenbank welcher der Eingabe entspricht
		iRc = sqlite3_open(DATABASE_FILE, &db_handle);
		
		sql = sqlite3_mprintf("SELECT user FROM benutzer WHERE user = '%s'", sUser);

		iRc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		iCol = sqlite3_column_count(stmt);
		


		if (sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -1;
		}
		sqlite3_finalize(stmt);
		sqlite3_close(db_handle);

		//SQL statement wird vorbereitet und ausgeführt und die Datenbank geöffnet bzw geschlossen
		//Das statement wählt das Passwort aus der Datenbank welcher der Eingabe entspricht und zu dem User gehört
		iRc = sqlite3_open(DATABASE_FILE, &db_handle);
		
		sql = sqlite3_mprintf("SELECT passwort FROM benutzer WHERE user = '%s' AND passwort = '%s'", sUser, sPasswort);


		iRc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		iCol = sqlite3_column_count(stmt);

		if (flag != -1 && sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -2;
		}
		sqlite3_finalize(stmt);
		sqlite3_close(db_handle);

		if (flag == 0) {
			//SQL statement wird vorbereitet und ausgeführt und die Datenbank geöffnet bzw geschlossen
			//Das statement wählt den User aus der Datenbank welcher der Eingabe entspricht
			iRc = sqlite3_open(DATABASE_FILE, &db_handle);

			sql = sqlite3_mprintf("SELECT user_id, user FROM benutzer WHERE user = '%s'", sUser);

			iRc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

			iCol = sqlite3_column_count(stmt);

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int data = sqlite3_column_int(stmt, 0);
				int flag = data;
			}
			sqlite3_finalize(stmt);
			sqlite3_close(db_handle);
		}
		if (flag < 0) {
			//Fehlermeldung bei einem falschen Benutzernamen
			if (flag == -1) {
				printf("\tFalscher Benutzername!\n\n");
			}
			//Fehlermeldung bei einem falschen Passwort
			if (flag == -2) {
				printf("\tFalsches Passwort!\n\n");
			}
			menuAnzeige();		
		}
	} while (flag < 0);
	printf("\tErfolgreich eingeloggt!\n\n");

	for (int i = 0; i < 25; i++)
	{
		if (sUser[i] == NULL)
		{
			sUser[i] = ' ';
		}
	}
		iLoginChange = 1;
	return sUser;
}

	char logout_user(void) {
		sUser[26] = "                          ";
		iLoginChange = 0;
	}