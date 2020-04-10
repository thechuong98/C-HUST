#include<stdio.h>

void rotate(double *a, double *b, double *c){
    double temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main()
{
    double a,b,c;
    printf("Enter 3 numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    rotate(&a, &b, &c);
    printf("After swap: a = %lf, b = %lf, c = %lf", a, b, c);
    return 0;

}
