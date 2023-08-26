#include <stdio.h>

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src);

int main(void) {
  char s1[98] = "Hello ";
  char s2[] = "World!\n";
  char *ptr;

  ptr = _strcat(s1, s2);
  printf("%s\n", s1);
  printf("%s", s2);
  printf("%s", s1);
  printf("%s", s2);
  printf("%s", ptr);
  return (0);
}
char *_strcat(char *dest, char *src) {
char *t = dest;
while (*t++ != '\0') 


while (*src) *t++ = *src++;
printf("%s", dest);
return (dest);
/*   printf("%c\n", *t);
 */
}