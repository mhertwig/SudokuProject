#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>


#include "sqlite3.h"

// Globale Variablen
extern int iLoginChange;
extern char sUser[26];

extern int iGrid[9][9]; // main array 



#define DATABASE_FILE "sudoku.sqlite3"

//test
//Funktions Prototypen

void sudoku_header(void);
char login_user(void);
char logout_user();
void register_user(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void scan(char *sUser, char *sPasswort, char *sNachname, char *sVorname);
void spiel(void);
void sudokuGenerator(void);
int checkRows(int *pGrid[9][9], int *pTmpVal);
int randomNum(void);
void menu(void);
int main(void);
void schreibe_hallOfFame(char *sUser, int anzahlHilfe, double zeit, char schwierigkeit);