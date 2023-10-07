#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern char **environ;

char *getpath(char **env) {
  char *ans = NULL;
  int i = 0;

  for (i = 0; env[i]; i++) {
    if (strncmp(env[i], "PATH", 4) == 0) {
      ans = strdup(env[i] + 5);
      break;
    }
  }

  return ans;
}

int main(int argc, char *argv[], char *env[]) {

  char *path = getpath(env), del = ':', *token, *com;
  size_t token_len, com_len;

  if (argc != 2) {
    perror("invalid number of args");
    return -1;
  }
  com = argv[1];
  com_len = strlen(com);

  token = strtok(path, &del);
  while (token) {
    token_len = strlen(token);
    char *modified_token = malloc((token_len + com_len + 2) * sizeof(char));
    if (modified_token == NULL) {
      perror("memory allocation failed");
      return -1;
    }

    strcpy(modified_token, token);
    strcat(modified_token, "/");
    strcat(modified_token, com);
    if (open(modified_token, O_RDONLY) != -1) {
      printf("%s\n", modified_token);
      return 0;
    }

    free(modified_token);
    token = strtok(NULL, &del);
  }

  return 0;
}