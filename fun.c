#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char s1[] = "omer ";
  char s2[] = "abdolraheem ";

    char* t = getstring();
    printf("You entered: %s\n", t);
  // strcpy(string1,string2);
  // strncpy(string1,string2,5);
  // strrev(s1);
  // int a = strlen(string1);
  // int a = strncmp(s1,s2,1);

  //  printf("%s",string1);
  //  printf("%d",a);

  return 0;
}

int add(int i1, int i2) {
  int z = i1 > i2 ? i1 + i2 : i1 - i2;
  // printf("%d\n",z);
  return z;
}
// (char s[]) getstring (){//TODO
//     printf("enter string");
//     fgets(s,23,stdin);
//     s[strlen(s)-1]='\0';
//     return s;
// }

// char[] getstr() {
//     char[]  s= {};
//     printf("enter string");
//     fgets(s,23,stdin);
//     s[strlen(s)-1]='\0';
//     return s;
// }
char *getstr() {
  char *s = malloc(25 * sizeof(char));
  if (s == NULL) {
    printf("Error: out of memory\n");
    exit(1);
  }
  printf("Enter string: ");
  fgets(s, 25, stdin);
  s[strcspn(s, "\n")] = '\0'; // remove newline character from input
  return s;
}