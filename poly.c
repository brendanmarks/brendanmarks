#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int addPolyTerm(int base, int exp) {
	struct PolyTerm *p;
        p = (struct PolyTerm *) malloc(sizeof(struct PolyTerm));
	if (head == NULL) {
		*head = *p;	
	} else {
		struct PolyTerm *node = head; 
		while (node->next != NULL || head->next == NULL) {
			if (node->next->expo < p->expo){
				node = node->next;
			} else if (node->next->expo > p->expo) {
				struct PolyTerm *tmp = node->next;
				node->next = p;
				p->next = tmp;
			} else {
				node->coeff = node->coeff + p->coeff;
			}
		
		}
		
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
			printf("%ix%i", p->coeff, p->expo);
		}
	}
}

void evaluatePolynomial() {

}
