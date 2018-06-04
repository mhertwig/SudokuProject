#include "include.h"

// Generates random number
int randomNum(void)
{
	unsigned int iNum = rand() % 10;
	if (iNum == 0)
	{
		randomNum();
	}
	else
	{
		return iNum;
	}

}

int checkRows(int *pGrid[9][9], int *pTmpVal) {
	int iIndexH = 0;
	int iIndexV = 0;
	for (iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			printf("%d . ", *pGrid[iIndexV][iIndexH]);
		}
		printf("\n");
	}
}

void sudokuGenerator(void)
{
	

	int iIndexH = 0; // Horizontal lines / rows of the grid
	int iIndexV = 0; // Vertical lines / columns of the grid
	int iInd; // index for iteration
	int iIndV;

	int iTmpVal; // for storing generated number until it's validated and assign to a grid
	int iMatches = 0;
	int iMatches2 = 0;
	int valCount = 0;

	// Gives rand() function starting point
	srand(time(0));

	// Generates and assign the numbers to all 9 elements of the first column
	while (iIndexV < 9)
	{
		// Generating a number 
		iTmpVal = randomNum();

		// Giving the first occurance a value without checking
		if (iIndexV == 0)
		{
			iGrid[0][0] = iTmpVal;
		}
		else
		{
			// checking if the number already is in an array
			for (iInd = 0; iInd <= iIndexV; iInd++)
			{
				if (iGrid[iInd][0] == iTmpVal)
				{
					iMatches = 1;
				}
			}
			// end if single check / one loop of array elements

		}

		// if after an existance check a match is not found, 
		// assigns a generated number to the next element of an array 
		// and increments iIndexV for next iteration
		if (iMatches == 0)
		{
			iGrid[iIndexV][0] = iTmpVal;
			iIndexV++;
		}
		else
		{
			// set the variable iMatch to Zero for the next iteration
			iMatches = 0;
		}

	}

	//printf("%i\n\n", iIndexH);

	for (iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		printf("%d\n", iGrid[iIndexV][0]);
	}

	// filling the remaining cells of the grid with numbers 
	for (iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		iIndexH = 1;

		while (iIndexH < 9)
		{
			iTmpVal = randomNum();

			for (iInd = 0; iInd <= iIndexH; iInd++)
			{
				//printf("iGrid[%d][%d] - %d\n", iIndexV, iInd, iTmpVal);
				if (iGrid[iIndexV][iInd] == iTmpVal)
				{
					iMatches2 = 1;
					break;
				}
			}

			// ??????
			//printf("iGrid[%d][%d] - %d\n", iIndexV, iIndexH, iTmpVal);
			if (iMatches2 == 0)
			{
				for (iIndV = 0; iIndV <= iIndexV; iIndV++)
				{
					//printf("iGrid[%d][%d] - %d - %d \n", iIndV, iIndexH, iTmpVal, iIndexV);

					if (iGrid[iIndV][iIndexH] == iTmpVal)
					{
						//printf("iGrid[%d][%d] - %d - %d \n", iIndV, iIndexH, iTmpVal, iIndexV);
						iMatches2 = 1;  // etwas stimmt hier nicht
						break;
					}
				}
			}


			printf("\n\n iMatches2 = %d\n\n", iMatches2);

			if (iMatches2 == 0)
			{
				iGrid[iIndexV][iIndexH] = iTmpVal;
				//printf("iGrid[%d][%d] = %d\n", iIndexV, iIndexH, iGrid[iIndexV][iIndexH]);
				iIndexH++;
			}
			else
			{
				iMatches2 = 0;
			}
		}
		//printf("\n------- end of row iteration ----------- \n");
		printf("\n");
	}


	printf("\n");

	for (iIndexV = 0; iIndexV < 9; iIndexV++)
	{
		for (iIndexH = 0; iIndexH < 9; iIndexH++)
		{
			printf("%d . ", iGrid[iIndexV][iIndexH]);
		}
		printf("\n");
	}
	printf("\n");

}

