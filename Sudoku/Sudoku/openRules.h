#include <stdio.h>;
#include <stdlib.h>;
#include "windows.h";

void openFile(void)
{
	// opens a pdf file
	char file[100] = "C://Users/iaBag/source/repos/SudokuProject/Sudoku/Sudoku/resouces/pdf.pdf";
	ShellExecute(NULL, NULL, file, NULL, NULL, SW_SHOW);

	return 0;
}