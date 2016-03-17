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

struct node* reverse(struct node*);

struct node * numberToLinkedList(int N) {
	if (N < 0)
		N = -1 * N;
	typedef struct node list;
	list *head, *node,*temp;
	head = (list*)malloc(sizeof(list) * 1);
	head->num = N % 10;
	head->next = NULL;
	temp = head;
	N = N / 10;
	if (N == 0)
	{
		head = (list*)malloc(sizeof(list) * 1);
		head->num = 0;
		head->next = NULL;
	}
	else
	{
		while (N != 0)
		{
			node = (list*)malloc(sizeof(list) * 1);
			node->num = N % 10;
			node->next = NULL;
			temp->next = node;
			temp = node;
			N = N / 10;
		}
		temp->next = NULL;
		head = reverse(head);
	}
	return head;
}
struct node* reverse(struct node* head)
{
	struct node *temp1, *temp2, *temp3, *temp;
	temp1 = head;
	temp2 = temp1->next;
	temp1->next = NULL;
	while (temp2->next != NULL)
	{
		temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
	}
	temp2->next = temp1;
	temp = temp2;
	return temp2;
}