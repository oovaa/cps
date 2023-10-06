#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void dothething() {
  char *args[] = {"ls", "-l", "/tmp", NULL};
  //   char *args[] = {"pwd", NULL};
  int id = fork();
  if (id == 0)
    execvp(args[0], args);
  else
    wait(NULL);
}

int main(int argc, char *argv[]) {
  for (int i = 0; i < 5; i++) {
    dothething();
  }

  return 0;
}