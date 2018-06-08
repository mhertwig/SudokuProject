#include "include.h"

// Generates random number from 1 to 9
int randomNumGen(void)
{
	unsigned int iNum;

	iNum = rand() % 10;

	if (iNum == 0)
	{
		randomNumGen();
	}
	else
	{
		return iNum;
	}
}


// generates sudoku board
void sudokuGenShift(void)
{

	int iIndexH = 0; // Horizontal lines / rows of the grid
	int iIndexV = 0; // Vertical lines / columns of the grid
	int iInd; // index for iteration

	int iTmpVal; // for storing generated number until it's validated and assign to a grid
	int iMatches = 0;

	int iStep = 3; // steps to shift
	int iRowIndex;


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


	// filling rows
	/*
	Sudoku board is generated through the following logic:
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
			// shifting the rows
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

	
	// Generiere Array mit 0 und 1
	generiereZuLoeschende();
	// setzte Zahlen und NULL in Array
	loescheZahlen();

}

// Generiere das Array iGridmuster mit den Werten 0 und 1
void generiereZuLoeschende(void)
{
	int iRandom;

	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			if(iSchwierigkeitsgrad == 1)
			{ 
				// Generiere Array mit entweder 1 oder 0
				iRandom = rand() % 2;
				if (rand() % 100 < 30) // 30% Wahrscheinlichkeit werden gelöscht
				{
					iGridmuster[iIndexV][iIndexH] = 0;
				}
				else
				{
					iGridmuster[iIndexV][iIndexH] = 1;
				}
			}
			else if (iSchwierigkeitsgrad == 2)
			{ // Generiere Array mit entweder 1 oder 0
				iRandom = rand() % 2;
				if (rand() % 100 < 45) // 45% Wahrscheinlichkeit werden gelöscht
				{
					iGridmuster[iIndexV][iIndexH] = 0;
				}
				else
				{
					iGridmuster[iIndexV][iIndexH] = 1;
				}
			}
			else if (iSchwierigkeitsgrad == 3)
			{ // Generiere Array mit entweder 1 oder 0
				iRandom = rand() % 2;
				if (rand() % 100 < 70) // 70% Wahrscheinlichkeit werden gelöscht
				{
					iGridmuster[iIndexV][iIndexH] = 0;
				}
				else
				{
					iGridmuster[iIndexV][iIndexH] = 1;
				}
			}
			else if (iSchwierigkeitsgrad == 4)
			{ // Generiere Array mit entweder 1 oder 0
				iRandom = rand() % 2;
				if (rand() % 100 < 2) // 70% Wahrscheinlichkeit werden gelöscht
				{
					iGridmuster[iIndexV][iIndexH] = 0;
				}
				else
				{
					iGridmuster[iIndexV][iIndexH] = 1;
				}
			}
			
			
			

		}

	}

}

// Setze in iGrid an den Positionen, in der in iGridmuster eine 0 ist auf NULL
// Ansonsten setze die Zahl aus dem Lösungs Sudoku
void loescheZahlen(void)
{
	for (int iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (int iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			if (iGridmuster[iIndexV][iIndexH] == 0)
			{
				iGrid[iIndexV][iIndexH] = NULL;
			}
			else
			{
				iGrid[iIndexV][iIndexH] = iGridCopy[iIndexV][iIndexH];
			}
			iGridplay[iIndexV][iIndexH] = iGridmuster[iIndexV][iIndexH];
		}
	}
}

