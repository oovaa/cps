#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
  int i, j, last = 0;
  char *tmp;

  while (environ[last + 1])
    last++;

  for (i = 0; environ[i]; i++) {
    if (strncmp(name, environ[i], strlen(name)) == 0) {
      tmp = environ[i];
      environ[i] = environ[last];
      environ[last] = NULL;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) { // Set environment variables
  setenv("VAR1", "Value1", 1);
  setenv("VAR2", "Value2", 1);
  setenv("VAR3", "Value3", 1);

  // Print all environment variables
  printf("Environment variables:\n");
  for (int i = 0; environ[i] != NULL; i++) {
    printf("%s\n", environ[i]);
  }

  printf("\n");

  // Unset an environment variable
  _unsetenv("VAR1");

  // Print all environment variables after unset
  printf("Environment variables after unset:\n");
  for (int i = 0; environ[i] != NULL; i++) {
    printf("%s\n", environ[i]);
  }

  return 0;
}