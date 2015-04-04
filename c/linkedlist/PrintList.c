/*
 * PrintList.c
 *
 *  Created on: 02-Apr-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

void PrintList(struct ListNode *root)
{
	struct ListNode *cur;

	cur = root;
	while(cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}
