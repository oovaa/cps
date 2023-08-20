#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char s[6];
  scanf("%s", s);
  s[0] = toupper(s[0]);
  strcat(s, s);
  printf("%ld\n", strlen(s));
  for (size_t i = 0; i < strlen(s); i++)
    printf("%c", s[i]);

  int t = strcmp(s, s); // 1 if not equal 0  if equal
  printf("\n%d\n", t);

  for (size_t i = 0; i < strlen(s); i++)
    printf("%d\t", isupper(s[i]));

  return 0;
}
