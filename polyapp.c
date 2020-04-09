#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "poly.h"

/*
 *	Purpose: This is the main file of the polyapp, which constructs and evaluates polynomials
 *	Author: Brendan Marks
 *	Department: Software Eng.
 *	History:
 *		- Create file
 *
 */



int main(int argc, char *argv[]) {
	
	FILE *f = fopen("data.ssv", "rt");
	// parse all lines of the file and add them to LL
	char array[10000];
	fgets(array, 9999, f); 
	while(!feof(f)){
		int co;
		int ex;
		parse(array, &co, &ex);
		addPolyTerm(co, ex);	
		fgets(array, 9999, f);
	}
	fclose(f);
	//display poly
	displayPolynomial();
	//evaluate poly
	evaluatePolynomial();

	
	return 0;
}
