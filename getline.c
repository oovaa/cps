#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 1024

static char buffer[BUFSIZE];
static int buf_pos = 0;

char *my_getline(void) {
  int ch;
  int pos = 0;
  int bytesRead;

  while ((bytesRead = read(STDIN_FILENO, &ch, 1)) > 0) {
    if (pos >= BUFSIZE - 1) {
      buffer[pos % BUFSIZE] = ch;
      pos++;
      if (pos % BUFSIZE == 0) {
        buf_pos = fread(buffer, 1, BUFSIZE, stdin);
      }
    } else {
      buffer[pos] = ch;
      pos++;
    }

    if (ch == '\n') {
      break;
    }
  }

  if (bytesRead == -1) {
    perror("read error");
  }

  buffer[pos] = '\0';
  return buffer;
}

int main(int argc, char *argv[]) {

  char *o = my_getline();

  printf("%s\n", o);

  /*   char *buf;
    size_t len = 0;
    ssize_t read;
    char *hold;

      printf("$: ");
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
      close(file); */
  return 0;

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

/*   read = getline(&buf, &len, stdin);
  buf[strcspn(buf, "\n")] = '\0';

  hold = strtok(buf, " ");
  while (hold != NULL) {
    printf("%s\n", hold);
    hold = strtok(NULL, " ");
  }

  free(buf); */