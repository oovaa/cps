#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  pid_t zid;

  for (size_t i = 0; i < 5; i++) {

    zid = fork();

    if (zid < 0)

      perror("fork failed");
    else if (zid == 0) {
      sleep(3);
      exit(0);
    } else {
      printf("the zid is : %d\n", zid);
      sleep(1);
    }
  }
  while (1)
    sleep(1);

  return 0;
}
