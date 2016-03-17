/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head){
	if (head==NULL)
	return 0;
	else
	{
		int sum = 0,num1,num2,num=0;
		while (head)
		{
			sum = sum * 10;
			num1 = head->digit1;
			num2 = head->digit2;
			num = num1 * 10 + num2;
			sum = sum * 10 + num;
			head = head->next;
		}
		return sum;
	}
}
