// Define
#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_SECURE_NO_WARNINGS
#define DATABASE_FILE "sudoku.sqlite3"

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


#include "sqlite3.h"


// Globale Variablen
extern char sUser[26]; // Username
extern int iLoginChange; // Flag ob Benutzer eingeloggt ist
extern int iGrid[9][9]; // main array
extern int iGridCopy[9][9]; // lösungs array
extern int iGridmuster[9][9]; // Array ob feld leer oder gefüllt werden soll
extern int iGridplay[9][9]; // damit Zahlen gefüllt werden
extern int iLoesung; // wenn gelößt
//extern int iAnzahlHilfe; // anzahl der Hilfen

HANDLE  hColor;





// Funktions Prototypen
void sudokuGenShift(void);
void schreibe_hallOfFame(); 
void show_hallOfFameL(void);
void show_hallOfFameM(void);
void show_hallOfFameS(void);
void sudoku_header(void);
int login_user(void);
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
int spielFeldAusgabe(void);
void menu(void);
int main(void);
int randomNumGen(void);
void lösungAnzeigen(void);
void loescheZahlen(void);
void generiereZuLoeschende(void);
