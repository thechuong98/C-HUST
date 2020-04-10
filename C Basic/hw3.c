#include <stdio.h>

int main(){
	int num1;
	double num2;
	float var_store1;
	int var_store2;
	printf("Input an integer and a double (add a white space between them) : ");
	scanf("%i %lf", &num1, &num2);
	var_store1 = num1;
	var_store2 = num2;
	printf("Your two input numbers : %f and %i \n", var_store1, var_store2);

	int hexa_num;
	float sci_num;
	printf("Enter a hexadecimal number, and a scientific format float : ");
	scanf("%x %f", &hexa_num, &sci_num);
	printf("Your two input numbers : %i %f\n", hexa_num, sci_num);

	return 0;
}


int main(){
	char sthing[100];
	printf("Enter a string : ");
	scanf("%[aeiou]", sthing);
	printf("The input was : \"%s\"\n", sthing);

	return 0;
}


#define normalrate 25000 
#define overtimerate 40000
#define reg_hour 40
int main(){
	int hours; 
	int wages;
	printf("Enter the total work hours : ");
	scanf("%d", &hours);
	if (hours > reg_hour){
		wages = reg_hour*normalrate + (hours-reg_hour)*overtimerate;
	}
	else {
		wages = hours*normalrate;
	}
	printf("The total wages : %d\n", wages);

	return 0;
}

#define VAT 0.04
int main(){
	int Quantity, Price, Total;
	double Pay;
	char ISBN[50], Title[50];
	printf("The Title of the book : ");
	scanf("%[^\n]", Title);
	printf("The ISBN of the book : ");
	scanf("%s", ISBN);
	printf("How many books you buy : ");
	scanf("%d", &Quantity);
	printf("The price of the book : ");
	scanf("%d", &Price);
	Total = Quantity*Price;
	printf("BK Book Store\n");
	printf("Qty    ISBN          Title          Price     Total\n");
	printf("----------------------------------------------------\n");
	printf("%d      %s      %s     %d     %d\n",Quantity, ISBN, Title, Price, Total);
	printf("VAT : %f\n", VAT);
	Pay = Total*(1+VAT);
	printf("You pay : %f", Pay);

	return 0;
}

int main(){
	char name[50] = { '\0' };
	char stdID[30] = { '\0' };
	char enter[1];
	printf("Enter your name: ");
	scanf("%[^\n]", name);
	printf("Enter your student ID in the form HUSTxxx ( x is a number 0-9 ) :");
	scanf(" %[HUST0-9]", stdID); // cho nay phai co dau cach o truoc %[HUST0-9] vi scanf dang truoc co luu 1 dau \n, nen phai co 1 white space de huy \n roi moi tiep tuc scanf 
	printf("Your name : %s\nYour Student ID : %s\n", name, stdID);

	return 0;
}