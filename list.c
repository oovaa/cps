#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int size = -1;
int Capacity = 5;
int *cp;

void add(int i);
int Remove(int i);
void print();
void set(int i, int v);
void insert(int index, int val);

int main(int argc, char const *argv[]) {
  cp = malloc(sizeof(int) * 5);
  int n = 0;
  while (n < 10) {
    add(n++);
  }
  print();
  int removed_element = Remove(3);
  printf("------------------\n");
  insert(3, 4);
  print();
  // printf("last %d\n", cp[size]);

  printf("removed_element = %d\n", removed_element);

  // n=11;
  // printf("%d,%d", n, n *= 2);

  // printf("%d", cp[94]);
  // for (int i = 0; i < 94; i++) {
  //   if (cp[i] != cp[i + 1] - 1) {
  //     printf("i = %d i+1 = %d [i] = %d [i+1] = %d  \n", i, i + 1, cp[i],
  //            cp[i + 1]);
  //   }
  // }

  // printf("%p\n", cp);
  // printf("%d\n", *cp);
  // cp[0] = 1;
  // int n = 1;
  // printf("cp[3]=%d\n", cp[3]);

  // while (true) {
  //   add(n++);
  // }

  //   int a[] = {1, 3, 4};
  //   int *p = a + 1;
  //   p[1] = 5;

  //   printf("%d\n", a[2]);
  //   printf("%d\n", p[1]);
  free(cp);
  return 0;
}
void add(int i) {
  if (size == Capacity) {
    Capacity *= 2;
    cp = realloc(cp, Capacity * sizeof(int));
  }
  cp[size++] = i;
  // printf("cp[%d]=%d\n", size, cp[size - 1]); // Corrected index
  // printf("%d\n", Capacity);
}

int Remove(int targetindex) {
  int t = cp[targetindex];
  for (int i = targetindex; i + 1 < size; i++) {
    cp[i] = cp[i + 1];
  }
  size--;
  return t;
}

void print() {
  for (int i = 0; i < size; i++) {
    printf("cp[%d]=%d\n", i, cp[i]); // Corrected index
  }
}

void set(int i, int v) { cp[i] = v; }
bool isEmpty() { return size == -1; }

void insert(int index, int val) {
  size++;
  int i;
  for (i = size - 1; i > index; i--) {
    cp[i + 1] = cp[i];
  }
  cp[i] = val;
}
// void add(int i) {
//   if (size < Capacity)
//     cp[size++] = i;
//   else {
//     Capacity *= 2;
//     cp = realloc(cp, Capacity * sizeof(int));
//     size = Capacity / 2;
//     cp[size++] = i;

// printf("new capacity is %d \n", Capacity);
// printf("%d\n", Capacity);

// printf("i is %d \n", i);

// printf("cp[%d]=%d\n", size, cp[size - 1]);
// size++;
// printf("i is %d \n", cp[i]);
// time.sleep
// }
