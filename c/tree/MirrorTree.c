/*
 * MirrorTree.c
 *
 *  Created on: 23-Mar-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

void MirrorTree(struct tnode *root)
{
	struct tnode *temp;

	if(!root)
		return;
	MirrorTree(root->left);
	MirrorTree(root->right);

	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void MirrorTreePreOrder(struct tnode *root)
{
	struct tnode *temp;

	if(!root)
		return;

	temp = root->left;
	root->left = root->right;
	root->right = temp;

	MirrorTree(root->left);
	MirrorTree(root->right);

}

void PrintInOrder(struct tnode *root)
{
	if(root)
	{
		PrintInOrder(root->left);
		printf("%d -> ", root->data);
		PrintInOrder(root->right);
	}
}

int main_MirrorTree(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->left->left = newtreenode(70);

	PrintInOrder(root);

//	printf("\nMirror Tree is\n");
//	MirrorTree(root);
//	PrintInOrder(root);

	printf("\nMirror Tree in another method is\n");
	MirrorTreePreOrder(root);
	PrintInOrder(root);

	return 0;
}

