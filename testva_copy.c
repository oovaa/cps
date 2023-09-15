#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

void print_arguments(va_list args)
{
    va_list args_copy;
    va_copy(args_copy, args);
    
    int num;
    while ((num = va_arg(args_copy, int)) != -1) {
        printf("%d ", num);
    }
    printf("\n");
    
    va_end(args_copy);
}

void print_all(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        print_arguments(args); // Invoke the helper function
        printf("---------\n");
    }

    va_end(args);
}

int main()
{
    // print_all(3, 1, 2, -1, 3, 4, 5, -1, 6, 7, 8, -1);   

    const char *message = "Hello, world!";
    size_t len = strlen(message);
    ssize_t bytes_written = write(1, message, len);

    return 0;
}