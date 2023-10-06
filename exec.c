#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve %s\n", argv[0]);
    if (execl(argv[0], "/bin/ls", "-l", "/usr/", NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}


/* #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
    execlp("neofetch", "neofetch", NULL);
    return 0;
} */