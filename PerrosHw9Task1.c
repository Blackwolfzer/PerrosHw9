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
void WriteFile(FILE *outFile, float array[]);

/* Main Program */
int main(int argc, char *argv[])
{
	float array[FSIZE];
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
	strcpy(outF, argv[1]);
	ReadFile(outF, array);
	for (int i = 0; i < 12; i++)
	{
		printf("no no no%lf\n", array[i]);
	}
	*OpenCheckFile(outF);
	WriteFile(// what are we call the two that go here


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

	if (inFile != NULL)
	{
		printf(" we were able to read the file muahahhahaha");
		fseek(inFile, 0, SEEK_END);
		long  sizef = ftell(inFile);
		long  count = 0;
		fseek(inFile, 0 , SEEK_SET);
		long i = 0;

	while ( count <= sizef )
	{
		fscanf(inFile, "%f", &num[i]);
		if (i < 12)
			printf("hi hi hi%f\n", num[i]);
	/*  	fread(num++, sizeof(float), 1 , inFile); //  were in the array, the size of the data that i want to read, how many in a row, and what file i'm taking it from
		printf("%ld \nboo %lf\n", count,   *num++);
		fseek(inFile, sizeof(char)+sizeof(float), SEEK_CUR);
		i++;
		count += sizeof(float) + sizeof(char);
		*/
		i++;
		count += sizeof(float) + sizeof(char);
	}	
	fclose(inFile);
	}
	else
	{
		printf("we were not able to read that stupid file that you want us to read");
	}

	return;
}

FILE *OpenCheckFile(char *fileName)
{
	FILE *inFile;
	char resp;
	inFile = fopen(filename, "w");
	if(inFile != NULL)
	{
		printf("The %s file exits.\n", filename);
		printf("Do you want to overwrtie it?\n");
		scanf("%c", &resp);
		
		if (resp == 'n' || resp == 'N')
		{
			printf("The existing file won't be overwritten\n");
			printf("Goodbye\n");
			exit(1);
		}
	fclose(inFile);\
	}
	return ();
}



void WriteFile(FILE *outFile, float array[])
{
	float sum = 0;
	float avg = 0;
	for(int i = 0; i < 12; i++)
	{
		fprintf(outFile, "%f" , array[i]);
		sum += array[i];
		avg = sum/12;

	}
	printf(" The sum of the number is: %f\n", sum);
	printf(" The avg of the number is: %f\n", avg);
	printf(" The numbers have been written to your file");

	return;
}
