#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]) {
  for (size_t i = 0; environ[i]; i++) {
    printf("%s\n", environ[i]);
  }
  return 0;
}