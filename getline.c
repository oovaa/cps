#include <stdio.h>

int main(int argc, char *argv[]) {
  char buf[256];
  printf("$: ");

  scanf("%[^\n]s", buf);

  printf("the text is: %s\n", buf);

  scanf("%s");
  
  char buf2[256];
  printf("$: ");

  scanf("%[^\n]s", buf2);

  printf("the text is: %s\n", buf2);
  return 0;
}