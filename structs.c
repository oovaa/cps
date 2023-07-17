#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  struct player {
    char name[22];
    int score;
  };

  struct player p1;
  struct player p2;

  strcpy(p1.name, "omer");
  p1.score = 23;
  strcpy(p2.name, "mohammed");
  p2.score = 43;


  printf("%s\t :", p1.name);
  printf("%d\n", p1.score);
  printf("%s\t :", p2.name);
  printf("%d\n", p2.score);

  return 0;
}