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

int menu()
{
	int imenu;
	int iError = 0;

	do
	{
		printf("(1)Login\n");
		printf("(2)Benutzer anlegen\n\n");
		fflush(stdin);
		iError = scanf("%i", &imenu);
	} while (iError == 0 || imenu < 1 || imenu > 2);

	printf("\n");
	return imenu;
}

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


	// Open
	//rc = sqlite3_open(DATABASE_FILE, &db_handle);

	/* SQL Statement erstellen */
	//sql = sqlite3_mprintf("SELECT spielername,passwort from benutzer WHERE spielername = '%s' AND passwort = '%s'", spielername, passwort);

	/* SQL Statement ausf�hren */
	//rc = sqlite3_exec(db_handle, sql, NULL, NULL, &zErrMsg);

	/* Returncode pr�fen */
	/*if (rc != SQLITE_OK) {
	printf("SQL Fehler: %s\n", zErrMsg);
	sqlite3_free(zErrMsg);
	sqlite3_close(db_handle);
	return -3;
	}
	else {

	// SQL String vorbereiten und Speicher reservieren
	sql = sqlite3_mprintf("SELECT user_id, spielername, passwort FROM benutzer WHERE spielername= '%s'; ", spielername);

	// SQL Statement und Struktur erzeugen
	rc = sqlite3_prepare_v2(db_handle,sql,strlen(sql), &stmt, NULL);

	// Anzahl der Spalten in der Ergebnismenge ermitteln
	cols = sqlite3_column_count(stmt);

	if(sqlite3_step(stmt) == SQLITE_ROW)
	{

	data = (const char*)sqlite3_column_text(stmt, 2);

	if(strcmp(data,passwort) == 0)
	{
	user = sqlite3_column_int(stmt, 0);
	sqlite3_free(sql);
	sqlite3_finalize(stmt);
	return user;
	}
	else
	{
	sqlite3_free(sql);
	sqlite3_finalize(stmt);
	return -2;
	}

	}
	sqlite3_free(sql);
	sqlite3_finalize(stmt);
	return -1;


	// callback
	//const char* data = sqlite3_mprintf("SELECT user_id FROM benutzer WHERE spielername = '%s' AND passwort = '%s'", spielername, passwort);
	//rc = sqlite3_exec(db_handle, sql, callback, (void*)data, &zErrMsg);
	}*/

}

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
	int imenu;
	int ilogin;

	imenu = menu();
	if (imenu == 1)
	{
		// Starte login
		ilogin = login();

		// Gebe Loginreturn aus
		//printf("Return = %i\n", ilogin);
		printf("\nSpielername oder Passwort stimmen nicht ueberein!\n\n");
	}
	else
	{
		register_user();
	}


	system("Pause");
}



