#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {

  char *fullvar = malloc(strlen(name) + strlen(value) + 2);
  char **newenv;
  int i;
  int count = 0;

  while (environ[count] != NULL)
    count++;

  strcpy(fullvar, name);
  strcat(fullvar, "=");
  strcat(fullvar, value);
  // printf("%s\n\n", fullvar); passed

  for (i = 0; environ[i]; i++) {
    if (strncmp(name, environ[i], strlen(name)) == 0 && overwrite == 1) {
      free(environ[i]);
      environ[i] = strdup(fullvar);
      return 0;
    } else if (strncmp(name, environ[i], strlen(name)) == 0 && overwrite == 0) {
      free(fullvar);
      return 0;
    }
  }

  newenv = malloc((count + 2) * sizeof(char *));
  for (i = 0; i < count; i++)
    newenv[i] = environ[i];

  newenv[i] = fullvar;
  // printf("%d\n", i); 

  environ = newenv;

  return 0;
}

int main(int argc, char *argv[], char *env[]) {
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

// old one
// int _setenv(const char *name, const char *value, int overwrite) {

//   char *com = malloc(strlen(name) + strlen(value) + 2);
//   char *arr[] = {"export", com, NULL};
//   char **env = environ;
//   int id;

//   if (com == NULL) {
//     perror("malloc");
//     return -1;
//   }

//   printf("%s\n", com);

//   strcpy(com, name);
//   com[strlen(name)] = '=';
//   strcpy(com + strlen(name) + 1, value);

//   id = fork();
//   if (id == -1) {
//     perror("fork");
//     free(com);
//     return -1;
//   }
//   if (id == 0) {
//     execve(arr[0], arr, env);
//     perror("execve didnt work");
//     return -1;
//   } else
//     wait(NULL);
//   return 0;
// }