#include <stdio.h>

int main(){
	char sequence[3];
	printf("Write a string with 3 letter : ");
	scanf("%s", sequence); //get a string

	char first;

	if (sequence[0] < sequence[1]) first = sequence[0];
	else first = sequence[1];

	if (first > sequence[2]) first = sequence[2];
	
	printf("%c\n", first);
	
	return 0;
}

-------------------------------------

#include <stdio.h>

int main(){
	double degree;
	printf("Enter a compass heading and I will transfer it into compass bearing : ");
	scanf("%lf", &degree);
	if ((degree >= 0) && (degree < 90)) printf("North East\n");
	else if (degree < 180) printf("North West\n");
	else if (degree < 270) printf("South West\n");
	else if (degree < 360) printf("South East\n");
	else printf("Oops! Please enter a degree from 0 to 360(not including 360)\n");

	return 0;
}

-----------------------------------------------------------------------

#include <stdio.h>

int main(){
	int age = 0;
	printf("Enter your age : ");
	scanf("%d", &age);
	if (age < 0) printf("You haven't been born yet!\n");
	else if ((age >= 0) && (age < 18)) printf("Your age class is Child\n");
	else if (age < 65) printf("Your age class is Adult\n");
	else printf("Your age class is Senior Citizen\n");

	return 0;
}

----------------------------------------------------------------------
#include <stdio.h>

#define weekend_price 10
#define other_price 7
int main(){
	int age = 0; 
	int weekend = 2;
	double total_price;
	char date;
	char movie[20];
	char* age_class;
	char* date_print;
	
	//Get age and date and film name
	printf("Enter your age : ");
	scanf("%d", &age);
	printf("Today is (enter the first letter of the day in lowercase) : ");
	scanf(" %c", &date);
	printf("What is the movie you'd like to watch: ");
	scanf(" %[^\n]", movie);
	
	//Weekend or not ? 
	switch (date){
		case 'm': case 't': case 'f': case 'w': weekend = 0 ; break;
		case 's': weekend = 1; break;
		default : break;
	}
	
	//If weekend
	if (weekend == 1){
		if (age<18)	total_price = weekend_price*0.5;
		else if (age < 65) total_price = weekend_price;
		else total_price = weekend_price*0.7;
		date_print = "Weekend";
	}

	//If other days
	else if (weekend == 0){
		if (age<18)	total_price = 7*0.5;
		else if (age < 65) total_price = other_price;
		else total_price = other_price*0.7;
		date_print = "Other days";
	}
	else {
		printf("You input the wrong date\n");
		date_print = "Wrong";
	}

	//Child or adult or sc
	if (age < 18) age_class = "Child";
	else if (age < 65) age_class = "Adult";
	else age_class = "Senior Citizen";

	//Print
	printf("\nBKCine\n-------------------\n");
	printf("-Movie : %s\n", movie);
	printf("-Class : %s\n", age_class);
	printf("-Date : %s\n", date_print);
	printf("-Price : $%.2lf\n\n", total_price);

	return 0;

}

-----------------------------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand((unsigned)time(NULL));
	int random = rand() % 10; /* generate 0 to M-1 */
	int guess = 0;

	printf("Guess my number (between 0 and 10) : ");
	scanf("%d", &guess);

	if (guess < random) printf("Your guess was too small.\n");
	else if (guess > random) printf("Your guess was too big.\n");
	else printf("You're genius.\n");

	return 0;
}

----------------------------------------------------------------------

#include <stdio.h>

int main(){
	char veh_type;
	int check_type = 0; // 1 for car, 2 for bus, 3 for truck
	double park_time = 0;
	double regular_fee = 0;
	double over_time = 0;
	double total_fee = 0;
	char* print_veh;

	printf("What is you vehicle type (C for car, B for bus and T for truck) : ");
	scanf("%c", &veh_type);

	switch (veh_type){
		case 'C': check_type = 1; break;
		case 'B': check_type = 2; break;
		case 'T': check_type = 3; break;
		default : break;
	}

	printf("Enter your parking time: ");
	scanf("%lf", &park_time);

	//If CAR TYPE
	if (check_type == 1){
		print_veh = "CAR";
		if (park_time <= 2){
			total_fee = 0.7*park_time;
			regular_fee = total_fee;
		}
		else {
			regular_fee = 2*0.7;
			over_time = (park_time - 2) * 2.5;
			total_fee = regular_fee + over_time;
		}
	}

	//If BUS TYPE
	if (check_type == 2){
		print_veh = "BUS";
		if (park_time <= 2){
			total_fee = 1.5*park_time;
			regular_fee = total_fee;
		}
		else {
			regular_fee = 1.5*2;
			over_time = (park_time - 2) * 2;
			total_fee = regular_fee + over_time;
		}
	}

	//If TRUCK TYPE
	if (check_type == 3){
		print_veh = "TRUCK";
		if (park_time <= 1){
			total_fee = 2.5*park_time;
			regular_fee = total_fee;
		}
		else {
			regular_fee = 2.5;
			over_time = (park_time - 1) * 3.25;
			total_fee = regular_fee + over_time;
		}
	}

	//Print out 
	printf("------------------------------\n");
	printf("Parking Fee\n");
	printf("VEHICLE TYPE : %s\n", print_veh);
	printf("TIME : %.2lf\n", park_time);
	printf("REGULAR FEE : $%.2lf\n", regular_fee);
	printf("OVERTIME    : $%.2lf\n", over_time);
	printf("TOTAL       : $%.2lf\n", total_fee);
	printf("Thank you.\n");

	return 0;
}

-----------------------------------------------------
#include <stdio.h>

int main(){
	double a, b, c;
	char operator = '\0';
	scanf("%lf %c %lf", &a, &operator, &b);
	switch (operator){
		case '+' : c = a + b; break;
		case '-' : c = a - b; break;
		case '*' : c = a * b; break;
		case '/' : c = a / b; break;
		}

	printf("%.2lf %c %.2lf = %.2lf\n", a, operator, b, c);
}