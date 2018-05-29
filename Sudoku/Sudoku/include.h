#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "sqlite3.h"
//#include "Sudoku_header.h"




#define DATABASE_FILE "spiele.sqlite3"


//Funktions Prototypen
void sudoku_header(void);
void login_user(void);
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void menu(void);







