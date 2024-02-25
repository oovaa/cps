#include "tree.h"

node *root = NULL;

int main()
{
  addN(20);
  addN(10);
  addN(30);
  addN(5);
  addN(3);
  addN(50);
  addN(15);
  addN(33);

  node *tmp = delete (10);

  printf("tmp = %d\n", tmp->val);
  printf("root = %d\n", root->left->left->val); // great 🔥

  in_order(root);
  return 0;
}
// TODO: add a parent pointer
