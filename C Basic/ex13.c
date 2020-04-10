// HOMEWORK 12
// 12.1------------------------------------------

#include <stdio.h>
#include <string.h>

int spaceCounter(char *string){
	int count = 0;
	for(int i = 0; i < strlen(string); ++i){
		if(string[i] == ' '){
			count += 1;
		}
	}
	return count;
}

int main(){
	char istring[100];
	printf("Input a string :");
	scanf("%[^\n]%*c", istring);
	printf("Number of space : %d\n", spaceCounter(istring));
	return 0;
}

// 12.2---------------------------------------------------

#include<stdio.h>
#include <string.h>

void swapChar(char *string, char c1, char c2){
	for(int i = 0; i < strlen(string); ++i){
		if(string[i] == c1){
			string[i] = c2;
		}
	}
}

int main(){
	char istring[100];
	printf("Input a string :");
	scanf("%s", istring);
	swapChar(istring, 'a', 'b');
	printf("%s\n", istring);
	return 0;
}

// 12.3----------------------------------------------------
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int inFormat(char *number){
	if (strlen(number) != 7) return 0;
	else {
		for (int i = 0; i < 3; ++i){
			if(!isalpha(number[i])) return 0;
		}
		for (int i = 3; i < 7; ++i){
			if(!isdigit(number[i])) return 0;
		}
		return 1;
	}
}

int main(){
	char cusNum[10];
	printf("Enter your customer number ");
	scanf("%s", cusNum);
	if(inFormat(cusNum)) printf("Right format\n");
	else printf("Wrong format\n");

	return 0;
}

// 12.4 -----------------------------------------------------
#include<stdio.h>	
#include <string.h>

void getFirst(char *name){
	for(int i = 0; i < strlen(name); ++i){
		if(name[i] != ' '){
			printf("%c", name[i]);
		}
		else break;
	}
	printf("\n");
}

int main(){
	char name[100];
	printf("Input your full name : ");
	scanf("%[^\n]s", name);
	getFirst(name);
	return 0;
}


// 12.5 -----------------------------------------------------------
#include<stdio.h>
#include <string.h>

int strend(char *s, char* t){
	int slen = strlen(s);
	int tlen = strlen(t);
	if (slen < tlen) return 0;
	else{
		for (int i = 0; i <= slen - tlen ; ++i){
			if(strcmp(&s[i], t) == 0) return 1;
		}
		return 0;
	}
}

int main(){
	char string[] = "Testing";
	char t[] = "ting";
	if(strend(string, t)){
		printf("Occurred\n");
	}
	else printf("Not Occurred\n");

	return 0;
}

// 12.6--------------------------------
#include <stdio.h>
#include <string.h>
//check if input in a product number
int inString(char *product, char *input){
	for (int i = 0; i < 5; i++){
		if (product[i] == input[0]){
			for (int j = 1; j < strlen(input); j++){
				if(product[i+j] != input[j]) return 0;
			}
			return 1;
		}
	}
	return 0;
}

void printResult(char *list[], char *input){
	int check = 0;
	for(int i = 0; i < 5; ++i){
		if (inString(list[i], input)){
			printf("%s\n", list[i]);
			check = 1;
		}
	}
	if (!check) printf("No result\n");
}

int main(){
	char *product[] = {"TV127 31 inch Television", "CD057 CD Player", "TA877 Answering Machine", "CS409 Car Stereo", "PC655 Personal Computer"};
	char input[10];
	printf("Enter the product number : ");
	scanf("%s", input);
	printResult(product, input);
}