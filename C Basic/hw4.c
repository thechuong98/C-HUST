#include <stdio.h>

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
	if (( a==0 ) && ( b == 0)) printf("Error : divided by zero in expression 1\n");
	if (a==b) printf("Error : divided by zero in expression 2\n");
	exp1 = ((a+b)*(a+b)*(a+b)/((a*a-b*b)-a*b));
	exp2 = ((a-b)*(a+b))/((a*a-b*b)*(a*a+b*b));
	printf("Expression 1 : %lf\n", exp1);
	printf("Expression 2 : %lf\n", exp2);
	return 0;
}

int main(){
	double x, y;
	
	printf("Enter two real numbers, and I will tell you\nthe relationships they satisfy: ");
	scanf("%lf %lf", &x, &y);

	if (x == y){
		printf("%lf is equal to %lf\n", x, y);
	}

	if (x != y){
		printf("%lf is not equal to %lf\n", x, y);
	}

	if (x < y){
		printf("%lf is less than %lf\n", x, y);
	}

	if (x > y){
		printf("%lf is greater than %lf\n", x, y);
	}

	if (x >= y){
		printf("%lf is greater than or equal to %lf\n", x, y);
	}

	if (x <= y){
		printf("%lf is less than or equal to %lf\n", x, y);
	}
	
	return 0;
}

int main(){
	int iPod, iPad;
	double Payment;
	printf("How many iPod and iPad you want to buy : ");
	scanf("%d %d", &iPod, &iPad);
	Payment = iPod*148 + iPad*288;
	if ((Payment > 1020) || ((iPod>3)&&(iPad>=2)) || (iPod>=3)&&(iPad>2)){
		Payment *= 0.9;
	}
	printf("The bill you have to pay : %lf$\n", Payment);

	return 0;
}