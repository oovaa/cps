
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Test the sorting algorithms
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Call sorting functions here, for example:
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    // Add more tests for other sorting functions

    return 0;
}
