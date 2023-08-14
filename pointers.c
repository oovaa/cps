#include <stdio.h>
int* tryReturn(int*);
// #define  *psum(int *a, int *s) ((*a > *s)? a : s)
#define max(a, b) ((a > b)? a : b)
#define psum(a, s) ((*a > *s) ? (a) : (s))
// #define psum(a, s) ((*a > *s) ? (*a) : (*s))
int main(void)
{

    


    char a[5] = "tata";
    char s[5] = "nana";
    // printf("%c\n",*(a+4));

    a[4] = *s ;// it worked  😂😂😂  combined two strings
    // printf("%s\n",a);
    // printf("%s\n",s);
    
    int x = 5;
    int y = 10;
    int *result = psum(&x, &y);
    
    // printf("The larger value is: %d\n", *result);

// int a = 2;
// int s = 23;
// int x = max(a , s);
// int x = psum(&a , &s);
// printf("%d\n",x);
// printf("%p\n",&x);

 

// int a = 2;
// int* p = tryReturn(&a);
// printf("%d\n",a);
// printf("%d\n",*p);
// printf("%p\n",p);

    // char *a = "om\0e\0r";
    // a = NULL;
    // printf("%s\n",a);
    // char s = 'a';
    // char *sp = *(0x7ffc32064857);
    // char *sp = &s; 
    // printf("%c\n",s);
    // printf("%d\n",s);
    // printf("%p\n",sp);
    // printf("%d\n",*sp + 10);
    // printf("%d\n",*(sp +1));
    
    
// int a = 333;
// int *d = &a;
// *d = 10;
// *d = 20;
// printf("test = %d\n",a + *d + 10);

// printf("a = %d\n",a);
// printf("&a = %p\n",&a);
// printf("d = %p\n",d);
// printf("*d = %d\n",*d);

return 0;
}
// int* psum(int* a, int* s){
//     return (*a > *s)? a : s;
// }


int* tryReturn(int* p){
    *p += 3;
    return p;

}

