/*
================================================
Praeprozessoranweisungen
================================================
*/

#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"
#define DATABASE_FILE "spiele.sqlite3"
/*
================================================
Funktionsprototypen
================================================
*/
int register_user(char *spielername, char *passwort, char *nachname, char *vorname);
void scan(char *spielername, char *passwort, char *nachname, char *vorname);

/*
================================================
Variablen
================================================
*/

		char spielername[20];
		char passwort[10];
		char nachname[20];
		char vorname[20];
/*
================================================
Funktion register_user
================================================
*/

int register_user(char *spielername, char *passwort, char *nachname, char *vorname) {

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	scan(spielername, passwort, nachname, vorname);

	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	sql = sqlite3_mprintf("INSERT INTO benutzer VALUES (NULL, %Q, %Q, %Q, %Q, \
				date('now'));", spielername, passwort, nachname, vorname);

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
		if (rc == SQLITE_OK)
		{
			sqlite3_close(db_handle);
			printf("User erfolgreich erstellt!\n\n\n\n\n");
			return 0;
		}
		else {
			printf("SQL Fehler: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(db_handle);
			system("Pause");
			exit(-1);
		}
	}
}

void scan(char *spielername, char *passwort, char *nachname, char *vorname) {

	printf("Spielername:");
	scanf("%s", spielername);

	printf("Passwort:");
	scanf("%s", passwort);

	/*
	================================================
	Encrypt (Passwort wird verschlüsselt und gespeichert)
	================================================
	*/
	char keyToEncrypt = 's';
	int pwLaenge = strlen(passwort);

	for (int temp = 0; temp < pwLaenge; temp++) {
		passwort[temp] ^= keyToEncrypt;
	}



	printf("Nachname:");
	scanf("%s", nachname);

	printf("Vorname:");
	scanf("%s", vorname);
}