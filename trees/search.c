#include "tree.h"

node *search_rec(node *root, int val);
node *parent_search_rec(node *root, int val);

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

node *parent_search(int val)
{
	return parent_search_rec(root, val);
}

node *parent_search_rec(node *root, int val)
{
	if (root == NULL)
	{
		return NULL;
	}
	if ((root->left && root->left->val == val) || (root->right && root->right->val == val))
	{
		return root;
	}
	else if (root->val > val)
	{
		return parent_search_rec(root->left, val);
	}
	else
	{
		return parent_search_rec(root->right, val);
	}
}