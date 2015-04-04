/*
 * NthNodeFromEnd.c
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

struct ListNode * getNthNodeFromEnd(struct ListNode *head, int n)
{
	struct ListNode *frontPtr, *rearPtr;
	int cnt;
	if(!head || n < 1)
		return NULL;

	frontPtr = head; cnt = 1;
	while(frontPtr && cnt < n)
	{
		frontPtr = frontPtr->next;
		cnt++;
	}
	if(!frontPtr)
		return NULL;

	rearPtr = head;
	while(frontPtr->next != NULL)
	{
		frontPtr = frontPtr->next;
		rearPtr = rearPtr->next;
	}
	return rearPtr;
}

