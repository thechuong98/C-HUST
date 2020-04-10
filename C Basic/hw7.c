#include <stdio.h>

int main(){
	int choice = 0;
	do {
		printf("Homework 7\n1. Calculate n!\n2. Average grade\n3. Replace multiple blank characters\n4. Replace tab and \\\n5. Exit Application\n");
		printf("Enter a number (1-5): ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				int n = 0;
				int factorial = 1;
				int i = 1;
				printf("Enter n: ");
				scanf("%d", &n);
				if (n < 0) printf("Factorial of negative number doesnt exist.");
				else if (n == 0) factorial = 1;
				else {
					while (i <= n){
						factorial *= i;
						i++;
					}
				}
				printf("n! = %d\n", factorial);
				break;
			}

			case 2:{
				float grade = 0;
				float aver_gra = 0;
				float sum = 0;
				int count = 0;
				printf("Enter your set of grades : \n");
				while ((scanf("%f", &grade)) && (grade >= 0)){
					sum += grade;
					count += 1;
					aver_gra = sum/count;
				}
				printf("Average grade : %g\n", aver_gra);
				break;
			}

			case 3 :{
				char c;
				int d = 0;
				printf("Enter a string: ");
				while (c = getchar()){
					if (c == ' '){
						if ( d != 1 ){ 
							putchar(c);
							d = 1;
						}
					}	
					else{
						putchar(c);
						d = 0;
					}
				}
				break;
			}

			case 4 : {
				char c;
				printf ("Enter a string : ");
				while (c = getchar()){
					if (c == '\t'){
						putchar('\\');
						putchar('t');
					}
					else if ( c == '\\'){
						putchar('\\');
						putchar('\\');
					}
					else putchar(c);
				}
				break;	
			}

			case 5 : printf("Bye!\n");

		}
	} while (choice != 5);

}	