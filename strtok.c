#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *str = NULL;
  char delimiters = ' ';
  size_t l = 0;

  printf("$: ");
  getline(&str, &l, stdin);
  str[strcspn(str, "\n")] = '\0';

  int i, j = 0;
  char **arr = malloc(sizeof(char *) * 100);
  if (arr == NULL) {
    perror("the array is not allocated");
    return -1;
  }

  arr[j] = malloc(sizeof(char) * 100);

  for (i = 0; str[i]; i++) {

    if (arr[j] == NULL) {
      perror("the string is not allocated");
      return -1;
    }

    if (str[i] == delimiters) {
      ++j;
      ++i;
      arr[j] = malloc(sizeof(char) * 100);
    }

    strncat(arr[j], &str[i], 1);
  }

  for (i = 0; arr[i]; i++) {
    printf("%s\n", arr[i]);
    free(arr[i]);
  }

  free(arr);

  return 0;
}
// char *token = strtok(str, delimiters);
// while (token != NULL) {
//     printf("%s\n", token);
//     token = strtok(NULL, delimiters);
// }