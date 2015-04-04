/*
 * BalancedBinaryTree.c
 *
 *  Created on: 21-Mar-2015
 *      Author: rajmohan
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "GenericTree.h"

int getHeightSpl(struct tnode *root)
{
	int l, r;
	if(!root)
		return 0;
	l = getHeightSpl(root->left);
	r = getHeightSpl(root->right);

	if(l == -1 || r == -1)
		return -1;
	if(abs(l-r) > 1)
		return -1;

	if(l > r)
		return  l+1;
	else
		return r+1;
}
unsigned char isBalancedTree(struct tnode *root)
{
	if(!root)
		return 1;
	if(getHeightSpl(root) == -1)
		return 0;

	return 1;
}

int main_BalancedBinaryTree(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->left->left = newtreenode(70);

	if(isBalancedTree(root))
		printf("Yes Balanced binary tree it is..");
	else
		printf("No not a Balanced binary tree");
}
