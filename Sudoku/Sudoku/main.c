/*
Programmname:
Erstellungs-Datum:
Autor:
Beschreibung:
Compiler: 			VS12
*/

#define _CRT_SECURE_NO_WARNINGS

// Include
#include "include.h"
//#include "sqlite3.h"



#define DATABASE_FILE "spiele.sqlite3"
#define MAX 50



static int callback(void *data, int argc, char **argv, char **colName)
{
	int i;
	printf("\n");
	printf("%s: ", (const char*)data);
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int login()
{
	char *sql;
	char *zErrMsg;
	char spielername[MAX], passwort[MAX];
	//sqlite3 *db_handle;
	int rc;
	int user_id;
	const char* data;
	//sqlite3_stmt *stmt; // SQL Statement Struktur
	int cols;
	int user;



	/*do
	{*/
	printf("Spielername: ");
	scanf("%s", spielername);
	printf("Passwort: ");
	scanf("%s", passwort);


	



int register_user(void)
{
	// Lokale Definition
	char *sql;
	char *zErrMsg;
	int i;

	char spielername[MAX],
		passwort[MAX],
		nachname[MAX],
		vorname[MAX];

	// Scanf
	printf("Spielername: ");
	scanf("%s", spielername);
	printf("Passwort: ");
	scanf("%s", passwort);
	printf("Nachname: ");
	scanf("%s", nachname);
	printf("Vorname: ");
	scanf("%s", vorname);

	// Open
	/*sqlite3 *db_handle;
	int rc;
	rc = sqlite3_open(DATABASE_FILE, &db_handle);

	/* SQL Statement erstellen
	sql = sqlite3_mprintf("INSERT into benutzer (spielername,passwort,nachname,vorname, anmeldedatum) VALUES ('%s','%s','%s','%s', date('now'));", spielername, passwort, nachname, vorname);
	/* SQL Statement ausf�hren
	rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);
	/* Returncode pr�fen
	if (rc != SQLITE_OK) {
	printf("SQL Fehler: %s\n", zErrMsg);
	sqlite3_free(zErrMsg);
	sqlite3_close(db_handle);
	}
	else {
	*/
	//printf("\nSpielername ist schon vergeben!\n");
	//printf("Bitte versuchen Sie es erneut!\n");
	printf("\n");
	printf("Datensatz Erfolgreich erstellt!\n");
	printf("\n");

	register_user();

	// Ausgabe
	//const char* data = "Callback Funktion aufgerufen.";
	//sql = "SELECT * from benutzer";
	//rc = sqlite3_exec(db_handle, sql, callback, (void*)data, &zErrMsg);
}

//Exit
//sqlite3_close(db_handle);

//}

int main(void)
{
	


	system("Pause");
}



