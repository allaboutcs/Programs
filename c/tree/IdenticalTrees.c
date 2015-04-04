/*
 * IdenticalTrees.c
 *
 *  Created on: 23-Mar-2015
 *      Author: AllAboutComputerScience
 * Description: Write C Code to Determine if Two Trees are Identical. Two trees are identical
 *              when they have same data and arrangement of data is also same.
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

int IsIdenticalTrees(struct tnode *root1, struct tnode *root2)
{
	if(!root1 && !root2)
		return 1;
	if(!root1 || !root2)
		return 0;

	if(root1->data != root2->data)
		return 0;
	return IsIdenticalTrees(root1->left, root2->left)
			&& IsIdenticalTrees(root1->right, root2->right);
}
int main_IdenticalTrees(void)
{
	struct tnode *root1 = NULL;
	root1 = newtreenode(10);
	root1->left = newtreenode(20);
	root1->right = newtreenode(40);
	root1->left->left = newtreenode(30);
	root1->left->left->left = newtreenode(70);

	struct tnode *root2 = NULL;
	root2 = newtreenode(10);
	root2->left = newtreenode(20);
	root2->right = newtreenode(40);
	root2->left->left = newtreenode(30);
	root2->left->right = newtreenode(70);

	if(IsIdenticalTrees(root1, root2))
	{
		printf("Identical");
	}
	else
	{
		printf("Non-Identical");
	}

	return 0;
}
