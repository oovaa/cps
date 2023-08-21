#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarr(int *p, int size);
void tryrealloc(int *p, int size);

int main(int argc, char *argv[]) {

  int size = 5;
  int *num = malloc(size * sizeof(int));
  int in=0;
  int i=0;
  do
  {
   printf("enter number , -1 if u wanna exit \n");
   scanf("%d",&in);
   if (in == -1) break;
   if (i == size) num = realloc (num, sizeof(int) * (size+=5));
   
   
   num[i++] = in;
  //  printf("num[%d] = %d\n",i , num[i-1]);
   
   printf("size = %d\n",size);
  } while (in != -1);
  
  for (int f = 0; f < size; f++)
  {
   printf("num[%d] = %d\n",f , num[f]);
   
  }
  


  // int *p;

  // tryrealloc(p, 5);
  // free(p);
  // int *arrp = malloc(5 * sizeof(int));
  // arrp[2] = 2;
  // arrp[1] = 4;
  // arrp[0] = 6;
  // arrp[3] = 32;
  // arrp[4] = 3;
  // arrp[5] = 65;

  // int a[] = {2, 4, 5, 16, 7, 51};

  // int *p = a;

  // printf("a = %d\n", p[6]); pass the limit is random (a = -1584652544)
  // printf("a = %d\n", p[5]);
  // printarr(arrp, 6);

  //   int a = 4;
  //   int *pa = &a;

  //   printf("a = %d\n", a);
  //   printf("pa = %p\n", pa);
  //   printf("pa = %d\n", *pa);

  return 0;
}

void printarr(int *p, int size) {
  for (int i = 0; i < size; i++) {
    printf("a[%d] = %d\n", i, p[i]);
  }
}
void tryrealloc(int *p, int size) {
  int c = 0;
  int val;
  p = malloc(size * sizeof(int));

  while (1) {
    if (c == size) {
      size *= 2;
      p = realloc(p, size * sizeof(int));
      printf("\nnew capacity is %d \n", size);
    }
    printf("enter num   size is %d  c is %d:\n", size, c);
    scanf("%d", &val);
    p[c] = val;
    printf("arr[%d] = %d\n", c, p[c]);
    c++;
  }
  free(p);
}
