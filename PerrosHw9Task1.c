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
	//for (int i = 0; i < 12; i++)
	//{
	//	printf("no no no%lf\n", array[i]);
	//}
	//*OpenCheckFile(inF);
	strcpy(outF, argv[2]);
	WriteFile(OpenCheckFile(outF), array);
	// what are we call the two that go here


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
		//The following while loop and int count can be removed before submitting, it was just here to view what was in the input file.
		int count = 0;
		while(fscanf(inFile, "%f", &num[count]) != EOF)
		{
			printf("%f\n", num[count]);
			count++;
		}
		/* fseek(inFile, 0, SEEK_END);
		long  sizef = ftell(inFile);
		long  count = 0;
		fseek(inFile, 0 , SEEK_SET);
		long i = 0;

	while ( count <= sizef )
	{
		fscanf(inFile, "%f", &num[i]);
		if (i < 12)
			printf("hi hi hi%f\n", num[i]);*/
	/*  	fread(num++, sizeof(float), 1 , inFile); //  were in the array, the size of the data that i want to read, how many in a row, and what file i'm taking it from
		printf("%ld \nboo %lf\n", count,   *num++);
		fseek(inFile, sizeof(char)+sizeof(float), SEEK_CUR);
		i++;
		count += sizeof(float) + sizeof(char);
		*/
		//i++;
		//count += sizeof(float) + sizeof(char);
	//}
	fclose(inFile);
	}
	else
	{
		printf("Txt file <%s> could not be read\n", fileName);
	}
	//fclose(inFile);
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
	return(inFile);
}



void WriteFile(FILE *outFile, float array[])
{   
	/* int count = 0;
	float sum = 0;
	float avg;
	while(fscanf(outFile, "%f", &array[count]) != EOF)
	{
		printf("%f\n", array[count]);
		sum += array[count];
		avg += array[count];
		count++;
	}
	avg = avg/(count * 1.0);
	printf("%f\n", avg);*/
	float sum = 0;
	float avg = 0;
	for(int i = 0; i < 12; i++)
	{
		fprintf(outFile, "%.4f\n" , array[i]);
		sum += array[i];
		avg = sum/12;
	}
	fclose(outFile);
	printf(" The sum of the number is: %f\n", sum);
	printf(" The avg of the number is: %f\n", avg);
	printf(" The file has successfully been written as a txt file.\n");
	return;
}
