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
	
	//printf("%s", argv[1]);
	FILE *f = fopen(argv[1], "rt");
	char array[1000];
	//printf("here0");
	fgets(array, 999, f); 
	while(!feof(f)){
		int co;
		int ex;
		parse(array, &co, &ex);
		//printf("here%i&%i\n", co, ex);
		addPolyTerm(co, ex);
	       	//printf("here2");	
		fgets(array, 999, f);
	
	}
	
	
	//printf("here3");
	displayPolynomial();
	printf("here4\n");
	evaluatePolynomial();
	
	


}
