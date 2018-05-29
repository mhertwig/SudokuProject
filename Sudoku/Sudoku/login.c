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
Funktion login_user
================================================
*/

void login_user(void) {
	char sUser[26];
	char sPasswort[20];

	char *sql;
	char *zErrMsg;
	sqlite3 *db_handle;
	int rc;
	sqlite3_stmt *stmt;
	int col;
	int *data;

	int flag = 0;
	do {
		flag = 0;
		printf("\tSpielername: ");
		fflush(stdin);
		scanf("%s", sUser);

		printf("\tPasswort: ");
		fflush(stdin);
		scanf("%s", sPasswort);

		/*
		================================================
		Decrypt (Passwort wird entschl�sselt)
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

		if (sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -1;
			sqlite3_close(db_handle);
		}

		sql = sqlite3_mprintf("SELECT sPasswort FROM benutzer WHERE sUser = '%s' AND sPasswort = '%s'", sUser, sPasswort);

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		col = sqlite3_column_count(stmt);

		if (flag != -1 && sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -2;
			sqlite3_close(db_handle);
		}

		if (flag == 0) {
			sql = sqlite3_mprintf("SELECT user_id, user FROM benutzer WHERE user = '%s'", sUser);

			rc = sqlite3_open(DATABASE_FILE, &db_handle);

			rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

			col = sqlite3_column_count(stmt);

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int data = sqlite3_column_int(stmt, 0);
				int flag = data;
			}
		}
		if (flag < 0) {
			if (flag == -1) {
				printf("\tFalscher Benutzername!\n");
			}
			if (flag == -2) {
				printf("\tFalsches Passwort!\n");
			}

		}

	} while (flag < 0);
	printf("\tErfolgreich eingeloggt!\n");

	//menu();
	//return flag;
}