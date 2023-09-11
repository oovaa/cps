#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int sum(int num, ...);
void print(char *placeholders, ...);

int main(int argc, char *argv[]) {
  int s = sum(5, 4, 5, 6, 2, 7);
  printf("s = %d\n", s);

  print("ddff", 1, 2, 4.4, 5.7);

  return 0;
}

void print(char *placeholders, ...) {
  int len = strlen(placeholders);
  va_list args;
  va_start(args, placeholders);
  for (size_t i = 0; i < len; i++) {
    if (placeholders[i] == 'd') {
      int x = va_arg(args, int);
      printf("%d  ", x);
    }
    if (placeholders[i] == 'f') {
      double x = va_arg(args, double);
      printf("%.2lf  ", x);
    }
  }
}

int sum(int num, ...) {
  int s = 0;
  va_list args;
  va_start(args, num);
  for (int i = 0; i < num; i++) {
    s += va_arg(args, int);
  }

  return s;
}
