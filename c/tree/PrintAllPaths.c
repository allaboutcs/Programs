/*
 * PrintAllPaths.c
 *
 *  Created on: 24-Mar-2015
 *      Author: AllAboutComputerScience
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include "GenericTree.h"

void PrintArray(int pathArr[], int arrLen)
{
	int i;
	for(i = 0; i < arrLen; i++)
	{
		printf("%d -> ", pathArr[i]);
	}
	printf("$\n");
}

void PrintAllPathsUtil(struct tnode *root, int pathArr[], int pathIdx)
{
	if(!root)
		return;
	pathArr[pathIdx++] = root->data;
	if(root->left == NULL && root->right == NULL)
		PrintArray(pathArr, pathIdx);
	else
	{
		PrintAllPathsUtil(root->left, pathArr, pathIdx);
		PrintAllPathsUtil(root->right, pathArr, pathIdx);
	}

}
void PrintAllPaths(struct node *root)
{
	int pathArr[1000];

	if(!root)
		return;
	PrintAllPathsUtil(root, pathArr, 0);
}
int main_PrintAllPaths(void)
{
	struct tnode *root = NULL;
	root = newtreenode(10);
	root->left = newtreenode(20);
	root->right = newtreenode(40);
	root->left->left = newtreenode(30);
	root->left->right = newtreenode(70);
	root->right->right = newtreenode(100);


	printf("The paths are\n");
	PrintAllPaths(root);


	return 0;
}
