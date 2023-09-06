#include <stdio.h>

static void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int *arr, int size, int (*cmp)(int, int)) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j + 1 < size; j++) {
      if (cmp(arr[j], arr[j + 1]))
        swap(&arr[j], &arr[j + 1]);
    }
  }
}
int isgreater(int a, int s) { return a > s; }
int isSmaller(int a, int s) { return a < s; }
int second_digit(int a, int s) { return (a / 10) % 10 > (s / 10) % 10; }

void print_arr(int *arr, int size) {
  printf("{ ");

  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  printf("}\n");
}

int main() {
  int one[] = {12, 0, 5, 154, 87, 78, 124};
  int size = sizeof(one) / sizeof(int);

  // bubble_sort(one, size, is_smaller);
  // bubble_sort(one, size, is_greater);
  bubble_sort(one, size, &second_digit);
  print_arr(one, size);

  return 0;
  return 0;
}