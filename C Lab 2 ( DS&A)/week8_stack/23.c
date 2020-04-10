#include <stdio.h>
#include "stack_1.h"

int charToInt(char c) {
	return(c - '0');
}

void strToStack(const char *str, stackNode **stack) {

	int i = 0;
	while (str[i]){
		push(stack, charToInt(str[i]));
		i++;
	}
	return;
}

void stackToStr(stackNode **stack, char str[]) {

	int i = 0;
	while (!isEmpty(stack)) {
		str[i] = pop(stack) + '0';
		i++;
	}
	return;
}

void add(char a[], char b[], char result[]) {

	stackNode *stack1;
	stackNode *stack2;
	stackNode *resultStack;
	
	strToStack(a, &stack1);
	strToStack(b, &stack2);

	int op1 = 0;
	int op2 = 0;
	int carry = 0;

	while (!isEmpty(&stack1) || !isEmpty(&stack2)) {
		if (!isEmpty(&stack1)) op1 = pop(&stack1);
	    else op1 = 0;

		if (!isEmpty(&stack2)) op2 = pop(&stack2);
		else op2 = 0;

		int opTotal = 0;
		opTotal = op1 + op2 + carry;
		push(&resultStack, opTotal % 10);

		if (opTotal >= 10) carry = 1;
		else carry = 0;
	}

	stackToStr(&resultStack, result);
}

void subtract(char a[], char b[], char result[]) {

	stackNode *stack1;
	stackNode *stack2;
	stackNode *stackResult;

	strToStack(a, &stack1);
	strToStack(b, &stack2);

	int op1 = 0;
	int op2 = 0;
	int carry = 0;

	while (!isEmpty(&stack1) || !isEmpty(&stack2)) {

		if (!isEmpty(&stack1)) op1 = pop(&stack1);
	    else op1 = 0;

		if (!isEmpty(&stack2)) op2 = pop(&stack2);
		else op2 = 0;
		int sub = op1 - op2 - carry;

		if (sub < 0) {
			sub += 10;
			carry = 1;
		} else
			carry = 0;

		push(&stackResult, sub);
	}

	stackToStr(&stackResult, result);
}

int main() {

	char result[100];	
	char operand1[100];
	char operand2[100];
	// scanf("%s + %s", operand1, operand2);
	subtract("234", "234", result);
	printf("= %s\n", result);
	return(0);
}