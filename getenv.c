#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcspn
extern char **environ;

char *_getenv(char *name) {
  char *val = NULL;
  int len = strlen(name);
  for (int i = 0; environ[i]; i++) {

    if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=') {
      val = environ[i] + len + 1;
      break;
    }
  }

  return val;
}

int main() {
  //   char *n = "omar", a = 'a';
  //   int i = strcspn(n, &a);
  //   printf("%d\n", i);

  // Test different environment variables
  char *path = _getenv("PATH");
  if (path != NULL) {
    printf("PATH: %s\n", path);
  } else {
    printf("PATH environment variable not found.\n");
  }

  char *home = _getenv("HOME");
  if (home != NULL) {
    printf("HOME: %s\n", home);
  } else {
    printf("HOME environment variable not found.\n");
  }

  char *user = _getenv("USER");
  if (user != NULL) {
    printf("USER: %s\n", user);
  } else {
    printf("USER environment variable not found.\n");
  }

  char *shell = _getenv("SHELL");
  if (shell != NULL) {
    printf("SHELL: %s\n", shell);
  } else {
    printf("SHELL environment variable not found.\n");
  }

  char *lang = _getenv("LANG");
  if (lang != NULL) {
    printf("LANG: %s\n", lang);
  } else {
    printf("LANG environment variable not found.\n");
  }
  return 0;
}