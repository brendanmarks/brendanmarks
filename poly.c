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
			printf("%i\n", i);	
			if (node->next->expo < p->expo){
				node = node->next;
				printf("here1\n");
			} else if (node->next->expo > p->expo) {
				struct PolyTerm *tmp = node->next;
				node->next = p;
				p->next = tmp;
				printf("here2");
				return 1;
			} else {
				printf("here3");
				node->coeff = node->coeff + p->coeff;
				printf("\n%i", node->coeff);
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
	int arr[5] = {-2,-1,0,1,2};
	int res;
	int i;
	int test = powi(2,2);
	printf("here123, %i\n", test);
	for (i = 0; i<5; i++) {
		int a;
		int b;
		struct PolyTerm *p;
		p = head;
		res = head->coeff * powi(arr[i], p->expo);
		printf("%i\n",res);
		while (p->next != NULL) {
			res += p->next->coeff * powi(arr[i], p->next->expo);
			p = p->next;
		}
		if (i == 0) {
			printf("for x=%i, y=%i", arr[i], res);
		} else {
			printf("\nfor x=%i, y=%i", arr[i], res);
		}
		
	}
}
