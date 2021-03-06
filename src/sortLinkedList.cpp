/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node list;
list *mergesort(list *, int);
list *merge(list *, list *, int, int);
struct node * sortLinkedList(struct node *head) {
	if (head==NULL)
	return NULL;
	int len = 1;
	list* temp;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	temp = head;
	head = mergesort(temp, len-1);
	return head;
}

list *mergesort(list *present, int len)
{
	int mid, i = 0;
	list *prev, *ptr, *p, *s;
	mid = len / 2;
	prev = present;
	if (mid>0)
	{
		while (i<mid)
		{
			present = present->next;
			i++;
		}
		ptr = mergesort(prev, mid);
		p = mergesort(present, len - mid);
		s = merge(ptr, p, mid, len - mid);
		return s;
	}
	else
		return present;
}

list *merge(list *ptr, list *p, int mid, int left)
{
	int len, i = 0, j = 1, m, n;
	list *sort, *prv, *p1;
	len = mid + left;
	m = 0;
	n = 0;

	while (m<mid&&n<left)
	{
		sort = (list *)malloc(sizeof(list));
		if (j == 1)
		{
			p1 = sort;
			j++;
		}
		else
			prv->next = sort;
		if (ptr->num > p->num)
		{
			sort->num = p->num;
			p = p->next;
			n++;
		}
		else
		{
			sort->num = ptr->num;
			ptr = ptr->next;
			m++;
		}
		prv = sort;
	}
	while (n<left)
	{
		sort = (list *)malloc(sizeof(list));
		sort->num = p->num;
		p = p->next;
		prv->next = sort;
		prv = sort;
		n++;
	}
	while (m<mid)
	{
		sort = (list *)malloc(sizeof(list));
		sort->num = ptr->num;
		ptr = ptr->next;
		prv->next = sort;
		prv = sort;
		m++;
	}
	prv->next = NULL;
	return p1;
}
