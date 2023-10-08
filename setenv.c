#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int setenv(const char *name, const char *value, int overwrite) {
  if (name == NULL || value == NULL || strchr(name, '=') != NULL) {
    return -1; // Invalid input
  }

  if (!overwrite && getenv(name) != NULL) {
    return 0; // Variable already exists and overwrite is not allowed
  }

  size_t len = strlen(name) + strlen(value) + 2; // +2 for '=' and '\0'
  char *var = (char *)malloc(len);
  if (var == NULL) {
    return -1; // Failed to allocate memory
  }

  snprintf(var, len, "%s=%s", name, value);
  int result = putenv(var); // Set the environment variable

  if (result != 0) {
    free(var);
    return -1; // Failed to set the environment variable
  }

  return 0; // Success
}
int main(int argc, char *argv[]) {
  const char *varName = "MY_VARIABLE";
  const char *varValue = "Hello, World!";
  int overwrite = 1,
      id; // Set to 1 to overwrite if the variable already exists

  id = fork();
  if (id == 0) {
    _setenv(varName, varValue, overwrite);
    perror("setenv didnt work");
    return -1;
  } else {
    wait(NULL);
    printf("child process has ended");
  }

  return 0;
}