#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd[2];
  if (pipe(fd) == -1) {
    printf("an error has accured\n");
    return 1;
  }
  int id = fork();
  if (id == 0) {
    close(fd[0]);
    int x;
    printf("Enter number: ");
    fflush(stdout);
    scanf("%d", &x);
    if (write(fd[1], &x, sizeof(int)) == -1)
      return 2;
    close(fd[1]);
  } else {
    int y;
    close(fd[1]);
    if (read(fd[0], &y, sizeof(int)) == -1)
      return 3;
    close(fd[0]);
    y += 1;
    printf("The y is %d\n", y);
    wait(NULL);
  }
  return 0;
}