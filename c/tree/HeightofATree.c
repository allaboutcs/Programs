/*
 * HeightofATree.c
 *
 *  Created on: 23-Mar-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

int GetHeight(struct tnode *root)
{
	int l, r;
	if(!root)
		return 0;
	l = GetHeight(root->left);
	r = GetHeight(root->right);
	if(l > r)
		return l+1;
	else
		return r+1;
}

int main_HeightofATree(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->left->left = newtreenode(70);

	printf("Height(Max-Depth) of the Tree = %d", GetHeight(root));
	return 0;
}

