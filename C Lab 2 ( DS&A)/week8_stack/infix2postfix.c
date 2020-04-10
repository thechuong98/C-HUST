#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"stackLinked.h"

int charToInt(char c) {
	return(c - '0');
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main(int argc, const char *argv[]){
	if(argc == 2){
		char infix[100];
		stack operator;
		char x;
		init_stack(&operator);
		strcpy(infix, argv[1]);
		for(int i = 0; i < strlen(infix); ++if){
			i(isalnum(infix[i])) printf("%c", infix[i]);
			else if(infix[i] == '('){ 
				push(&infix[i], &operator);
			}
			else if(infix[i] == ')'){
				while((x = pop(&operator)) != '('){
					printf("%c",x);
				}
			}
			else{
				while(priority(top(&operator)) >= priority(infix[i])){
					printf("%c", pop(&operator));
				push(&infix[i], &operator);
				}
			}
		}
	}
}
