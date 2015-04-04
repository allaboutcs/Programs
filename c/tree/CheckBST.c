#include <stdio.h>
#include "GenericTree.h"
#include <limits.h>
/* Given a binary tree, check whether it is a binary search tree or not */

// get maximum value present in a binary tree rooted at a node
int GetMaxVal(struct tnode *node)
{
	int curval, lval, rval, max;

	if(!node)
		return INT_MIN;

	curval = node->data;
	lval = GetMaxVal(node->left);
	rval = GetMaxVal(node->right);

	if(lval > rval)
		max = lval;
	else
		max = rval;

	if(curval > max)
		max = curval;

	return max;
}

// get minimum value present in a binary tree rooted at a node
int GetMinVal(struct tnode *node)
{
	int curval, lval, rval, min;

	if(!node)
		return INT_MAX;

	curval = node->data;
	lval = GetMinVal(node->left);
	rval = GetMinVal(node->right);

	if(lval < rval)
		min = lval;
	else
		min = rval;

	if(curval < min)
		min = curval;

	return min;
}

int checkBST(struct tnode *root)
{
	if(!root)
		return 1;
	if(root->left && (GetMaxVal(root->left) > root->data))
		return 0;
	else if(root->right && (GetMinVal(root->right) <= root->data))
		return 0;
	else
		return checkBST(root->left) && checkBST(root->right);
}

/* technique 2 - efficient */
int checkBSTUtil(struct tnode *root, int min, int max)
{
	if(!root)
		return 1;
	else if(!(root->data >= min && root->data <= max))
		return 0;
	else
		return checkBSTUtil(root->left, min, root->data)
				&& checkBSTUtil(root->right, root->data + 1, max);
}
int checkBST2(struct tnode *root)
{
	return checkBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
	struct tnode *root = newtreenode(20);
	root->left = (struct tnode *)newtreenode(16);
	root->right = newtreenode(30);
	root->left->left = newtreenode(14);
	root->left->right = newtreenode(18);
	root->right->left = newtreenode(24);

	if(checkBST2(root))
	{
		printf("Tree is a Binary search tree");
	}
	else
	{
		printf("Tree is not a Binary search tree");
	}
}
