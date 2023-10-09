#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;
int main(int argc, char *argv[]) {
printf("%s\n", environ[24]);


  return 0;
}