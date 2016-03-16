/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node*, struct node*);
struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *start = head, *traverse, *min;
	while (start->next)
	{
		min = start;
		traverse = start->next;
		while (traverse)
		{
			if (min->num > traverse->num)
				min = traverse;
			traverse = traverse->next;
		}
		swap(start, min);
		start = start->next;
	}
	return head;
}
void swap(struct node* ptr1, struct node* ptr2)
{
	int temp = ptr1->num;
	ptr1->num = ptr2->num;
	ptr2->num = temp;
}