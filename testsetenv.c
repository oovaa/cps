#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int _setenv(const char *name, const char *value, int overwrite) {
char *exp = "/usr/bin/export"; 


}
int main(int argc, char *argv[]) {
  const char *varName = "MY_VARIABLE";
  const char *varValue = "Hello!";
  int overwrite = 1;
  int result = _setenv(varName, varValue, overwrite);

  if (result == 0) {
    // Check if the environment variable was added successfully
    char *envVar = getenv(varName);
    if (envVar != NULL) {
      printf("Environment variable %s set to %s.\n", varName, envVar);
    } else {
      printf("Failed to set the environment variable envVar :%s.\n", varName);
    }
  } else {
    printf("Failed to set the environment variable  is null  %s.\n", varName);
  }

  return 0;
}