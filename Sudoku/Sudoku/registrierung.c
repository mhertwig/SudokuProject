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
Initialisierung der Variablen
================================================
*/

char sUser[26];
char sPasswort[20];
char sNachname[20];
char sVorname[20];

int flag = 0;

/*
================================================
Funktion register_user
================================================
*/

void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname) {

	/*
	================================================
	Initialisierung der Variablen
	================================================
	*/

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;

	// scan funktion zur Eingabe von Daten wird aufgerufen (username, passwort, nachname, vorname)
	scan(sUser, sPasswort, sNachname, sVorname);
	if (flag == 0)
	{

		//Datenbank wird geöffnet und das SQL statement wird vorbereitet 

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		sql = sqlite3_mprintf("INSERT INTO benutzer VALUES (NULL, %Q, %Q, %Q, %Q, \
				date('now'));", sUser, sPasswort, sNachname, sVorname);

		if (rc == SQLITE_OK)
		{
			// Wenn rc = SQLITE_OK ist, wird das SQL statement ausgeführt
			rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
			if (rc == SQLITE_OK)
			{
				// Wenn rc = SQLITE_OK ist, wird die Datenbank geschlossen und eine entsprechende Ausgabe folgt
				sqlite3_close(db_handle);
				printf("\tUser %s erfolgreich erstellt!\n\n",sUser);
				return 0;
			}
			else {
				// Wenn rc nicht gleich SQLITE_OK ist,
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

	printf("\t\033[4mRegistrierung\033[0m\n\n");

	printf("\tUsername: ");
	scanf("%s", sUser);
	if (*sUser == 'x')
	{
		flag = 1;
		return 0;
	}

	printf("\tPasswort: ");
	scanf("%s", sPasswort);
	if (*sPasswort == 'x')
	{
		flag = 1;
		return 0;
	}

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
	//if (*sNachname == 'x')
	//{
	//	flag = 1;
	//	return 0;
	//}

	printf("\tVorname: ");
	scanf("%s", sVorname);
	//if (*sVorname == 'x')
	//{
	//	flag = 1;
	//	return 0;
	//}
}