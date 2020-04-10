#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stackLinked.h"
int charToInt(char c) {
	return(c - '0');
}

int main(int argc, const char* argv[]){
	char expression[100];
	stack operands;
	init_stack(&operands);
	if(argc == 2){
		strcpy(expression, argv[1]);
		for(int i = 0; i < strlen(expression); ++i){
			int a;
			if(isdigit(expression[i])){
				a = charToInt(expression[i]);
				push(&a, &operands);
				continue;
			}
			if(isalpha(expression[i])){
				switch(expression[i]){
					case '+':
						a = pop(&operands) + pop(&operands);
						push(&a, &operands);
						break;
					case '*':
						a = pop(&operands) * pop(&operands);
						push(&a, &operands);
						break;
					case '-':
						a = pop(&operands) - pop(&operands);
						push(&a, &operands);
						break;
					case '/':
						a = pop(&operands) / pop(&operands);
						push(&a, &operands);
						break;
				}
			}
		}
		top(&operands);
	}	

}