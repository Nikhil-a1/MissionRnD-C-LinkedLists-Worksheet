/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	int zeros = 0, ones = 0, twos = 0;
	struct node* temp;
	temp = head;
	if (head == NULL)
		return;
	while (temp)
	{
		if (temp->data == 0)
			zeros++;
		else if (temp->data == 1)
			ones++;
		else
			twos++;
		temp = temp->next;
	}
	temp = head;
	while (zeros > 0)
		{
			temp->data = 0;
			zeros--;
			temp = temp->next;
		}
		while (ones > 0 && temp)
		{
			temp->data = 1;
			ones--;
			temp = temp->next;
		}
		while (twos > 0 && temp)
		{
			temp->data = 2;
			twos--;
			temp = temp->next;
		}
}