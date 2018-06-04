#include "include.h"



void spiel(void) {

	sudokuGenShift();

	system("cls");

	sudoku_header();
	layout();

	system("\t");
	system("Pause");

}