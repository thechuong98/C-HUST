// -------------Hw8.1----------------------------------------------
#include <stdio.h>
 
double kineticE(double mass,double velo){
	return 0.5*mass*velo*velo;
}

int main(){
	double mass = 0, velocity = 0;
	printf("Enter mass : ");
	scanf("%lf", &mass);
	printf("Enter velocity : ");
	scanf("%lf", &velocity);
	double KE = kineticE(mass, velocity);
	printf("Kinetic Energy of the object is : %.2lf\n J", KE);
	
	return 0;
}
// ----------------Hw8.2------------------------------------------
#include<stdio.h>
#include<math.h>
int is_prime(int n){
    if (n==2 || n==3) return 1;
    if (n>3){
        double t = sqrt(n);
        for(int i = 2; i <= t ; i++){
            if (n%i == 0) return 0;
        }
        return 1;

    }
}

int main(){
    int number = 0;
    printf("Enter the number : ");
    scanf("%d", &number);
    for (int i = 2; i <= number; i++){
        if (is_prime(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}

// ------------------Hw8.3-----------------------------------------
#include <stdio.h>

double TotalS(double hours){
	double totalS = 0;
	const double Sperhour = 15000;
	if (hours < 10 || hours > 65) printf("A worker can not work less than 10 hours or more than 65 hours a week\n");
	else if (hours <= 40 ) totalS = hours*Sperhour;
	else totalS = 40*Sperhour + (hours - 40)*Sperhour*1.5;
	return totalS;
}

int main(){
	double iHour = 0;
	printf("Total working hours ? ");
	scanf("%lf", &iHour);
	double TotalSalary = TotalS(iHour);
	printf("Thank you! Here's your salary : %.2lf VND\n", TotalSalary);

	return 0;
}

// ----------------Hw8.4--------------------------------------------

#include <stdio.h>

int IsLeapYear(int y){
	if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) return 1;
	else return 0;
}

int main(){
	int month = 0;
	int year = 0;
	int days;
	printf("Enter month and year(with the '/' between. ie : 5/2017 ): ");
	scanf("%d/%d", &month, &year);
	if (month == 4 || month == 6 || month == 9 || month == 11) days = 30;
	else if (month == 2){
		if (IsLeapYear(year)) days = 29;
		else days = 28;
	}
	else days = 31;

	printf("Number of days in that month: %d\n", days);

	return 0;
}