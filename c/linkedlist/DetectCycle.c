/*
 * DetectCycle.c
 *
 *  Created on: 03-Apr-2015
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

struct ListNode * NewListNode(int data)
{
	struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

int DetectCycle(struct ListNode *head)
{
	struct ListNode *slowPtr, *fastPtr;
	if(!head || !head->next)
		return 0;

	slowPtr = head; fastPtr = head;
	while(fastPtr && fastPtr->next)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
		if(slowPtr == fastPtr)
			return 1;
	}

	return 0;
}

int DetectCycle2(struct ListNode *head)
{
	struct ListNode *slowPtr, *fastPtr;

	slowPtr = head; fastPtr = head;
	while(slowPtr && fastPtr)
	{
		fastPtr = fastPtr->next;
		if(slowPtr == fastPtr)
			return 1;
		if(!fastPtr)
			return 0;

		fastPtr = fastPtr->next;
		if(slowPtr == fastPtr)
			return 1;
		slowPtr = slowPtr->next;
	}

	return 0;
}

