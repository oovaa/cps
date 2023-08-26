#include <stdio.h>
#include <stdlib.h>

void printnum(char *n);

int main(int argc, char const *argv[]) {

  printnum(122);
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
  if (atoi(n) / 10) {

    printnum(n[]);
  }
}

int some_function(void) {
  // printf("%d", 12);
  return (98);
}
