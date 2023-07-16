#include <stdio.h>
int main(int argc, char const *argv[]) {

  int ot;
  char t;

  printf("temp is in C or F?\n");
  scanf("%c", &t);
  t = toupper(t);

  printf("enter temp :\t");
  scanf("%d", &ot);

  switch (t) {
  case 'C':
    ot = (ot / 9 * 5) + 32;
    printf("the temp in F is : %d", ot);
    break;

  case 'F':
    ot = ((ot - 32) * 5) / 9;
    printf("the temp in C is : %d\n", ot);
    break;

  default:
    printf("INVALID INPUT");

    break;
  }

  return 0;
}
