/*
 * StackUsingLL.c
 *
 *  Created on: 03-Apr-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

struct Stack
{
	struct ListNode *top;
};

struct ListNode * NewListNode(int data)
{
	struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = data;
	node->next = NULL;
	return node;
}

int IsEmptyStack(struct Stack *s)
{
	return (s->top == NULL);
}

void push(struct Stack *s, int data)
{
	struct ListNode *node = NewListNode(data);

	if(!s->top)
		s->top = node;
	else
	{
		node->next = s->top;
		s->top = node;
	}
	printf("%d pushed\n", data);
}

int top(struct Stack *s)
{
	if(IsEmptyStack(s))
	{
		printf("Stack is empty. Cant top()");
		return INT_MIN;
	}
	else
	{
		return s->top->data;
	}
}

int pop(struct Stack *s)
{
	int val;
	if(IsEmptyStack(s))
	{
		printf("Stack is empty");
		val = INT_MIN;
	}
	else
	{
		struct ListNode *t = s->top;
		val = t->data;
		s->top = s->top->next;
		free(t);
	}
	return val;
}
void DeleteStack(struct Stack *s)
{
	struct ListNode *cur = s->top;
	struct ListNode *p;
	while(cur)
	{
		p = cur->next;
		free(cur);
		cur = p;
	}
	s->top = NULL;
}
int main()
{
	int rval;
	struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
	s->top = NULL;

	push(s, 10);
	push(s, 20);
	push(s, 30);

	rval = pop(s);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(s);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(s);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

	rval = pop(s);
	if(rval != INT_MIN)
		printf("%d popped\n", rval);

}

