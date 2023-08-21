#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char arr[]);
int main() {

  // char name1[5]= "omar";
  // name[0]='o';
  // name[1]='m';
  // name[2]='a';
  // name[3]='r';
  // name[4]='\0';

  // printf("%s\n",name);
  // printf("%s\n",name1);
  // char name[5];
  // char name2[5];
  char *name = malloc(5 * sizeof(char)); // u gotta allocate
  char *name2 = malloc(5 * sizeof(char));
  scanf("%s", name);
  scanf("%s", name2);
  // printf("%s\n", name);
  // printf("%s\n", name2);
  // name[4] = *name2; // this only work on arrays
  printf("%s\n", name);

  //  add(&name[0]); //u can do this
  // add(name + 1); // u can do this
  // for (int i = 0; i < strlen(name); i++)
  //   printf("%d=%c\n", i, name[i]);

  // int g[4] = {1,2,5,6};

  // int a[] = {2,4,6,7,NULL};
  // int c = {2,4,6,7,NULL};
  // int i = 0;
  // int* p = a;
  //   printf("%d\n",*(p+2));

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

  // char *s;
  // printf("\nenter a symble: \n");
  // scanf("%s", &s);
  // printf("enter a symble: \n");
  // scanf("%s", &s); // the space matters it clears the buffer i think
  // // scanf("%s");
  // for (int i = 0; i < 10; i++) {
  //   for (int l = i; l < 10; l++) {
  //     printf("%s",&s);
  //   }
  //   printf("\n");
  // }
  free(name);
  free(name2);
}
void add(char *arr) {
  *arr = *arr + 1;
  printf("*arr=%c\n", *arr);
  for (size_t i = 0; i < 4; i++)
    arr[i]++;
}