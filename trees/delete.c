#include "tree.h"

node *no_kid_delete(node *parent, node *target);
node *one_kid_delete(node *parent, node *target);
node *tow_kid_delete(node *parent, node *target);
node *find_seccessor(node *target);

node *delete(int val)
{

	node *target = search(val);
	node *parent = parent_search(val);
	if (!target || !parent)
	{
		printf("no such node or it is the root node\n");
		return NULL;
	}

	if (target->left && target->right)
		return tow_kid_delete(parent, target);
	else if (target->left || target->right)
		return one_kid_delete(parent, target);
	else
		return no_kid_delete(parent, target);
}

node *no_kid_delete(node *parent, node *target)
{
	node *tmp = target;

	if (parent->left == target)
		parent->left = NULL;
	else
		parent->right = NULL;

	return tmp;
}
node *one_kid_delete(node *parent, node *target)
{
	node *tmp = target, *kid = (target->left) ? target->left : target->right;

	if (parent->left == target)
		parent->left = kid;
	else
		parent->right = kid;

	tmp->left = tmp->right = NULL;

	return tmp;
}
node *tow_kid_delete(node *parent, node *target)
{
	node *suc = delete (find_seccessor(target)->val);

	suc->left = target->left;
	suc->right = target->right;

	if (parent->left == target)
		parent->left = suc;
	else
		parent->right = suc;

	target->left = target->right = NULL;

	return target;
}
node *find_seccessor(node *target)
{
	node *suc = target->left;
	while (suc->right)
		suc = suc->right;

	return suc;
}