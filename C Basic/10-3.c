#include <stdio.h>

int main(){
float a,b,c;
printf("Enter 3 float numbers: \n");
scanf("%f %f %f", &a, &b, &c);
float *ptr = &a;
*ptr += 100;
printf("a = : %.2f", a);
ptr = &b;
*ptr += 100;
printf("\nb = : %.2f", b);
ptr = &c;
*ptr += 100;
printf("\nc = : %.2f", c);
return 0;

}
