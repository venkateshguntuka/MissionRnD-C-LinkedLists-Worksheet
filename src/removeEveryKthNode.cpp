/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if ((head == NULL && K > 0) || (K<=0))
		return NULL;
	struct node* temp1 = head;
	if (K == 1)
	{
		head = temp1->next;
		free(temp1);
		return head;
	}
	int i;
	struct node* temp2 = head;
	for (i = 0; i<K - 2; i++)
		temp1 = temp1->next;
	
	temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
	K += K;
	head = removeEveryKthNode(head, K);
	if (head == NULL)
		return NULL;
	return head;
}