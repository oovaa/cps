#include "tree.h"

node *addN_rec(node *root, int val);

// Helper function to create a new node
node *createNode(int val)
{
  node *newNode = malloc(sizeof(node));
  if (!newNode)
  {
    fprintf(stderr, "malloc failed");
    exit(EXIT_FAILURE);
  }
  newNode->val = val;
  newNode->left = newNode->right = NULL;
  return newNode;
}

node *addN(int val)
{
  root = addN_rec(root, val);
  return root;
}

node *addN_rec(node *root, int val)
{

  if (root == NULL)
    return createNode(val);

  if (val > root->val)
    root->right = addN_rec(root->right, val);

  else if (val < root->val)
    root->left = addN_rec(root->left, val);

  return root;
}