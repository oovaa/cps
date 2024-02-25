#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node
{
  int val;
  struct Node *left;
  struct Node *right;
} node;

// Declare the global variable for the root of the tree
extern node *root;

node *addN(int val);

node *createNode(int val);
void pre_order(node *root);
void in_order(node *root);
void post_order(node *root);
node *search(int val);

node *findMin();
node *findMax();

node *parent_search(int val);
node *delete(int val);

int height(node *root);
int depth(node *root);

#endif // TREE_H
