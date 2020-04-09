#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *      Purpose: This is the utils file of the polyapp, for parsing & powi functions
 *      Author: Brendan Marks
 *      Department: Software Eng.
 *      History:
 *              - Create file
 *
 */

void parse(char* line, int* i1, int* i2) {
	int coef = atoi(strtok(line, " "));
	int exp = atoi(strtok(NULL, " "));
	*i1 = coef;
	*i2 = exp;
}

int powi(int base, int exp) {
	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return base;
	}
	if (exp % 2 == 0) {
		return powi(base, exp/2) * powi(base, exp/2);
	} else {
		return base*powi(base, exp-1);
	}
}

