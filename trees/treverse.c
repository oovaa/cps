#include "tree.h"

void pre_order(node *root) {
  if (!root) {
    return;
  }

  printf("%d  ", root->val);
  pre_order(root->left);
  pre_order(root->right);
}

void in_order(node *root) {
  if (!root)
    return;

  in_order(root->left);
  printf("%d  ", root->val);
  in_order(root->right);
}

void post_order(node *root) {
  if (!root)
    return;

  post_order(root->left);
  post_order(root->right);
  printf("%d  ", root->val);
}