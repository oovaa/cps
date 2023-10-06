#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
/* int main(void) {
  pid_t my_pid;
  pid_t child_pid;

  child_pid = fork();
  if (child_pid == -1) {
    perror("Error:");
    return (1);
  }
  my_pid = getpid();
  printf("My pid is %u\n", my_pid);
  if (child_pid == 0) {
    printf("(%u) Nooooooooo!\n", my_pid);
    exit(0);
  } else {
    printf("(%u) %u, I am your father\n", my_pid, child_pid);
  }
  return (0);
} */

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void) {
  pid_t parent;
  pid_t child;

  printf("pefore the fork\n");

  child = fork();
  parent = getpid();

  if (child != 0)
    printf("1 - after the fork child is : %u and daddy is %u\n", child, parent);

  else
    printf("2 - after the fork\n");

  if (child == 0) {
    char *argv[] = {"/bin/pwd", NULL};

    printf("Before execve %s\n", argv[0]);
    if (execl(argv[0], "/bin/pwd", NULL) == -1) {
      perror("Error");
    }
  }

  wait(NULL);
  printf("My ID is: %u\n", parent);
  // printf("Child process finished\n");
}

/*
int main(int argc, char *argv[]) {

  int id = fork();
  int n;
  if (id == 0)
    n = 1;
  else
    n = 6;

  int status;
  if (id != 0)
    wait(NULL);

  for (int i = n; i < n + 5; i++) {
    printf("%d ", i);
    fflush(stdout);
  }
  if (id != 0)
    printf("\n");

  return 0;
} */
