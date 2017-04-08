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
void MathFunction(float xAxis[], float yAxis[], int Rep);
 void MathFunctionBegin(int xyAxis[][COLS],float x[],float y[]);

/* Main Program */
int main(int argc, char *argv[])
{
	FILE *inFile;
	int xyValues[ROWS][COLS];
	inFile = fopen("zone1.txt", "r");

	if(inFile != NULL)
	{
		printf("<%s> was read.\n", "zone1.txt");
	
		for( int j =0; j < ROWS ; j++)
		{
			for( int i =0; i < COLS ; i++)
			{
					fscanf(inFile, "%d", &xyValues[j][i]);
					//printf("%d\n", xyValues[j][i]);
			}
		}
	}

	float xValues[ROWS];
	float yValues[ROWS];

	MathFunctionBegin( xyValues, xValues, yValues);
	MathFunction(xValues, yValues, sizeof(xValues)/sizeof(float));

	return 0;
}

/* Function Defenitions */
void MathFunctionBegin(int xyAxis[][COLS],float x[],float y[])
{
	for ( int i = 0; i < ROWS ; i++)
	{
		x[i] = xyAxis[i][0];
		
		for ( int j = 1; j < COLS ; j++)
		{
			y[i] = xyAxis[i][j];
		}
	}

	return;
}

void MathFunction(float xAxis[], float yAxis[], int Rep)
{
	float m = 0.0;
	float b = 0.0;
	float sumx = 0.0; //sum of teh x axis
	float sumy = 0.0; //sum of the y axis
	float sumxy = 0.0; //sum of hte x time y axis
	float sumxx = 0.0; // sum of x^2
	float sumxThenSquare = 0.0; // sum of x then x squared
	
	for(int i = 0; i < Rep; i++)
	{
		sumx += xAxis[i];
		sumy += yAxis[i];
		sumxy += (xAxis[i] * yAxis[i]);
		sumxx += ( xAxis[i] * xAxis[i]);
	}
	sumxThenSquare = ( sumx * sumx);
	// time fore math to work out lets see if we can't gt m and b muahahhaha
	m = (  (  (sumx * sumy) - (Rep * sumxy)  ) /  (  ( sumxThenSquare ) - ( Rep * sumxx)  )  );

	b = (  (  ( sumx * sumxy)  -  ( sumxx * sumy ) ) /  (  ( sumxThenSquare ) - ( Rep *  sumxx) ) );
	
	printf("\nThe Range of altitudes that we were wonderfully given in km are: %.2f to %.2f\n", xAxis[0], xAxis[(ROWS -1)]);
	printf("\nozone-mix-ratio = %.2f altitude + %.2f\n\n", m , b);

	return;
}

