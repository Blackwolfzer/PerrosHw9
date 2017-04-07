/*
 * =====================================================================================
 *
 *       Filename:  PerrosHw9Task2.c
 *       	Usage:  ./PerrosHw9Task2.c
 *    Description:  Task 2
 *
 *        Version:  1.0
 *        Created:  04/04/2017 04:19:55 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sharon Dansie (), sharondansie@weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>

#define COLS 2
#define ROWS 4
/* Function Prototypes */
void MathFunction(int xAxis[], int yAxis[], int Rep);
 void MathFunctionBegin(int xyAxis[][COLS],int x[],int  y[]);

/* Main Program */
int main(int argc, char *argv[])
{
	FILE *inFile;
	int xyValues[ROWS][COLS];
	inFile = fopen("zone1.txt", "r");
	if(inFile != NULL)
	{
		printf("<%s> was read.\n", "zone1.txt");
	}
			for( int j =0; j < ROWS ; j++)
		{
			for( int i =0; i < COLS ; i++)
			{
				fscanf(inFile, "%d", &xyValues[j][i]);
				printf("%d\n", xyValues[j][i]);
			}
		}

	/* test variable to have an idea what i'm planning to do here lets see how well this works out */
	int xValues[ROWS];
	int yValues[ROWS];

	MathFunctionBegin( xyValues, xValues, yValues);
	MathFunction(xValues, yValues, sizeof(xValues)/sizeof(int));

	return 0;
}


/* Function Defenitions */

 void MathFunctionBegin(int xyAxis[][COLS],int x[],int  y[])
{
	for ( int i = 0; i < ROWS ; i++)
	{
		x[i] = xyAxis[i][j];
		
		for ( int j = 1; j < COLS ; j++)
			y[i] = xyAxis[i][j];
	}
	return;
}
void MathFunction(int xAxis[], int yAxis[], int Rep)
{
	float m = 0.0;
	float b = 0.0;
	int sumx = 0; //sum of teh x axis
	int sumy = 0; //sum of the y axis
	int sumxy = 0; //sum of hte x time y axis
	int sumxx = 0; // sum of x^2
	int sumxThenSquare = 0; // sum of x then x squared
	for(int i = 0; i < Rep; i++)
	{
		sumx += xAxis[i];
		sumy += yAxis[i];
		sumxy += (xAxis[i] * yAxis[i]);
		sumxx += ( xAxis[i] * xAxis[i]);

	}
	sumxThenSquare = ( sumx * sumx);
	// time fore math to work out lets see if we can't gt m and b muahahhaha
	m = (  (  (sumx * sumy) - (sumxy)  ) /  (  ( sumxThenSquare ) - ( Rep * sumxx)  )  );

	b = (  (  ( sumx * sumxy)  -  ( sumxx * sumy ) ) /  (  ( sumxThenSquare ) - ( Rep *  sumxx) ) );

	printf(" %f for m and %f for b\n ", m , b);

	printf(" The values of sums to see if they work sumx %d sumy %d sumxy %d sumxx %d sum^2 %d \n "
			, sumx, sumy, sumxy, sumxx, sumxThenSquare);

	return;
}

