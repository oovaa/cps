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
  int j = 0;
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

    char *token = strtok(command, " ");
    while (token != NULL) {
      arr[j] = malloc(sizeof(char) * 100);
      if (arr[j] == NULL) {
        perror("the string is not allocated");
        return -1;
      }
      strcpy(arr[j], token);
      token = strtok(NULL, " ");
      j++;
    }

    arr[j] = NULL;

    // handle command in a child process
    int pid = fork();
    if (pid == 0) {
      execvp(arr[0], arr);
      perror("execvp failed"); // Print an error message if execvp fails
      exit(1);
    } else {
      wait(NULL);
    }

    // Free allocated memory
    for (int i = 0; i < j; i++) {
      free(arr[i]);
    }
    j = 0;

    free(arr);
    free(command);
    command = NULL;
  }

  return 0;
}
