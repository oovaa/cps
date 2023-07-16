#include <stdio.h>

char *getstring(void);

int main(void) {
  // char *t = getstring();
  char t = 'A';
  printf("You entered: %p\n", &t);
  return 0;
}

char *getstring(void) {
  static char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  return str;
}