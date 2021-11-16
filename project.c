/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Include your information here - name, user name, ID number >> */
//Name: Raymond Li
//User name: rli560
// ID number: 275427240
#include "project.h"

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeWorked = 0;
	int timeWorkedA = ((minuteA * 60) + secondA);
	int timeWorkedB = ((minuteB * 60) + secondB);
	//Check if time worked A is greater than time worked B
	if (timeWorkedA > timeWorkedB)
	{
		timeWorked = timeWorkedA - timeWorkedB;
	}
	// Check if time worked B is greater than time worked A
	else if (timeWorkedB > timeWorkedA)
	{
		timeWorked = timeWorkedB - timeWorkedA;
	}
	return timeWorked;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WarehouseAddress(int maximum)
{
	int number = 0;
	int primeNumber = 0;
	// For loop to check every number up til the maximum values input
	for (int index = (maximum - 1); index >= 2; index--)
	{
		number = 0;
		// For loop to check if the number is a prime number or not
		for (int j = 2; j < index; j++)
		{
			if (index % j == 0)
			{
				number = index;
			}
		}
		if (number == 0)
		{
			primeNumber = index;
			return primeNumber;
		}
	}
	return primeNumber;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void Advertise(char *words)
{
	int counter = 0;
	// While loop to find how many characters in array!
	while (words[counter] != '\0')
	{
		counter++;
	}
	char MyArray = words[0];
	// For loop to rearrange characters.
	for (int index = 0; index < counter; index++)
	{
		words[index] = words[index + 1];
	}
	words[counter - 1] = MyArray;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WinningBid(int *values, int length)
{
	// Scans through the array to pick out the least repeated element in an array
	// If the second index is equal to the first index current number increases
	int found = 0;
	int smallestNumber = 10000;
	// Compare each values
	for (int index = 0; index < length; index++)
	{
		for (int j = 0; j < length; j++)
		{
			if (index != j)
			{
				if (values[index] == values[j])
				{
					found = 1;
				}
			}
		}
		// Find the lowest values
		if (!found)
		{
			if (values[index] < smallestNumber)
			{
				smallestNumber = values[index];
			}
		}
		found = 0;
	}
	return smallestNumber;
}
/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height)
{
	//For loop to make empty spaces
	for (int index = 0; index < height; index++)
	{
		for (int j = 0; j <= (width); j++)
		{
			design[((width + 1) * index) + j] = ' ';
			design[(width + 1) * index] = '\n';
			//Setting the border to *
			if (index == 0 || index == (height - 1) || j == 1 || j == (width))
			{
				design[((width + 1) * index) + j] = '*';
			}
		}
	}
	//Place the crosses into the 1D array
	//Both width and height are odd values
	if (width % 2 != 0 && height % 2 != 0)
	{
		design[((width + 1) * (height / 2)) + ((width + 1) / 2)] = 'X';
	}
	// Both width and height are even values
	if (width % 2 == 0 && height % 2 == 0)
	{
		if (width != 2 && height != 2)
		{
			// Cross on the top right hand corner
			design[((width) * (height / 2))] = 'X';
			// Cross on the top left hand corner
			design[((width) * (height / 2) - 1)] = 'X';
			// Cross on the bottom right
			design[((width) * (height / 2) + (width + 1))] = 'X';
			// Cross on the bottom left hand corner
			design[((width) * (height / 2) + width)] = 'X';
		}
	}
	// Width even values and height odd values
	if (width % 2 != 0 && height % 2 == 0)
	{
		// Cross on the top
		design[((width) * (height / 2))] = 'X';
		// Cross on the bottom
		design[((width) * (height / 2) + (width + 1))] = 'X';
	}
	else if (width % 2 == 0 && height % 2 != 0)
	{
		// Cross on the right
		design[((width) * (height / 2) + width)] = 'X';
		// Cross on the left
		design[((width) * (height / 2) + (width - 1))] = 'X';
	}
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
typedef struct
{
	int x;
	int y;
} Point;
Point locationWorker;
Point locationBox;
void WorkerRoute(int warehouse[10][10])
{
	for (int cols = 0; cols < 10; cols++)
	{
		for (int rows = 0; rows < 10; rows++)
		{
			// Store the locaton of the worker
			if (warehouse[rows][cols] == 1)
			{
				locationWorker.x = rows;
				locationWorker.y = cols;
			}
			//Store the location of the Box
			if (warehouse[rows][cols] == 2)
			{
				locationBox.x = rows;
				locationBox.y = cols;
			}
		}
	}
	// Going left
	if (locationWorker.y > locationBox.y)
	{
		for (int cls = (locationWorker.y - 1); cls >= locationBox.y; cls--)
		{
			if (warehouse[locationWorker.x][cls] != 2)
			{
				warehouse[locationWorker.x][cls] = 3;
			}
		}
	}
	// Going right
	else if (locationBox.y > locationWorker.y)
	{
		for (int cols = (locationWorker.y + 1); cols <= locationBox.y; cols++)
		{
			if (warehouse[locationWorker.x][cols] != 2)
			{
				warehouse[locationWorker.x][cols] = 3;
			}
		}
	}
	//Going up
	if (locationWorker.x > locationBox.x)
	{
		for (int rws = (locationWorker.x - 1); rws > locationBox.x; rws--)
		{
			warehouse[rws][locationBox.y] = 3;
		}
	}
	//Going down
	else if (locationBox.x > locationWorker.x)
	{
		for (int rows = (locationWorker.x + 1); rows < locationBox.x; rows++)
		{
			warehouse[rows][locationBox.y] = 3;
		}
	}
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/

int MakeMove(int warehouse[10][10], char move)
{
	int workerRows = 0;
	int workerCols = 0;

	// FInding where the location of the worker
	for (int rows = 0; rows < 10; rows++)
	{
		for (int cols = 0; cols < 10; cols++)
		{
			// Store the location of the worker into workerRows and wokerCols
			if (warehouse[rows][cols] == WORKER)
			{
				workerRows = rows;
				workerCols = cols;
			}
		}
	}
	// Up direction
	if (move == 'w')
	{
		// Moving Worker up, not acrossing the boundary
		if (warehouse[workerRows - 1][workerCols] == 0)
		{
			// Moving the worker
			warehouse[workerRows - 1][workerCols] = WORKER;
			warehouse[workerRows][workerCols] = SPACE;
		}
		// Moving Box up, also not going past the boundary
		if (warehouse[workerRows - 1][workerCols] == 3 && warehouse[workerRows - 2][workerCols] == 0)
		{
			// Moving the box
			warehouse[workerRows - 2][workerCols] = BOX;
			//Moving the worker
			warehouse[workerRows - 1][workerCols] = WORKER;
			warehouse[workerRows][workerCols] = SPACE;
		}
		//!Task 10
	}
	//Down direction
	if (move == 's')
	{
		// Moving Worker down, not acrossing the boundary
		if (warehouse[workerRows + 1][workerCols] == 0)
		{
			// Moving the worker
			warehouse[workerRows + 1][workerCols] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		// Moving Box down, also not going past the boundary
		if (warehouse[workerRows + 1][workerCols] == 3 && warehouse[workerRows + 2][workerCols] == 0)
		{
			// Moving the box
			warehouse[workerRows + 2][workerCols] = BOX;
			//Moving the worker
			warehouse[workerRows + 1][workerCols] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		//!Task 10
	}
	// Right direction
	if (move == 'd')
	{
		// Moving Worker right, not acrossing the boundary
		if (warehouse[workerRows][workerCols + 1] == 0)
		{
			warehouse[workerRows][workerCols + 1] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		// Moving Box right, also not going past the boundary
		if (warehouse[workerRows][workerCols + 1] == 3 && warehouse[workerRows][workerCols + 2] == 0)
		{
			// Moving the box
			warehouse[workerRows][workerCols + 2] = BOX;
			// Moving the worker
			warehouse[workerRows][workerCols + 1] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		//!Task 10
	}
	// Left direction
	if (move == 'a' || move == 'A')
	{
		// Moving Worker left, not acrossing the boundary
		if (warehouse[workerRows][workerCols - 1] == 0)
		{
			// Moving the worker
			warehouse[workerRows][workerCols - 1] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		// Moving Box left, also not going past the boundary
		if (warehouse[workerRows][workerCols - 1] == 3 && warehouse[workerRows][workerCols - 2] == 0)
		{
			// Moving the box
			warehouse[workerRows][workerCols - 2] = BOX;
			// Moving the worker
			warehouse[workerRows][workerCols - 1] = WORKER;
			warehouse[workerRows][workerCols] = 0;
		}
		//!Task 10

		if (warehouse[workerRows][workerCols] == 6 && warehouse[workerRows][workerCols - 1] == 3 && warehouse[workerRows][workerCols - 2] == 0)
		{
			warehouse[workerRows][workerCols] = TARGET;
			warehouse[workerRows][workerCols - 1] = WORKER;
			warehouse[workerRows][workerCols - 2] = BOX;
		}
		if (warehouse[workerRows][workerCols] == 6 && warehouse[workerRows][workerCols - 1] == 3 && warehouse[workerRows][workerCols - 2] == 2)
		{
			warehouse[workerRows][workerCols] = TARGET;
			warehouse[workerRows][workerCols - 1] = WORKER;
			warehouse[workerRows][workerCols - 2] = BOX;
		}
		if (warehouse[workerRows][workerCols] == 6 && warehouse[workerRows][workerCols - 1] == 4 && warehouse[workerRows][workerCols - 2] == 2)
		{
			warehouse[workerRows][workerCols] = TARGET;
			warehouse[workerRows][workerCols - 1] = WORKER_ON_TARGET;
			warehouse[workerRows][workerCols - 2] = BOX_ON_TARGET;
		}
		if (warehouse[workerRows][workerCols] == 6 && warehouse[workerRows][workerCols - 1] == 4 && warehouse[workerRows][workerCols - 2] == 0)
		{
			warehouse[workerRows][workerCols] = TARGET;
			warehouse[workerRows][workerCols - 1] = WORKER_ON_TARGET;
			warehouse[workerRows][workerCols - 2] = BOX;
		}
	}
	return 0;
}