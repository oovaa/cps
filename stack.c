#include <stdio.h>

#define MAX 101
int A[MAX];
int top = -1;

void push(int x) {
  if (top == MAX - 1) {
    printf("Error: stack is full");
    return;
  }
  A[++top] = x;
}
void printStack() {
  for (int i = 0; i <= top; i++) {
    printf("%d ", A[i]);
  }
}
int pop() {
  if (top == -1) {
    printf("Error: stack is full");
    return -1;
  }
  return top--;
}

int main(int argc, char const *argv[]) {
  push(1);
  push(2);
  push(3);
  pop();
  push(4);
  printStack();
  return 0;
}
