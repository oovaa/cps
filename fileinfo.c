#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av) {
  unsigned int i;
  struct stat st;

  if (ac < 2) {
    printf("Usage: %s path_to_file ...\n", av[0]);
    return (1);
  }
  i = 1;
  while (av[i]) {

    printf("%s:", av[i] += 2);
    if (stat(av[i], &st) == 0) {
      printf(" FOUND %ld \n", st.st_dev);

    } else {
      printf(" NOT FOUND\n");
    }
    i++;
  }
  return (0);
}
