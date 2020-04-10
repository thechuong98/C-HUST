// #include <stdio.h>

// int main(){
// 	for (int i = 1; i <= 10; i++){
// 		for (int j = 1; j <= i; j++){
// 			printf("*");
// 		}
// 		printf("\n");
// 	}

// 	return 0;
// }

// //-----------------------------------------------
// #include <stdio.h>

// int main(){
// 	for (int i = 29; i <= 100; i = i+2){
// 		printf("%d\n", i);
// 	}

// 	return 0;
// }

// //------------------------------------------------

// #include <stdio.h>
// #include <math.h>

// int main(){
// 	for (int x = 0; x <= 100; x++){
// 		if (x==0 || x==1) continue;
// 		else if (x==2 || x==3) printf("%d\n", x);
// 		else{
// 			for(int i = 2; i <= sqrt(x); i++){
// 				if ( x % i == 0) break;
// 				else{
// 					if ( i == (int)sqrt(x) ) printf("%d\n", x);
// 				}
// 			}
// 		}
// 	}

// 	return 0;
// }

#include <stdio.h>

int main(){
	int n = 0;
	double val = 1;
	printf("Enter a number, I will give the you the value of n! : ");
	scanf("%d", &n);
	
	if (n < 0) printf("You entered a negative number!\n");
	else{
		for(int i = 2; i <= n; i++){
			val *= i;
		}
		printf("n! = %.10e\n", val);
	}

	return 0;
}