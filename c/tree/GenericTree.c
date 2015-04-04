#include <stdio.h>
#include "GenericTree.h"


struct tnode *newtreenode(int val)
{
	struct tnode *aNode = (struct tnode*)malloc(sizeof(struct tnode));
	aNode->data = val;
	aNode->left = aNode->right = NULL;
	return aNode;
}
