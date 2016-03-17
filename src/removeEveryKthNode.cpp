/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head==NULL || K<=0)
	return NULL;
	else
	{
		struct node *temp, *temp1;
		int count = 1;
		temp = head;
		temp1 = temp;
		if (K == 1)
		{
			while (temp)
			{
				temp1 = temp->next;
				free(temp);
				temp = NULL;
				temp = temp1;
			}
			return head = NULL;
		}
		else if (K > 1)
		{
			if (K%2==0)
				while (temp)
				{
					if (count == K)
					{
						temp1->next = temp->next;
						free(temp);
						temp = NULL;
						temp = temp1->next;
						if (temp == NULL)
							break;
						count = 1;
					}
					temp1 = temp;
					temp = temp->next;
					count++;
				}
			else if (K%2!=0)
				while (temp)
				{
					temp = temp->next;
					count++;
					if (count == K - 1)
					{
						temp1 = temp;
						temp = temp->next;
						if (temp == NULL)
							break;
						temp1->next = temp->next;
						free(temp);
						temp = NULL;
						temp = temp1->next;
						count = 1;
					}
				}
		}
		return head;
	}
}
