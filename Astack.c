#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Astack {

  void **arr;
  int top;

} Astack;

Astack init() {
  Astack stack;
  stack.arr = malloc(MAX_SIZE * sizeof(void *));
  if (stack.arr == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  stack.top = -1;
  return stack;
}

void printstack(Astack stack) {
  // for (int i = 0; i <= stack.top; i++)
  // printf("[%d] = %d\n", i , stack.arr[i]);
}

void push(Astack *stack, void *data) {
  if (stack->top == MAX_SIZE - 1) {
    printf("Stack is full. Cannot push more elements.\n");
    return;
  }
  stack->arr[++stack->top] = data;
}

void *pop(Astack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty. Cannot pop more elements.\n");
    return NULL;
  }
  stack->top--;
  return stack->arr[stack->top + 1];
}

int main(void) {
  Astack stack = init();
  int num1 = 4;
  push(&stack, &num1);
  int num2 = 2;
  push(&stack, &num2);
  void *tmp = pop(&stack);

  printf("%d\n", stack.top);
  printf("%d\n", *((int *)tmp));
  printf("%d\n", *((int *)(stack.arr[stack.top])));

  return 0;
}
