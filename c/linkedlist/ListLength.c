/*
 * ListLength.c
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

int GetListLength(struct ListNode *root)
{
	struct ListNode *cur;
	int count;

	count = 0;
	cur = root;
	while(cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
