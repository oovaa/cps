#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {


int fileDescriptor = open("new_file.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
  // int to_read = open("text.txt", O_RDONLY);
  // int to_write = open("new_text.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

  // if (to_read == -1 || to_write == -1) {
  //   printf("coudnt open a file \n");

  //   return -1;
  // }
  // char c;
  // int b;
  // while ((b = read(to_read, &c, sizeof(c))) > 0) {
  //   if (c == 'o' || c == 'e' || c == 'm')
  //     c = ';';

  //   write(to_write, &c, sizeof(c));
  // }

  // close(to_read);
  // close(to_write);
  return 0;
}