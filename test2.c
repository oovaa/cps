#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
const double PI= 3.14159;
double r;
double c;
printf("enter radios\n ");

scanf("%lf",&r);

double re = 2*PI*r;
double area = PI * r*r;


printf("the area is %lf ",area);
// printf("the circ is %lf \n ",re);

    return 0;
}
