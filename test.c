#include <math.h>
#include <stdio.h>
#include <string.h>

char *getstring(void);
char *returnString(void);
#define pi 3414
#define compute(a) (sqrt(a))

int main(void) {

  char *c = "omera";
  printf("%ld\n", strlen(c));
  printf("%ld\n", sizeof(c));

  // char *name = returnString();
  // printf("%s\n", name);

  // printf("%d\n", 'c');

  // printf("%d\n", pi);
  // int a = 100;
  // int x = compute(a);
  // printf("%d\n", x);

  // char *t = getstring();
  // char t = 'A';
  // printf("You entered: %p\n", &t);
  return 0;
}
char *returnString(void) {
  static char s[22];
  // fgets(s,22,stdin);
  scanf("%s", s);
  // scanf("%s",s);
  // scanf("%s",s);
  return s;
}

char *getstring(void) {
  static char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);
  return str;
}