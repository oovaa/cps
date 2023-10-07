#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *getpath(char **arr) {
  char *ans, *hold = malloc(sizeof(char) * 20);
  int i = 0, j;
  for (i = 0; arr[i]; i++) {

    for (j = 0; arr[i][j] != '='; j++)
      strncat(hold, &arr[i][j], 1);

    hold[j] = '\0';
    if (strcmp(hold, "PATH") == 0) {
      strcpy(ans, arr[i] + 4);
    }
  }
  return ans;
}

int main(int argc, char *argv[], char *envp[]) {

  char ***Aenviron = &environ;
  char ***Aenv = &envp;
  char *path;

  printf("Aenviron: %p, Aenv: %p\n", Aenviron, Aenv);
  path = getpath(envp);
  printf("%s\n", path);

  // Iterate through the environment variables
  // for (int i = 0; environ[i]; i++) {
  //   printf("%s\n", environ[i]);
  // }

  // const double PI = 3.14159;
  // double r;
  // double c;
  // char s1[22];
  // char s2[22];

  // int i;

  // i = 9;
  // while (i--) {
  //   printf("%d", i);
  // }

  //   printf("enter name\n");
  //   scanf("%s", &s1);

  //   printf("enter name\n");
  //   scanf("%s", &s2);

  //   char s1[22];
  //   char s2[22];

  // printf("enter name\n");
  // scanf("%s", s1);

  // printf("enter name\n");
  // scanf("%s", s2);

  // printf("\n%s and %s\n", s1, s2);

  // printf("enter radios\n ");

  // scanf("%lf",&r);

  // double re = 2*PI*r;
  // double area = PI * r*r;

  // printf("the circ is %lf \n ",re);
  // printf("the area is %lf ",area);

  return 0;
}
