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
	if (head == NULL || K <= 1)
		return NULL;
	int count = 1;
	struct node *temp = head;
	while (temp != NULL)
	{
		if (count == K - 1 && temp->next != NULL)
		{
			temp->next = temp->next->next;
			count = 1;
		}
		else
			count++;
		temp = temp->next;
	}
	return head;
}