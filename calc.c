#include <stdio.h>

int main(int argc, char const *argv[]) {
  char op;
  int n1;
  int n2;
  int re;

  printf("enter op :\t");
  scanf("%c", &op);

  printf("\nenter num1\t");
  scanf("%d", &n1);

  printf("\nenter num2\t");
  scanf("%d", &n2);

  switch (op) {
  case '+':
    re = n1 + n2;
    printf("%d", re);
    break;

  case '-':
    re = n1 - n2;
    printf("%d", re);
    break;

  case '*':
    re = n1 * n2;

    printf("%d", re);
    break;

  case '/':
    re = n1 / n2;
    printf("%d", re);
    break;

  default:
    printf("INVALID INPUT");

    break;
  }

  return 0;
}
