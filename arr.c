#include <stdio.h>

int main() {

  int a[] = {2,4,6,7,NULL};
  // int c = {2,4,6,7,NULL};
  int i = 0;
  int* p = a;
  printf("%d\n",*(p+2));
  
//  while (a[i] != NULL ) //hmmmm why ? 🤨
//  {
//   printf("%d\n",*(a+i++));
//  }
 
  
  // int nums[][3] = {{3, 6}, {1, 3}, {78, 12}};

  // for (int i = 0; i < sizeof(nums) / sizeof(nums[1]); i++) {
  //   for (int l = 0; l < sizeof(nums[1]) / sizeof(nums[1][1]); l++) {
  //     int x = l + i * sizeof(nums) / sizeof(nums[1]);
  //     printf("%d   ", x);
  //   }
  // }

  // char* s;
  // printf("\nenter a symble: \n");
  // scanf("%s", &s);
  // printf("enter a symble: \n");
  // scanf("%s", s); // the space matters it clears the buffer i think
  // scanf("%c");
  // for (int i = 0; i < 10; i++) {
  //   for (int l = i; l < 10; l++) {
  //     printf("%s",&s);
  //   }
  //   printf("\n");
  // }
}