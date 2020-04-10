// #include <stdio.h>

// int main(){
// 	char sequence[20];
// 	printf("Write a string : ");
// 	scanf("%s", sequence);
// 	int m;
// 	for (int i = 0; sequence[i] != '\0'; i++){//get the number of character
// 		m = m+1;
// 	}
// 	char first = sequence[0];
// 	for (int i = 0; i < m; i++){ //for each letter in string
// 		if (sequence[i] < first){//compare to the biggest letter
// 			first = sequence[i]; 
// 		}
// 	}
// 	printf("%c\n", first);
// 	return 0;
// }
//----------Bai3--------------------------
// #include <stdio.h>

// int main(){
// 	int age = 0;
// 	printf("Enter your age : ");
// 	scanf("%d", &age);
// 	if (age < 18) printf("Your age class is Child\n");
// 	else if (age < 65) printf("Your age class is Adult\n");
// 	else printf("Your age class is Senior Citizen\n");

// 	return 0;
// }
//---------------BAI4-----------------------
#include <stdio.h>

#define weekend_price 10
#define other_price 7
int main(){
	int age = 0; 
	int weekend = 2;
	double total_price;
	char date;
	char* age_class;
	char* date_print;
	
	//Get age and date
	printf("Enter your age : ");
	scanf("%d", &age);
	printf("Today is (enter the first letter of the day in lowercase) : ");
	scanf(" %c", &date);
	
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
	printf("-Movie : Avatar\n");
	printf("-Class : %s\n", age_class);
	printf("-Date : %s\n", date_print);
	printf("-Price : $%.2lf\n\n", total_price);

	return 0;

}
