#include<stdio.h>
#include <stdio_ext.h>


typedef struct restaurant{
	char Name[30];
	char Description[500];
	double rating;
	char address[100];
} restaurant ;

void clean_stdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


/* ----------
  FUNCTION 1
-----------*/

void getResInfo(restaurant *A){
	clean_stdin();
	printf("Enter the name of the restaurant : ");
	fgets(A->Name, 30, stdin);
	printf("Description : ");
	fgets(A->Description, 500, stdin);
	printf("Rating : ");
	do{
		scanf("%lf", &A->rating);
	} while (A->rating < 0 || A->rating > 5);
	printf("Address: ");
	fgets(A->address, 100, stdin);
};
/* ----------
  FUNCTION 1
-----------*/

/* ----------
  FUNCTION 2
-----------*/
void printOne(restaurant A){
	printf("%s", A.address);
	printf("Name : %s", A.Name);
	printf("Description: %s", A.Description);
	printf("Rating : %lf\n", A.rating);
	printf("Address: %s", A.address);
	printf("\n\n");

}
void printArray(restaurant A[], int count){
	for(int i = 0; i < count; ++i){
		printf("Nha hang %d\n", i+1);
		printOne(A[i]);
	}
}
/* ----------
  FUNCTION 2
-----------*/


int main(){
	int count = 0;
	int numberofRes = 0;
	restaurant resArray[50];
	int choice;
	do{
		printf("\n\n HOMEWORK \n\n");
		printf("1. Get info Restaurant\n"); 
		printf("2. Info of Restaurant\n");
		printf("3. Exit application \n\n");
		printf("Enter a number (1-3):");
		choice=getchar();

		switch(choice){
			case '1':{
				printf("Number of restaurant you want to enter (greater than 0 ): ");
				scanf("%d", &numberofRes);
				for(int i = 0; i < numberofRes; ++i) getResInfo(&resArray[i+count]);
				count += numberofRes;
				__fpurge(stdin);
				} break;
				
			case '2':{
				printArray(resArray, count);
				} break;
				
			case '3':{
				clean_stdin();
				}break;
	
			case '4':{
				printf("\n Exit application!");
				clean_stdin();
				}break;

			default:{
            	printf("\nYour choice is invalid. Please enter again!\n");
				clean_stdin();
            	}break;
		}
	}	
	while(choice!='3'); 
}