#include <stdio.h>
#include <math.h>

char *getstring(void);
#define pi 3414
#define compute(a) (sqrt(a))

int main(void) {

  printf("%d\n", pi);
  int a =100;
  int x = compute(a);
  printf("%d\n", x);

  // char *t = getstring();
  // char t = 'A';
  // printf("You entered: %p\n", &t);
  return 0;
}

char *getstring(void) {
  static char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  return str;
}