#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> // Include the sys/wait.h header
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int id = fork();
  int n;
  if (id == 0)
    n = 1;
  else
    n = 6;

  int status;
  if (id != 0)
    wait(&status);
    
  for (int i = n; i < n + 5; i++) {
    printf("%d ", i);
    fflush(stdout);
  }
  if (id != 0)
    printf("\n");

  return 0;
}