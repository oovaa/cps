#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

  srand(time(0));

  const int min = 1;
  const int max = 100;
  int guess;
  int guesses = 0;
  int ans;

  ans = (rand() % max) + min; // guessing game

  // printf("%d",ans);
  do {

    printf("enter number : \n");
    scanf("%d", &guess);
    if (guess > ans) {
      /* code */ printf("too big\n");
    } else if (guess < ans) {
      printf("too small\n");

    } else {
      printf("CORRECT\n");
      printf("it took u %d times \n", guesses);
    }
    guesses++;

  } while (guess != ans);

  // int n = rand() % 5;
  // printf("%d  ", n);

  return 0;
}