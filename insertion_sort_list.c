#include "sorting_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

/**
* create_listint - Creates a doubly linked list from an array of integers
*
* @array: Array to convert to a doubly linked list
* @size: Size of the array
*
* Return: Pointer to the first element of the created list. NULL on
failure
*/
listint_t *create_listint(const int *array, size_t size) {
  listint_t *list;
  listint_t *node;
  int *tmp;
  list = NULL;
  while (size--) {
    node = malloc(sizeof(*node));
    if (!node)
      return (NULL);
    tmp = (int *)&node->n;
    *tmp = array[size];
    node->next = list;
    node->prev = NULL;
    list = node;
    if (list->next)
      list->next->prev = list;
  }
  return (list);
}

// Function to print an array
void print_list(listint_t *list) {

  listint_t *cur = list;

  while (cur->next) {
    printf("%d -> ", cur->n);
    cur = cur->next;
  }
  printf("%d\n", cur->n);
}
void insertion_sort_list(listint_t **list) {
  listint_t *cur = (*list)->next, *pre, *hold;

  while (cur) {
    pre = cur->prev;
    hold = cur->next;

    while (pre && cur->n < pre->n) {

      pre->next = cur->next;
      if (cur->next)
        cur->next->prev = pre;

      cur->prev = pre->prev;
      if (pre->prev)
        pre->prev->next = cur;

      if (pre->prev)
        pre->prev->next = cur;

      else
        *list = cur; // Update head if pre was the head
		
      pre->prev = cur;
      cur->next = pre;
      pre = cur->prev;
    }
    cur = hold;
  }
}

int main(void) {
  listint_t *list;
  int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
  size_t n = sizeof(array) / sizeof(array[0]);

  list = create_listint(array, n);
  if (!list)
    return (1);
  print_list(list);
  printf("\n");
  insertion_sort_list(&list);
  printf("\n");
  print_list(list);
  return (0);
}
