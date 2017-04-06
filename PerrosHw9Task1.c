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
void ReadFile(char *fileName, double num[]);

/* Main Program */
int main(int argc, char *argv[])
{
	char str[7] = "--help";
	char OutF[FSIZE];
	if(argc != 3 && (argc == 1 || (strcmp(argv[1], str) == 0)))
	{
		Usage(&argv[0]);
	}
	else if(argc != 3)
	{
		Usage(&argv[0]);
	}
//	float ar1;
//	ar1 = atof(argv[1]);
	strcpy(OutF, argv[1]);
//	ReadFile(OutF, &ar1);
	double array[FSIZE];
	ReadFile(OutF, array);
	for (int i = 0; i < 12; i++)
	{
		printf("no no no%lf\n", array[i]);
	}
	


	return 0;
}


/* Function Defenitions */
void Usage(char **info)
{
		printf("\nUsage %s <dataFile> <outFileName>\n\n", *info);
		exit(1);

	return;
}


void ReadFile(char *fileName, double num[])
{
	FILE *infile;
	infile = fopen(fileName, "r");
	
	if (infile != NULL)
	{
		printf(" we were able to read the file muahahhahaha");
		fseek(infile, 0, SEEK_END);
		long  sizef = ftell(infile);
		long  count = 0;
		fseek(infile, 0 , SEEK_SET);
		long i = 0;

	while ( count <= sizef )
	{
		fscanf(infile, "%lf", &num[i]);
		if (i < 12)
			printf("hi hi hi%f\n", num[i]);
	/*  	fread(num++, sizeof(float), 1 , infile); //  were in the array, the size of the data that i want to read, how many in a row, and what file i'm taking it from
		printf("%ld \nboo %lf\n", count,   *num++);
		fseek(infile, sizeof(char)+sizeof(float), SEEK_CUR);
		i++;
		count += sizeof(float) + sizeof(char);
		*/
		i++;
		count += sizeof(float) + sizeof(char);
	}	
	fclose(infile);
	}
	else
	{
		printf("we were not able to read that stupid file that you want us to read");
	}

	

	return;
}
