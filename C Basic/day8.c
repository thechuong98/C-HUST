#include<stdio.h>

int main(){
	// int choice;
	// int choice2;
	// 	do{
	// 	printf("Choose one of those champion to play : \n");
	// 	printf("1. Ashe\n2. Garen\n3.Leesin\n4.Quit\n");
	// 	scanf("%d", &choice);
	// 	printf("Choose skin:\n");
	// 	switch(choice){
	// 		case 1: {
	// 			printf("1. Projected Ashe\n2. Freljord Ashe\n3. Champion Ashe\n\n");
	// 			break;
	// 		}	
	// 		case 2: {
	// 			printf("1. Commando Garen\n2. Rugged Garen\n3. Steel Legion Garen\n\n");
	// 			break;
	// 		}
	// 		case 3: {
	// 			printf("1. Muay Thai Leesin\n2. Pool Party Leesin\n3. God Fist Leesin\n\n");
	// 			break;
	// 		}
	// 		default: {
	// 			printf("Choose again =.=\n");
	// 			break;
	// 		}
	// 	}
	// 	scanf("%d", &choice2);
	// }	while (choice != 4);

	unsigned int iGrade = 0;
	double sum = 0;
	int count = 0;
	printf("Enter you grade: ");
	while (scanf("%u", &iGrade)){
			sum += iGrade;
			count += 1;
		}	
	printf("%lf\n", sum);
	printf("%lf\n", sum/count);
}