/*
================================================
Praeprozessoranweisungen
================================================
*/
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#include "include.h"
/*
================================================
Funktionsprototypen
================================================
*/


/*
================================================
Variablen
================================================
*/

char sUser[20];
char sPasswort[20];
char sNachname[20];
char sVorname[20];
/*
================================================
Funktion register_user
================================================
*/

void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname) {

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	scan(sUser, sPasswort, sNachname, sVorname);

	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	sql = sqlite3_mprintf("INSERT INTO benutzer VALUES (NULL, %Q, %Q, %Q, %Q, \
				date('now'));", sUser, sPasswort, sNachname, sVorname);

	if (rc == SQLITE_OK)
	{
		rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
		if (rc == SQLITE_OK)
		{
			sqlite3_close(db_handle);
			printf("\tUser erfolgreich erstellt!\n\n\n\n\n");
			return 0;
		}
		else {
			printf("SQL Fehler: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			sqlite3_close(db_handle);
			menu();
			/*system("Pause");
			exit(-1);*/
		}
	}
}

void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname) {

	printf("\tUsername: ");
	scanf("%s", sUser);

	printf("\tPasswort: ");
	scanf("%s", sPasswort);

	/*
	================================================
	Encrypt (Passwort wird verschlüsselt und gespeichert)
	================================================
	*/
	char keyToEncrypt = 's';
	int pwLaenge = strlen(sPasswort);

	for (int temp = 0; temp < pwLaenge; temp++) {
		sPasswort[temp] ^= keyToEncrypt;
	}



	printf("\tNachname: ");
	scanf("%s", sNachname);

	printf("\tVorname: ");
	scanf("%s", sVorname);
}