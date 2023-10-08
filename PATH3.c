#include <stdio.h>
#include <string.h>

extern char **environ;

char *gpath() {
  char *path = NULL;
  int len = strlen("PATH");

  for (int i = 0; environ[i]; i++) {
    if (strncmp(environ[i], "PATH", len) == 0) {
      path = environ[i] + 5;
      break;
    }
  }
  return path + 1;
}
int getlastslasidx(char *str) {
  int idx = 0;
  char slsh = '/';
  for (size_t i = 0; str[i]; i++) {
    if (strncmp(&str[i], &slsh, 1) == 0)
      idx = i;
  }
  return idx;
}
void ppath() {
  char *path = gpath(), *tok = NULL, del = ':';
  int slashidx;

  tok = strtok(path, &del);
  while (tok) {
    int slashidx = getlastslasidx(tok);

    printf("%s\n", tok + slashidx + 1);
    tok = strtok(NULL, &del);
  }
}

int main(int argc, char *argv[]) {

  ppath();
  return 0;
}
