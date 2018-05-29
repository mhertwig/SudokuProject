/*
================================================
Praeprozessoranweisungen
================================================
*/

#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100


#define DATABASE_FILE "spiele.sqlite3"
/*
================================================
Funktionsprototypen
================================================
*/

int login_user();

/*
================================================
Funktion login_user
================================================
*/

int login_user() {
	char spielername[MAX];
	char passwort[MAX];

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
		printf("Spielername:");
		fflush(stdin);
		scanf("%s", spielername);

		printf("Passwort:");
		fflush(stdin);
		scanf("%s", passwort);

		/*
		================================================
		Decrypt (Passwort wird entschlüsselt)
		================================================
		*/
		char keyToEncrypt = 's';
		int pwLaenge = strlen(passwort);

		for (int temp = 0; temp < pwLaenge; temp++) {
			passwort[temp] ^= keyToEncrypt;
		}



		sql = sqlite3_mprintf("SELECT spielername FROM benutzer WHERE spielername = '%s'", spielername);

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		col = sqlite3_column_count(stmt);

		if (sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -1;
			sqlite3_close(db_handle);
		}

		sql = sqlite3_mprintf("SELECT passwort FROM benutzer WHERE spielername = '%s' AND passwort = '%s'", spielername, passwort);

		rc = sqlite3_open(DATABASE_FILE, &db_handle);

		rc = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

		col = sqlite3_column_count(stmt);

		if (flag != -1 && sqlite3_step(stmt) != SQLITE_ROW) {
			flag = -2;
			sqlite3_close(db_handle);
		}

		if (flag == 0) {
			sql = sqlite3_mprintf("SELECT user_id,spielername FROM benutzer WHERE spielername = '%s'", spielername);

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
				printf("Falscher Benutzername!\n");
			}
			if (flag == -2) {
				printf("Falsches Passwort!\n");
			}

		}

	} while (flag < 0);
	printf("Erfolgreich eingeloggt!\n");
	return flag;
}