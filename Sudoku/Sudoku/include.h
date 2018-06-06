#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


#include "sqlite3.h"


// Globale Variablen
char sUser[26]; // Username
int iLoginChange; // Flag ob Benutzer eingeloggt ist
extern int iGrid[9][9]; // main array
extern int iGridCopy[9][9]; // lösungs array
extern int iGridmuster[9][9]; // Array ob feld leer oder gefüllt werden soll

// Define
#define DATABASE_FILE "sudoku.sqlite3"


// Funktions Prototypen
void sudokuGenShift(void);
void schreibe_hallOfFame(); 
void show_hallOfFameL(void);
void show_hallOfFameM(void);
void show_hallOfFameS(void);
void sudoku_header(void);
char login_user(void);
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
int spielFeldAusgabe(void);
void menu(void);
int main(void);
int randomNumGen(void);
void lösungAnzeigen(void);
void loescheZahlen(void);
void generiereZuLoeschende(void);
