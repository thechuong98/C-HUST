#include <stdio.h>
#include <string.h>
void doubleExtract(double x, int *integer, double *frac){
  *integer = x;
  *frac = x - *integer;

}
int main(){ 
 double x = 3.14;
 int integer = 0;
 double frac = 0;
 doubleExtract(x, &integer, &frac);
 printf("%.2lf = %d + %.2lf\n", x, integer, frac);
 return 0;
}
