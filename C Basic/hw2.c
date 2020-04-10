#include <stdio.h>
int main()
{
    printf("Size of int: %ld bytes\n",sizeof(int));
    printf("Size of float: %ld bytes\n",sizeof(long));
    printf("Size of double: %ld bytes\n",sizeof(double));
    printf("Size of char: %ld byte\n",sizeof(char));

    return 0;
}

int main(){
	printf("%c%c%c%c%c%c\n", 67, 72, 85, 79, 78, 71);
    return 0;
}

int main(){
	char word[20];
	printf("Enter your name: ");
	scanf("%19s", word);
    printf("Hello, %s\n", word );
    return 0;
}

int main(){
    int num1, num2, sum;
    printf("Enter the first number: ");
    scanf("%i", &num1);
    printf("Enter the second number: ");
    scanf("%i", &num2);
    sum = num1 + num2;
    printf("Sum %i + %i = %i\n", num1, num2, sum);
    return 0;
}

int main(){
	char dayofweek[20];
	printf("Today is : ");
	scanf("%s", dayofweek);
	int overnights, threedays, weekly, total;
	printf("Enter the number of dvds you rent overnight : ");	
	scanf("%d", &overnights);
	printf("The number of dvds you rent for three-day : ");
	scanf("%d", &threedays);
	printf("The number of dvds you rent for a week : ");
	scanf("%d", &weekly);
	total = overnights * 7 + threedays * 5 + weekly * 3;
	printf("Your total cost is %d$\n", total);

	return 0;
}