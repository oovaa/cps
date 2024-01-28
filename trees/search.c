#include "tree.h"

node *search_rec(node *root, int val);

node *search(int val)
{
	return search_rec(root, val);
}
node *search_rec(node *root, int val)
{
	if (root == NULL || root->val == val)
	{
		return root;
	}
	else if (root->val > val)
	{
		return search_rec(root->left, val);
	}
	else
	{
		return search_rec(root->right, val);
	}
}