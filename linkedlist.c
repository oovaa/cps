#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
void rev();
void add(int a);
void insert(int location, int data);
struct Node *delete (int a);
void printlist();
void printrec(struct Node *start);
void revprintrec(struct Node *start);

struct Node *first;
struct Node *head;

int main(void) {
  int count;
  int val;
  printf("how many u wanna add to the linked list?\n");
  scanf("%d", &count);

  for (int i = 0; i < count; i++) {
    printf("enter number:\n");
    scanf("%d", &val);
    add(val);
    // printf("head val = %d\n",head->data);
  }
  //   delete (1);
  insert(4, 5);
  // printlist();
  // rev();
  revprintrec(first);

  return 0;
}

void rev() { // reverse the linked list
  struct Node *cur = first;
  struct Node *pre = NULL;
  struct Node *after;
  while (cur != NULL) {
    after = cur->next;
    cur->next = pre;
    pre = cur;
    cur = after;
  }
  first = pre;
}

void insert(int location, int data) { // insert a node in a given index
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = data;
  struct Node *cur = first;
  int i = 0;
  if (location != 1) {
    while (i < location - 2) {
      if (cur == NULL) {
        printf("INVALID!!");
        return;
      } else
        cur = cur->next;
      i++;
    }

    t->next = cur->next;
    cur->next = t;
  } else {
    t->next = first;
    first = t;
  }
}

void add(int a) {
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->data = a;
  // head = t;
  t->next = NULL;

  if (first == NULL) {
    first = t;
    head = t;
  } else {
    head->next = t;
    head = t;
  }
}
struct Node *delete (int a) {
  struct Node *cur = first;
  while (cur->next != NULL && cur->next->data != a) {
    cur = cur->next;
  }

  if (cur->next == NULL) {
    printf("NOT FOUND!!");
    return NULL;
  }

  cur->next = cur->next->next;
  struct Node *t = cur->next;
  return t;
}

// head = t;
// if(first != NULL && first->next == NULL)  first->next = head;

void printrec(struct Node *start) {
  if (start->next == NULL) {
    printf("%d\n", start->data);
    return;
  }
  printf("%d -> ", start->data);
  printrec(start->next);
}

void revprintrec(struct Node *start) {
  if (start == NULL) {
    return;
  }
  revprintrec(start->next);
  printf("%d -> ", start->data); // TODO: fix the last arrow thing
}

void printlist() {
  struct Node *cur = first;
  while (cur->next != NULL) {
    printf("%d->", cur->data);
    cur = cur->next;
  }
  printf("%d\n", cur->data);
}
