#include <math.h>
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[]) {

  char ***Aenviron = &environ;
  char ***Aenv = &envp;
  printf("Aenviron :%p   %p : env\n", Aenviron, Aenv);

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
