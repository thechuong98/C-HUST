#include <stdio.h>
#include <stdlib.h>

#define MAX 50
typedef int T;

T stack[MAX];
int top;

void stackInit(T stack[]){
	top  = 0;
}

int empty(T stack[]){
	return top == 0;
}

int full(T stack[]){
	return top == MAX;
}

void push(T element, T stack[]){
	if(full(stack)) printf("Stack Overflow!\n");
	else stack[top++] = element;
}

T pop(T stack[]){
	if(empty(stack)){
		printf("Stack Underflow!\n");}
	else return stack[--top];
	return stack[top];
}

T peek(T stack[]){
	return stack[top];
}




