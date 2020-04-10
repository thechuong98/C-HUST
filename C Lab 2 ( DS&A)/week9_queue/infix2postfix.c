#include "queue_infix.c"
#include "stackLinked.h"
#include <ctype.h>
void saveExpr(char *expr, char *store[]){
	int i = 0;
	char *p = strtok(expr, " ");
	while(p != NULL) {
		store[i++] = p;
		p = strtok(NULL, " ");
	}
}

int arraySize(char *array[]){
	int i = 0;
	while(*(array + i)){
		i++;
	}
	return i;
}

int isEnum(char *str){
	for(int i = 0; i < strlen(str); ++i){
		if(str[i] > '9' || str[i] < '0') return 0;
	}
	return 1;
}

int charToInt(char c) {
	return(c - '0');
}

int priority(char *x){
    if(strcmp(x, "(") == 0)
        return 0;
    if(strcmp(x, "+") == 0 || strcmp(x, "-") == 0)
        return 1;
    if(strcmp(x, "*") == 0 || strcmp(x, "/") == 0)
        return 2;
}


void infixToPostfix(char *store[], char *postfix[]){
	stack operator;
	init_stack(&operator);
	int sz = arraySize(store); //size of the infix array
	int postfixCount = 0;
	char *x;
	for(int i = 0; i < sz; ++i){
		if(isEnum(store[i])){
			strcpy(postfix[postfixCount], store[i]);
			postfixCount++;
		}
		else if(strcmp(store[i], "(") == 0) push(&store[i], &operator);
		else if(strcmp(store[i], ")") == 0){
			while(strcmp(strcpy(x, pop(&operator)), "(") != 0){
				strcpy(postfix[postfixCount], store[i]);
				postfixCount++;
			}
		}
		else{
			while(priority(top(&operator)) >= priority(store[i])) {
			    strcpy(postfix[postfixCount], pop(&operator));
			    push(&store[i], &operator);
			}
		}
	}
}

int main(){
	int choice = 0;
	char expr[100];
	char *store[100] = {}; //all every element initialize with 0
	char *postfix[100] = {};
	do{
		printf("----------------\n");
		printf("1. Enter an expression\n");
		printf("2. Convert into postfix\n");
		printf("3. Caculate\n");
		printf("4. Quit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter an expression\n");
				clear_buffer();
				scanf("%[^\n]s",expr); 
				saveExpr(expr, store);
				break;
			case 2:
				infixToPostfix(store, postfix);
				break;
			case 3:

				break;
			default:
				break;
		} 
	} while(choice != 4);
}