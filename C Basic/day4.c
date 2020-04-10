#include <stdio.h>

int main(){
	double x, y;
	
	printf("Enter two real numbers, and I will tell you\nthe relationships they satisfy: ");
	scanf("%d %d", &x, &y);

	if (x == y){
		printf("%d is equal to %d\n", x, y);
	}

	if (x != y){
		printf("%d is not equal to %d\n", x, y);
	}

	if (x < y){
		printf("%d is less than %d\n", x, y);
	}

	if (x > y){
		printf("%d is greater than %d\n", x, y);
	}
}

int main(){
	const double km_to_mil = 1.609344;
	double kmvl, mvl;
	printf("Input the kilometers value and I'm gonna convert it into miles: ");
	scanf("%lf", &kmvl);
	mvl = kmvl/km_to_mil;
	printf("= %lf miles\n", mvl);

	return 0;

}

int main(){
	double a, b, exp1, exp2;
	printf("Enter 2 real numbers : ");
	scanf("%lf %lf", &a, &b);
	if (( a==0 ) && (b == 0)) printf("Cannot divided by zero\n");
	if (a==b) printf("Cannot divided by zero in expression 2\n");
	exp1 = ((a+b)*/((a*a-b*b)-a*b));
	exp2 = ((a-b)*(a+b))/((a*a-b*b)*(a*a+b*b));
	printf("Expression 1 : %lf\n", exp1);
	printf("Expression 2 : %lf\n", exp2);
	return 0;
}

// Su dung double chinh xac hon float vi chua nhieu bit hon