#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
  if(argc == 4){
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    if( a == 0) printf("Wrong input! a must different with 0\n");
    else{
      double delta = b*b-4*a*c;
      if (delta < 0) printf("Equation has no solution!\n");
      else{
	double x1 = ((-b+sqrt(delta))/(2*a));
	double x2 = (-b/a) - x1;
	if(x1 != x2) printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
	else printf("x1 = x2 = %.2lf\n", x1);
      }
    }
  }
  else printf("Input inform sde a b c (4 argument)\n");
}
