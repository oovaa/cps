#include "tree.h"

node *findMin_rec(node *root)
{
	while (root->left)

		root = root->left;
	return root;
}

node *findMax_rec(node *root)
{
	while (root->right)

		root = root->right;
	return root;
}

node *findMin()
{
	return findMin_rec(root);
}
node *findMax()
{
	return findMax_rec(root);
}