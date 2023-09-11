#include <stdio.h>

void print_name(char *name, void (*f)(char *));
void print_name_as_is(char *name);
void print_name_uppercase(char *name);
void array_iterator(int *array, size_t size, void (*action)(int));
void print_elem_hex(int elem);
int int_index(int *array, int size, int (*cmp)(int));
int is_0(int elem);

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

void tas() { printf("take a shit\n"); }

void sat() { printf("shit a take\n"); }

void exe(void (*fn)()) { fn(); }

int main() {
  int one[] = {12, 0, 5, 154, 87, 78, 124};
  int size = sizeof(one) / sizeof(int);
  // array_iterator(one, 7, &print_elem_hex);
  int index = int_index(one, 7, &is_0);
  printf("%d\n", index);

  // bubble_sort(one, size, is_smaller);
  // bubble_sort(one, size, is_greater);
  // bubble_sort(one, size, &second_digit);
  // print_arr(one, size);
  // printf("%s\n", __DATE__);
  // printf("%s\n", __TIME__);
  // printf("%d\n", __LINE__);
  // printf("%d\n", __STDC__);

  // exe(&sat);
  // exe(&tas);

  // print_name("omar", &print_name_as_is);
  // print_name("omar", &print_name_uppercase);

  return 0;
}
int int_index(int *array, int size, int (*cmp)(int)) {
  for (int i = 0; i < size; i++) {
    if (cmp(array[i]))
      return i;
  }
  return -1;
}

int is_0(int elem) { return (elem == 0); }

void print_elem_hex(int elem) { printf("%d\n", elem); }

void array_iterator(int *array, size_t size, void (*action)(int)) {
  for (size_t i = 0; i < size; i++)
    action(array[i]);
}

void print_name(char *name, void (*f)(char *)) { f(name); }

void print_name_as_is(char *name) { printf("Hello, my name is %s\n", name); }

void print_name_uppercase(char *name) {
  unsigned int i;

  printf("Hello, my uppercase name is ");
  i = 0;
  while (name[i]) {
    if (name[i] >= 'a' && name[i] <= 'z') {
      putchar(name[i] + 'A' - 'a');
    } else {
      putchar(name[i]);
    }
    i++;
  }
  putchar('\n');
}