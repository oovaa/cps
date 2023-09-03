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
void revprint();
void printpreslist();

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
  printpreslist();
  revprint();

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
  Node *cur = first;
  while (cur->next != NULL) {
    printf("%d->", cur->data);
    cur = cur->next;
  }
  printf("%d\n", cur->data);
}

void printpreslist() { // print all pre nodes
  struct Node *cur = first->next;
  while (cur != NULL) {
    printf("%d->", cur->pre->data);
    if (cur->next == NULL)
      printf("%d\n", cur->data);
    cur = cur->next;
  }
}
void revprint() {
  Node *t = head;
  while (t->pre != NULL) {
    printf("%d->", t->data);
    if (t->pre->pre == NULL)
      printf("%d\n", t->pre->data);
    t = t->pre;
  }
}

// void printpreslist() { // print all pre nodes
//   struct Node *cur = first->next;
//   while (cur->next != NULL) {
//     printf("%d->", cur->pre->data);
//     cur = cur->next;
//   }
//   printf("%d->", cur->pre->data);
//   printf("%d\n", cur->data);
// }