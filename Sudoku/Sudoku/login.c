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
Funktion login_user
================================================
*/

char login_user() {

	char sPasswort[20];

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;
	sqlite3_stmt *stmt;
	int col;
	int *data;

	iLoginChange = 0;
	
	int flag = 0;
	do {

		printf("\t\033[4mLogin\033[0m\n\n");

		flag = 0;
		printf("\tSpielername: ");
		fflush(stdin);
		scanf("%s", sUser);
		if (*sUser == 'x')
		{
			return 0;
		}

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


		sql = sqlite3_mprintf("SELECT user FROM benutzer WHERE user = '%s'", sUser);

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		col = sqlite3_column_count(stmt);

		sqlite3_close(db_handle);
		

		if (sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -1;
		}

		sql = sqlite3_mprintf("SELECT passwort FROM benutzer WHERE user = '%s' AND passwort = '%s'", sUser, sPasswort);

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		col = sqlite3_column_count(stmt);

		sqlite3_close(db_handle);

		if (flag != -1 && sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -2;
		}

		if (flag == 0) {
			sql = sqlite3_mprintf("SELECT user_id, user FROM benutzer WHERE user = '%s'", sUser);

			rc = sqlite3_open(DATABASE_FILE, &db_handle);

			rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

			col = sqlite3_column_count(stmt);

			sqlite3_close(db_handle);

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int data = sqlite3_column_int(stmt, 0);
				int flag = data;
			}
			
			sqlite3_free(sql);
			sqlite3_finalize(stmt);
			sqlite3_close(db_handle);
		}
		if (flag < 0) {
			if (flag == -1) {
				printf("\tFalscher Benutzername!\n\n");
			}
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

char logout_user() {

	sUser[26] = "                          ";
	iLoginChange = 0;
}