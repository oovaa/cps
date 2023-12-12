
#include "sorting_algorithms.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArray(int arr[], int size);
// Swap function
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Bubble Sort
void bubble_sort(int *array, size_t size) {
  int i, j;

  for (i = 0; i < size; i++)
    for (j = 1; j < size; j++)
      if (array[j] < array[j - 1])
        swap(&array[j], &array[j - 1]);
}

// Selection Sort
void selection_sort(int *array, size_t size) {
  int min_idx, i, j;

  for (i = 0; i < size; i++) {
    min_idx = i;

    for (j = i + 1; j < size; j++)
      if (array[min_idx] > array[j])
        min_idx = j;
    swap(&array[min_idx], &array[i]);
  }
}

int partition(int *array, size_t start, size_t end) {
  int pivot = array[end];
  int i = start - 1, j;

  for (j = start; j < end; j++)
    if (array[j] < pivot)
      swap(&array[++i], &array[j]);

  swap(&array[++i], &array[end]);
  return i;
}

void quick_rec(int *array, int start, int end) {
  int pivot;

  if (start >= end)
    return;

  pivot = partition(array, start, end);

  if (pivot > 0 && start < pivot - 1)
    quick_rec(array, start, pivot - 1);

  quick_rec(array, pivot + 1, end);
}

void quick_sort(int *array, size_t size) { quick_rec(array, 0, (int)size - 1); }

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void shell_sort(int *array, size_t size) {
  int i, j, gap;
  for (gap = size / 2; gap > 0; gap /= 2)
    for (i = gap; i < size; i++)
      j = i;
  while (j >= gap && array[j] > array[j - gap])
    swap(&array[j], &array[(j -= gap) - gap]);
}

// Test the sorting algorithms
int main() {
  time_t start = 
  int arr[] = {6, 1, 9, 2, 7, 8, 4, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int start = time.
  quick_sort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}

// Insertion Sort
// void insertion_sort_list(listint_t **list);

// Merge Sort
// ... Merge sort code goes here ...

// Quick Sort
// ... Quick sort code goes here ...

// Heap Sort
// ... Heap sort code goes here ...

// Shell Sort
// ... Shell sort code goes here ...

// Counting Sort
// ... Counting sort code goes here ...

// Radix Sort
// ... Radix sort code goes here ...

// Bucket Sort
// ... Bucket sort code goes here ...

// TimSort
// ... TimSort code goes here ...

// Comb Sort
// ... Comb sort code goes here ...

// Pigeonhole Sort
// ... Pigeonhole sort code goes here ...

// Cycle Sort
// ... Cycle sort code goes here ...

// Bitonic Sort
// ... Bitonic sort code goes here ...

// BogoSort (Stupid Sort)
// ... BogoSort code goes here ...

// Gnome Sort
// ... Gnome sort code goes here ...

// Cocktail Shaker Sort
// ... Cocktail Shaker sort code goes here ...

// Sleep Sort (Theoretical/Humorous)
// ... Sleep Sort code goes here ...