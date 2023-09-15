#include <stdbool.h>
#include <stdio.h>

bool validMountainArray(int *arr, int arrSize);

int main(int argc, char *argv[]) {
  int arr1[] = {2, 1};
  int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
  bool result1 = validMountainArray(arr1, arrSize1);
  printf("Output: %s\n", result1 ? "true" : "false");
  // Output: false

  int arr2[] = {3, 5, 5};
  int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
  bool result2 = validMountainArray(arr2, arrSize2);
  printf("Output: %s\n", result2 ? "true" : "false");
  // Output: false

  int arr3[] = {0, 3, 2, 1};
  int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
  bool result3 = validMountainArray(arr3, arrSize3);
  printf("Output: %s\n", result3 ? "true" : "false");
  // Output: true

  return 0;
}
bool validMountainArray(int *A, int arrSize) {
  int i = 0;
  int j = arrSize - 1;

  while (i + 1 < arrSize && A[i] < A[i + 1])
    i++;
  while (j > 0 && A[j - 1] > A[j])
    j--;

  printf("%d %d\n", i, j);

  return i > 0 && i == j && j < arrSize - 1;
}
