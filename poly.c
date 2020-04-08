#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/*
 *      Purpose: This is the poly file of the polyapp, for creating the LL of polys
 *      Author: Brendan Marks
 *      Department: Software Eng.
 *      History:
 *              - Create file
 *
 */

struct PolyTerm *head = NULL;
struct PolyTerm *tail = NULL;

struct PolyTerm {
	int coeff;
	int expo;
	struct PolyTerm *next;

};

int addPolyTerm(int coef, int exp) {
	struct PolyTerm *p;
        p = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	p->coeff = coef;
	p->expo = exp;
	p->next = NULL;
	if (head == NULL) {
		head = p;			
	} else {
		if (p->expo < head->expo) {
			p->next = head;
			head = p;
			return 1;
		} else if (p->expo == head->expo) {
			head->coeff = head->coeff + p->coeff;
			return 1;
		}
		struct PolyTerm *node = head;	
		while (node->next != NULL || head->next == NULL) {
			int i = node->next->expo;
				
			if (node->next->expo < p->expo){
				node = node->next;
				
			} else if (node->next->expo > p->expo) {
				struct PolyTerm *tmp = node->next;
				node->next = p;
				p->next = tmp;
				
				return 1;
			} else {
				node->coeff = node->coeff + p->coeff;
				return 1;
			}
		}
		node->next=p;
	}			
	return 1;
} 

void displayPolynomial(){
	struct PolyTerm *p;
	*p = *head;
	if (head != NULL) {
		printf("%ix%i", p->coeff, p->expo);
		while (p->next != NULL) {
			p = p->next;
			if (p->coeff >= 0) {
				printf("+%ix%i", p->coeff, p->expo);
			} else {
				printf("%ix%i", p->coeff, p->expo);
			}
		}
	}
}

void evaluatePolynomial() {
	int *arr;
	arr = malloc(5 * sizeof(int));
	arr[0] = -2;
	arr[1] = -1;
	arr[2] = 0;
	arr[3] = 1;
	arr[4] = 2;
	int res;
	int i;
	printf("\n");	
	for (i = 0; i<5; i++) {
		int a;
		int b;
		struct PolyTerm *p;
		p = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
		p = head;
		res = head->coeff * powi(arr[i], p->expo);
		p = p->next;
		
		while (p != NULL) {
			res += p->coeff * powi(arr[i], p->expo);
			p = p->next;
		}
		if (i == 0) {
			printf("for x=%i, y=%i\n", arr[i], res);
		} else {
			printf("for x=%i, y=%i\n", arr[i], res);
		}
	}
}
