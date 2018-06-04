#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


#include "sqlite3.h"


// Globale Variablen
char sUser[26];
int iLoginChange;



#define DATABASE_FILE "sudoku.sqlite3"


//Funktions Prototypen

void spiel(void);
void sudoku_header(void);
char login_user(void);
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void spiel(void);
void menu(void);
int main(void);
void schreibe_hallOfFame(char *sUser, int anzahlHilfe, double zeit, char schwierigkeit);