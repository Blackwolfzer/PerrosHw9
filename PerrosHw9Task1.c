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
	FILE *infile;
	char str[7] = "--help";
	char OutF[FSIZE];
	float num[12];
	if(argc != 3 && (argc == 1 || (strcmp(argv[1], str) == 0)))
	{
		Usage(&argv[0]);
	}
	else if(argc != 3)
	{
		Usage(&argv[0]);
	}

	strcpy(outF, argv[1]);
	ReadFile(outF, num[]);


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
	infile = fopen("fileName", "r");
	
	


	fclose(infile);
	return;
}
