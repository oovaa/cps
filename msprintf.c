#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
int maput(char c);

int _printf(const char *format, ...) {
  int i, j;
  va_list args;
  va_start(args, format);
  char *hold;
  char inthold;

  for (i = 0; format[i]; i++) {
    switch (format[i + 1]) {
    case 'c':
      inthold = va_arg(args, int);
      maput(inthold);
      i++;
      break;
    case 's':
      hold = va_arg(args, char *);
      j = 0;
      while (hold[j]) {
        maput(hold[j++]);
      }
      i++;
      break;
    default:
      maput(format[i]);
      break;
    }
  }

  return i;
}
int main(int argc, char *argv[]) {
  printf("%d\n", _printf("i am omar im %c man %s\n", 'A', "i like coding"));
  return 0;
}
int maput(char c) {
  return (write(1, &c, 1));
} // Write a function that produces output according to a format.

// Prototype: int _printf(const char *format, ...);
// Returns: the number of characters printed (excluding the null byte used to
// end output to strings) write output to stdout, the standard output stream
// format is a character string. The format string is composed of zero or more
// directives. See man 3 printf for more detail. You need to handle the
// following conversion specifiers:
// c
// s
// %
// You don’t have to reproduce the buffer handling of the C library printf
// function You don’t have to handle the flag characters You don’t have to
// handle field width You don’t have to handle precision You don’t have to
// handle the length modifiers