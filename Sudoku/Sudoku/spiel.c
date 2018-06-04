#include "include.h"



void spiel(void) {

	sudokuGenerator();

	system("cls");

	sudoku_header();
	layout();

	system("\t");
	system("Pause");

}