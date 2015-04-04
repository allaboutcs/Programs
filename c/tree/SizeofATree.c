/*
 * SizeofATree.c
 *
 *  Created on: 23-Mar-2015
 *      Author: AllAboutComputerscience
 *      Write a C program to Calculate Size of a tree
 *      Size of a tree is the number of elements present in the tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

int GetSizeofTree(struct tnode *root)
{
	int l, r;
	if(!root) return 0;
	l = GetSizeofTree(root->left);
	r = GetSizeofTree(root->right);

	return l + r + 1;
}

int GetSizeofTree_Inorder(struct tnode *root)
{
	static int size = 0;
	if(root)
	{
		GetSizeofTree_Inorder(root->left);
		size = size + 1;
		GetSizeofTree_Inorder(root->right);
	}
	return size;
}

int main_SizeofTree(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->left->left = newtreenode(70);

	printf("Size of the Tree = %d", GetSizeofTree_Inorder(root));
	return 0;
}
