﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


#include "sqlite3.h"


// Globale Variablen
extern char sName[26];



#define DATABASE_FILE "spiele.sqlite3"


//Funktions Prototypen
void sudoku_header(void);
char login_user(void);
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void menu(void);







