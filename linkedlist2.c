#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertAtBeginning(Node **head, int newData) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = newData;
  newNode->next = *head;
  *head = newNode;
}

void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
  printf("Linked List: ");
  printList(head);
  return 0;
}