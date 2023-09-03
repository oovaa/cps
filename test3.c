#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printnum(char *n);
void tobinary(int n);

int main(int argc, char const *argv[]) {

  tobinary(9);

  // printnum("-22");
  // int *p = NULL;

  // printf("%d\n",*p);

  // int n = 5;
  // int array[10];
  // int i = 3;

  // array[n] = i;

  // int i = 5;
  // printf("%d\n",i+=4);

  // for (i = 48; i < 58; i++) {
  //   printf("%c", i);
  // }

  return 0;
}

void printnum(char *n) {
  if (*n == '-') {
    printf("-");
    n++;
  }
  while (*(n + 1))
    n++;

  if (*n == '\0') {
    printnum(n - 1);
  }
  putchar(*n);
}

int some_function(void) {
  // printf("%d", 12);
  return (98);
}

void tobinary(int n) {
  if (n / 2)
    tobinary(n / 2);

  printf("%d", n % 2);
}