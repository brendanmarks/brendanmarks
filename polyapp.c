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



void main(int argc, char *argv[]) {
	
	FILE *f = fopen(argv[1], "rt");
	char array[1000];
	fgets(array, 999, f); 
	while(!feof(f)){
		int co;
		int ex;
		parse(array, &co, &ex);
		addPolyTerm(co, ex);	
		fgets(array, 999, f);
	}
	displayPolynomial();
	evaluatePolynomial();
	printf("here, inally");
}
