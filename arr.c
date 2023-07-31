#include <stdio.h>

int main() {
  int nums[][3] = {{3, 6}, {1, 3}, {78, 12}};

  for (int i = 0; i < sizeof(nums) / sizeof(nums[1]); i++) {
    for (int l = 0; l < sizeof(nums[1]) / sizeof(nums[1][1]); l++) {
      int x = l + i * sizeof(nums) / sizeof(nums[1]);
      printf("%d   ", x);
    }
  }

  char s;
  printf("\nenter a symble: \n");
  scanf(" %c", &s);
  printf("enter a symble: \n");
  scanf(" %c", &s); // the space matters it clears the buffer i think
  // scanf("%c");
  for (int i = 0; i < 10; i++) {
    for (int l = i; l < 10; l++) {
      printf("%c  ", s);
    }
    printf("\n");
  }
}