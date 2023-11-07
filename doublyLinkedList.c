#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *pre;
} Node;

void rev();
void add(int a);
void addfirst(int a);
void insert(int location, int data);
struct Node *deleteval(int val);
struct Node *deleteloc(int loc);
Node *removeFirst();
void printlist();
void printrec(Node *start);
void revprintrec(Node *start);
void revprint();
void printpreslist();

Node *first = NULL;
Node *head = NULL;

int main() {
  int val, loc;
  while (1) {
    printf("1.add node at the end\n2.Insertion at the Beginning\n3.Insertion "
           "at a Specific Position\n4.delete with val\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("enter val\n");
      scanf("%d", &val);
      add(val);
      break;

    case 2:
      printf("enter val\n");
      scanf("%d", &val);
      addfirst(val);
      break;
    case 3:
      printf("enter val\n");
      scanf("%d", &val);
      printf("enter loc\n");
      scanf("%d", &loc);
      insert(loc, val);
      break;
    case 4:
      printf("enter val\n");
      scanf("%d", &val);
      deleteval(val);
      break;
    case 5:
      printf("enter loc\n");
      scanf("%d", &loc);
      deleteloc(loc);
      break;
    default:
      exit(0);
      break;
    }

    printlist();
  }

  return 0;
}

void add(int a) {
  Node *newnode = malloc(sizeof(Node));
  newnode->data = a;

  if (head == NULL) {
    first = newnode;
    head = newnode;
    return;
  }
  Node *current = first;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = newnode;
  newnode->pre = current;
  head = newnode;
}

void addfirst(int a) {
  Node *newnode = malloc(sizeof(Node));
  newnode->data = a;
  if (first)
    first->pre = newnode;
  newnode->next = first;
  first = newnode;
}

void insert(int loc, int data) {
  Node *newnode = malloc(sizeof(Node));
  Node *cur = first;
  int i = 1;

  newnode->data = data;

  if (loc <= 0) {
    printf("Not a valid location\n");
    exit(EXIT_FAILURE);
  }

  if (loc == 1) {
    addfirst(data);
    return;
  }

  while (cur->next && i < loc) {
    cur = cur->next;
    i++;
  }
  if (i != loc - 1) {
    printf("Not a valid location\n");
    exit(EXIT_FAILURE);
  }
  newnode->pre = cur;
  newnode->next = cur->next;
  if (cur->next)
    cur->next->pre = newnode;
  if (cur->pre)
    cur->pre->next = newnode;
  cur->next = newnode;
}

struct Node *deleteval(int val) {
  Node *cur = first;
  while (cur != NULL) {
    if (cur->data != val) {
      cur = cur->next;
    }
    break;
  }
  if (cur == NULL) {
    printf("Not found\n");
    return NULL;
  }

  if (cur == first) {
    return removeFirst();
  }

  if (cur->pre)
    cur->pre->next = cur->next;
  if (cur->next)
    cur->next->pre = cur->pre;
  cur->next = NULL;
  cur->pre = NULL;
  return cur;
}

struct Node *deleteloc(int loc) {
  Node *cur = first;
  int i = 1;

  if (loc == 1)
    return removeFirst();

  while (cur != NULL && i != loc) {
    cur = cur->next;
    i++;
  }
  if (cur == NULL) {
    printf("Not found\n");
    return NULL;
  }
  if (cur->pre)
    cur->pre->next = cur->next;
  if (cur->next)
    cur->next->pre = cur->pre;

  cur->next = NULL;
  cur->pre = NULL;

  return cur;
}

Node *removeFirst() {
  Node *cur = first;
  first = first->next;
  first->pre = NULL;
  cur->next = NULL;
  return cur;
}

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