#include "tree.h"

node *root = NULL;

int main()
{
  addN(1);
  addN(2);
  addN(3);
  addN(4);
  addN(5);
  addN(6);
  addN(7);

  node *n = findMin();

  printf("%d\n", n->val);

  node *m = findMax();

  printf("%d\n", m->val);

  return 0;
}
