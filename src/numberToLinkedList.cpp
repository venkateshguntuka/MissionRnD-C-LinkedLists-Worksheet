/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node* Insert(int rem, struct node* head)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->num = rem;
	temp->next = NULL;
	if (head != NULL)
		temp->next= head;
	head = temp;
	return head;
}
struct node * numberToLinkedList(int N) {
	struct node* head = NULL;
	N = (N >= 0) ? N : -N;//abs implementation
	int rem;
	if (N == 0)
		head=Insert(N, head);
		while (N > 0)
		{
			rem = N % 10;
			N = N / 10;
			head = Insert(rem, head);
		}
	return head;
}