#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *pre;
} Node;
void rev();
void add(int a);
void insert(int location, int data);
struct Node *delete (int a);
void printlist();
void printrec(Node *start);
void revprintrec(Node *start);

Node *first;
Node *head;

int main() {

  int count;
  int val;
  printf("how many u wanna add to the linked list?\n");
  scanf("%d", &count);

  for (int i = 0; i < count; i++) {
    printf("enter number:\n");
    scanf("%d", &val);
    add(val);
  }
  printlist();
  return 0;
}

void add(int a) {
  Node *t = (Node *)malloc(sizeof(Node));
  t->data = a;
  if (first == NULL) {
    first = t;
    head = t;
  } else {
    head->next = t;
    t->pre = head;
    head = head->next;
  }
}
void insert(int location, int data);

struct Node *delete (int a);

void printrec(struct Node *start);

void revprintrec(struct Node *start);

void printlist() {
  struct Node *cur = first;
  while (cur->next != NULL) {
    printf("%d->", cur->data);
    cur = cur->next;
  }
  printf("%d\n", cur->data);
}