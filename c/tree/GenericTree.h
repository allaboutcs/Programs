/*
 * GenericTree.h
 *
 *  Created on: 14-Mar-2015
 *      Author: rajmohan
 */

#ifndef TREE_GENERICTREE_H_
#define TREE_GENERICTREE_H_

struct tnode
{
	int data;
	struct tnode *left, *right;
};

struct tnode *newtreenode(int val);
#endif /* TREE_GENERICTREE_H_ */
