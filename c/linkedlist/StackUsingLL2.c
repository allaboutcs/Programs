/*
 * StackUsingLL2.c
 *
 *  Created on: 03-Apr-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode
{
	int data;
	struct StackNode *next;
};

struct StackNode * NewStackListNode(int data)
{
	struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
	node->data = data;
	node->next = NULL;
	return node;
}

int IsEmptyStack(struct StackNode *top)
{
	return (top == NULL);
}

void push(struct StackNode **top, int data)
{
	struct StackNode *node = NewStackListNode(data);

	if(!(*top))
		*top = node;
	else
	{
		node->next = *top;
		*top = node;
	}
	printf("%d pushed\n", data);
}

int top(struct StackNode *top)
{
	if(IsEmptyStack(top))
	{
		printf("Stack is empty. Cant top()");
		return INT_MIN;
	}
	else
	{
		return top->data;
	}
}

int pop(struct StackNode **top)
{
	int val;
	if(IsEmptyStack(*top))
	{
		printf("Stack is empty");
		val = INT_MIN;
	}
	else
	{
		struct StackNode *t = *top;
		val = t->data;
		*top = (*top)->next;
		free(t);
	}
	return val;
}
void DeleteStack(struct StackNode **top)
{
	struct StackNode *cur = *top;
	struct StackNode *p;
	while(cur)
	{
		p = cur->next;
		free(cur);
		cur = p;
	}
	*top = NULL;
}

int main()
{
	int rval;
	struct StackNode *top = NULL;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	rval = pop(&top);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(&top);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(&top);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(&top);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

}

