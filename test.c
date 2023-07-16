#include <stdio.h>

char *getstring(void);

int main(void) {
  char *t = getstring();
  printf("You entered: %s\n", t);
  return 0;
}

char *getstring(void) {
  static char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  return str;
}