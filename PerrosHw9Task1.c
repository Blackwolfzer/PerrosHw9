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
	float ar1;
	ar1 = atof(argv[1]);
	strcpy(OutF, argv[1]);
	ReadFile(OutF, &ar1);


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
	FILE *infile;
	infile = fopen(fileName, "r");
	
	if (infile != NULL)
	{
		printf(" we were able to read the file muahahhahaha");
		
	}
	else
	{
		printf("we were not able to read that stupid file that you want us to read");
	}


	fclose(infile);
	return;
}
