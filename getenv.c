#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcspn
extern char **environ;

char *_getenv(char *name) {
  char *val = NULL, *hold = NULL, eql = '=';
  int eqlidx;
  for (int i = 0; environ[i]; i++) {
    eqlidx = strcspn(environ[i], &eql);
    if (strncmp(name, environ[i], eqlidx) == 0) {
      val = environ[i] + eqlidx;
    }
  }

  return val;
}

int main() {
  //   char *n = "omar", a = 'a';
  //   int i = strcspn(n, &a);
  //   printf("%d\n", i);

  char *home_dir = _getenv("HOME");
  if (home_dir != NULL) {
    printf("Home directory: %s\n", home_dir);
  } else {
    printf("Home directory not found.\n");
  }

  return 0;
}