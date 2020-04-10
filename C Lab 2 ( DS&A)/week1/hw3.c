#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// int factorial (int n){
// 	int factorial=1;
// 	for(int i = 2; i <= n; ++i)
// 		factorial *= i;
// 	return factorial;
// }
double exponential(double x, float arg){
	double sum = 1;
	double e = 1;
	for(int i = 1;;++i){
		e = (e*x)/i;
		if (e < arg) break;
		else sum += e;
	}
	return sum;
}


int main(int argc, char const *argv[])
{
	double x;
	double exp;
	double arg;
	if(argc == 2){
		x = atof(argv[1]);
		exp = exponential(x, 0.0000000001);
	}
	else if (argc == 3){
		x = atof(argv[1]);
		arg = atof(argv[2]);
		exp = exponential(x,arg);
	}
	else printf("2 argument or 3 argument please !");

	printf("e^x = %.5lf\n", exp);
	return 0;
}