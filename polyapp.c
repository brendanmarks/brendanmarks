#include <stdio.h>
#include <stdlib.h>

/*
 *	Purpose: This is the main file of the polyapp, which constructs and evaluates polynomials
 *	Author: Brendan Marks
 *	Department: Software Eng.
 *	History:
 *		- Create file
 *
 */



void main(int argc, char *argv[]) {
	
	//printf("%s", argv[1]);
	FILE *f = fopen(argv[1], "rt");
	char array[1000];

	fgets(array, 999, f);
	while(!feof(f)){
		printf("%s", array); 
		fgets(array, 999, f);
	}




}
