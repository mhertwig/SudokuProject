#include "include.h"

// Generates random number
int randomNumGen(void)
{
	unsigned int iNum = rand() % 10;
	if (iNum == 0)
	{
		randomNumGen();
	}
	else
	{
		return iNum;
	}
}



// generates random coordinates (00 - 88) of displayed cells as an integer 
// integer is split as 2 digits later
int PuzzleRandomPicker(void)
{
	unsigned int iNum = rand() % (88 + 0 - 1) + 0;
	return iNum;
}

void sudokuGenShift(void)
{

	//int iGridCopy[9][9]; // copy of generated grid - needed to comparison and solving the puzzle

	int iIndexH = 0; // Horizontal lines / rows of the grid
	int iIndexV = 0; // Vertical lines / columns of the grid
	int iInd; // index for iteration

	int iTmpVal; // for storing generated number until it's validated and assign to a grid
	int iMatches = 0;


	// Gives rand() function starting point
	srand(time(0));

	// Generates and assigns the numbers to all 9 elements of the first column
	while (iIndexH < 9)
	{
		// Generating a number 
		iTmpVal = randomNumGen();

		// Giving the first element a value without checking
		if (iIndexH == 0)
		{
			iGrid[0][0] = iTmpVal;
		}
		else
		{
			// checks if the number already exists in an array
			for (iInd = 0; iInd <= iIndexH; iInd++)
			{
				if (iGrid[0][iInd] == iTmpVal)
				{
					iMatches = 1;
				}
			}
		}

		// if after an existance check a match is not found, 
		// assigns a generated number to the next element of an array 
		// and increments iIndexV for next iteration
		if (iMatches == 0)
		{
			iGrid[0][iIndexH] = iTmpVal;
			iIndexH++;
		}
		else
		{
			// set the variable iMatch to Zero for the next iteration
			iMatches = 0;
		}

	}

	//printf("%i\n\n", iIndexH);


	// filling rows
	/*
	Sudoku board is generated with the following logic:
	first row is filled with random unique numbers from 1 to 9
	2nd row - first row is shifted left by 3 steps
	3rd row - second row is shifted by 3 steps
	4th row - third row is shifted by 1 step
	5rd row - fourth row is shifted by 3 steps
	6rd row - fifth row is shifted by 3 steps
	7th row - sixth row is shifted by 1 step
	8rd row - seventh row is shifted by 3 steps
	9rd row - eightht row is shifted by 3 steps
	*/

	for (iIndexV = 1; iIndexV < 9; iIndexV++)
	{
		int iStep = 3; // steps to shift
		int iRowIndex;

		//fourth and seventh row are shifted by one step
		if (iIndexV == 3 || iIndexV == 6)
		{
			iStep = 1;
		}

		for (iRowIndex = 0; iRowIndex < 9; iRowIndex++)
		{
			// if the row is shifted by 3 steps, the values of last three element 
			// are first three elements of the previous row 
			if (iStep == 3 && (iRowIndex == 6 || iRowIndex == 7 || iRowIndex == 8))
			{
				iGrid[iIndexV][iRowIndex] = iGrid[iIndexV - 1][iRowIndex - 6];
			}
			// if the row is shifted by 1 steps, the values of last element 
			// is the value of first element of the previous row 
			else if (iStep == 1 && iRowIndex == 8)
			{
				iGrid[iIndexV][iRowIndex] = iGrid[iIndexV - 1][0];
			}
			// shifting the row
			else
			{
				iGrid[iIndexV][iRowIndex] = iGrid[iIndexV - 1][iRowIndex + iStep];
			}
		}
	}


	// coping the board into iGridCopy
	for (iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			iGridCopy[iIndexV][iIndexH] = iGrid[iIndexV][iIndexH];
		}
	}



	int iRow;
	int iCol;
	int iCellCount = 0;
	int iLevel36[37];
	int iIndexPicked;
	int iTmpHolder;
	int iChecking;
	int iDuplicated = 0;

	// 36 Numbers
	while (iCellCount < 36)
	{
		iTmpHolder = PuzzleRandomPicker();
		iDuplicated = 0;
		for (iIndexPicked = 1; iIndexPicked <= 36; iIndexPicked++)
		{
			if (iLevel36[iIndexPicked] == iTmpHolder)
			{
				iDuplicated = 1;
			}
		}

		// if there are no duplicated values, assigns the generated number to an array 
		//and increments index for next iteration
		if (iDuplicated == 0)
		{
			iLevel36[iCellCount] = iTmpHolder;
			iCellCount++;
		}
	}


	//printf("iGridCopy start \n");

	//for (iIndexV = 0; iIndexV < 9; iIndexV++)
	//{
	//	for (iIndexH = 0; iIndexH < 9; iIndexH++)
	//	{
	//		printf("%d . ", iGridCopy[iIndexV][iIndexH]);
	//	}
	//	printf("\n");
	//}
	//printf("iGridCopy  end \n");


	//Array Ausgabe zum testen

	//printf("\n");

	//for (iIndexV = 0; iIndexV < 9; iIndexV++)
	//{
	//	for (iIndexH = 0; iIndexH < 9; iIndexH++)
	//	{
	//		printf("%d . ", iGrid[iIndexV][iIndexH]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");


	loescheZahlen();

}

//Zahlen werden nach dem Schema iGridmuster1 gelöscht
void loescheZahlen(void)
{
	int iGridmuster1[9][9] = { 1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,0,0,1,1,0 };
	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			if (iGridmuster1[iIndexV][iIndexH] == 0)
			{
				iGrid[iIndexV][iIndexH] = NULL;
			}
		}
	}
}

