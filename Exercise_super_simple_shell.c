#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char **arr;
  char *command = NULL;
  int i, j = 0;
  size_t line = 0;
  while (1) {
    printf("#OmarIsCool$ ");
    getline(&command, &line, stdin);
    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0) {
      exit(0);
    }

    arr = malloc(sizeof(char *) * 100);
    if (arr == NULL) {
      perror("the array is not allocated");
      return -1;
    }

    arr[j] = malloc(sizeof(char) * 100);

    for (i = 0; command[i]; i++) {

      if (arr[j] == NULL) {
        perror("the string is not allocated");
        return -1;
      }

      if (command[i] == ' ') {
        arr[j][i] = '\0';
        ++j;
        ++i;
        arr[j] = malloc(sizeof(char) * 100);
      }

      strncat(arr[j], &command[i], 1);
    }
    arr[j + 1] = NULL;

    // handel command in a child process
    int pid = fork();
    if (pid == 0) {
      execvp(arr[0], arr);
    } else {
      wait(NULL);
    }
  }

  // Free allocated memory
  for (int i = 0; i <= j; i++) {
    free(arr[i]);
  }
  free(arr);

  free(command);
  return 0;
}