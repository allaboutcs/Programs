/*
 * InsertInSingleLL.c
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

struct ListNode * NewListNode(int data)
{
	struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void InsertInList(struct ListNode *head, int data, int pos)
{
	struct ListNode *newnode;
	struct ListNode *curNode;
	int curpos = 0;

	curNode = head;
	newnode = NewListNode(data);
	if(pos == 0)
	{
		if(!head)
			head = newnode;
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	else if(curpos < pos && curNode)
	{
		curNode = curNode->next;
		curpos++;
	}
}
