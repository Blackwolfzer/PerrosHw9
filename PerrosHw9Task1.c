/*
 * =====================================================================================
 *
 *       Filename:  PerrosHw9Task1.c
 *       	Usage:  ./PerrosHw9Task1.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/04/2017 04:06:58 PM
 *
 Compiler:  gcc -Wall -Werror -lm 
 *         Author:  Daniel Tayler (), danieltayler@mail.weber.edu
 * =====================================================================================
 */

#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h> 

#define FSIZE 21
/* Function Prototypes */
void Usage(char **info);
void ReadFile(char *fileName, float num[]);
FILE *OpenCheckFile(char *fileName);
void WriteFile(FILE *inFile, float array[]);

/* Main Program */
int main(int argc, char *argv[])
{
	float array[FSIZE];
	char inF[FSIZE];
	char outF[FSIZE];
	char str[7] = "--help";

	if(argc != 3 && (argc == 1 || (strcmp(argv[1], str) == 0)))
	{
		Usage(&argv[0]);
	}
	else if(argc != 3)
	{
		Usage(&argv[0]);
	}

	strcpy(inF, argv[1]);
	ReadFile(inF, array);
	strcpy(outF, argv[2]);
	WriteFile(OpenCheckFile(outF), array);

	printf("\nThe file <%s> has successfully been written as a txt file.\n\n", outF);

	return 0;
}

/* Function Defenitions */
void Usage(char **info)
{
	printf("\nUsage %s <dataFile> <outFileName>\n\n", *info);
	exit(1);

	return;
}

void ReadFile(char *fileName, float num[])
{
	FILE *inFile;
	inFile = fopen(fileName, "r");

	if(inFile != NULL)
	{
		printf("\nTxt file <%s> was successfully read.\n", fileName);
		int count = 0;
		while(fscanf(inFile, "%f", &num[count]) != EOF)
		{
			count++;
		}
		fclose(inFile);
	}
	else
	{
		printf("\nTxt file <%s> could not be read\n\n", fileName);
	}

	return;
}

FILE *OpenCheckFile(char *fileName)
{
	FILE *inFile;
	char resp;
	inFile = fopen(fileName, "w");

	if(inFile != NULL)
	{
		printf("\nThe <%s> file exits.\n\n", fileName);
		printf("Do you want to overwrite it? (y or n): ");
		scanf("%c", &resp);
		
		if (resp == 'n' || resp == 'N')
		{
			printf("The existing file won't be overwritten\n");
			printf("Goodbye\n");
			exit(1);
		}
	}
	else
	{
		printf("Could not open file <%s> fo writting\n", fileName);
		exit(1);
	}

	return(inFile);
}

void WriteFile(FILE *outFile, float array[])
{   
	float sum = 0;
	float avg = 0;
	
	for(int i = 0; i < 12; i++)
	{
		fprintf(outFile, "%.4f\n" , array[i]);
		sum += array[i];
		avg = sum/12;
	}

	fprintf(outFile, "------------\n");
	fprintf(outFile, "Total: %.4f\n", sum);
	fprintf(outFile, "Avg: %.4f", avg);
	fclose(outFile);

	return;
}
