///*
// * PrintPathBetweenNodes.c
// *
// *  Created on: 14-Mar-2015
// *      Author: AllAboutComputerScience
// */
//
// /* print the path between any two given nodes in a binary tree */
//
//void printPathUtil(struct node *root, struct node *node1, struct node *node2)
//{
//
//}
//int IsPresent(struct tnode *root, struct tnode *node)
//{
//	if(!root)
//		return 0;
//	if(root == node)
//		return 1;
//	else
//		return IsPresent(root->left, node) || IsPresent(root->right, node);
//}
//
//void printPath(struct tnode *root, struct tnode *node1, struct tnode *node2)
//{
//	if(!root)
//	{
//		printf("tree is empty");
//		return;
//	}
//	if(IsPresent(root, node1) && IsPresent(root, node2))
//	{
//		printPathUtil(root, node1, node2);
//	}
//	else
//	{
//		printf("Both nodes must be present in the tree");
//	}
//}
//int main_PrintPathBetweenNodes()
//{
//	struct tnode *root = newtreenode(20);
//	root->left = (struct tnode *)newtreenode(16);
//	root->right = newtreenode(30);
//	root->left->left = newtreenode(14);
//	root->left->right = newtreenode(18);
//	root->right->left = newtreenode(24);
//
//	printPath(root, root->left->right, root->right->right);
//}
