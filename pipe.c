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
    printf("enter number :  ");
    scanf("%d", &x);
    write(fd[1], &x, sizeof(int));
    close(fd[1]);
  } else {
    int y;
    close(fd[1]);
    read(fd[0], &y, sizeof(int));
    close(fd[0]);
    printf("the y is %d\n", y);
    
  }

  return 0;
}