
void openFile(void)
{
	// opens a pdf file
	char file[100] = "/sudoku-anleitung.pdf";
	ShellExecute(NULL, NULL, file, NULL, NULL, SW_SHOW);

	//return 0;
}