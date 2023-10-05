#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *buf;
  size_t len = 0;
  ssize_t read;
  char *hold;
  printf("$: ");

  read = getline(&buf, &len, stdin);
  buf[strcspn(buf, "\n")] = '\0';

  hold = strtok(buf, " ");
  while (hold != NULL) {
    printf("%s\n", hold);
    hold = strtok(NULL, " ");
  }

  free(buf);

  /*   char *buf = NULL;
    size_t len = 0;
    ssize_t read;

    int file = open("text.txt", O_RDONLY);
    if (file == -1) {
      perror("Failed to open file");
      return 1;
    }
    FILE *fd = fdopen(file, "r");

    while ((read = getline(&buf, &len, fd)) != EOF) { //EOF | -1 THE SAME
      printf("%.*s", (int)read, buf);
    }
    printf("\n");


    free(buf);
    close(file);
    return 0; */
  // printf("$: ");
  // fflush(stdout);

  // scanf("%[^\n]s", buf);

  // getline(&buf, &len, stdin); // Read a line using getline
}
// scanf("%s");

// char buf2[256];
// printf("$: ");

// scanf("%[^\n]s", buf2);

// printf("the text is: %s\n", buf2);