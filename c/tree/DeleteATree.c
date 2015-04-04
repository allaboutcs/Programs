/*
 * DeleteATree.c
 *
 *  Created on: 23-Mar-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

/*  This function traverses tree in post order to
    to delete each and every node of the tree */
void DeleteTree(struct tnode *root)
{
	if(!root)
		return;

	/* first delete both subtrees */
	DeleteTree(root->left);
	DeleteTree(root->right);

	/* then delete the node */
	printf("\n Deleting node: %d", root->data);
	free(root);
}

void DeleteTreeEnhanced(struct tnode **rootref)
{
	if(!(*rootref))
		return;
	DeleteTree(*rootref);
	*rootref = NULL;
}

void DeleteTreeAllinOne(struct tnode** node)
{
	if(!*node)
		return;
	DeleteTreeAllinOne(&(*node)->left);
	DeleteTreeAllinOne(&(*node)->right);

	printf("\n Deleting node: %d", (*node)->data);
	free(*node);

	*node = NULL;

}
int main_DeleteATree(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->left->left = newtreenode(70);

	DeleteTreeAllinOne(&root);
	printf("\nTree deleted successfully!");

	return 0;
}

