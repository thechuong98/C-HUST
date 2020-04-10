#include<stdio.h>
#include<stdlib.h>

#define MAX 50
typedef int T;
typedef struct stack{
	T storage[MAX];
	int top;
} stack;

stack *stackInit(){
	stack *Stack = (stack *)malloc(sizeof(stack));
	Stack->top = 0;
	return Stack;
}

int empty(stack *Stack){
	return Stack->top == 0;
}

int full(stack *Stack){
	return Stack->top == MAX;
}

void push(stack *Stack, T val){
	if(full(Stack)) printf("Stack overflow\n");
	else{
		Stack->storage[Stack->top++] = val; 
	}
}

T pop(stack *Stack){
	if(empty(Stack)){
		printf("Stack Underflow!\n");}
	else return Stack->storage[(--Stack->top)];
	return Stack->storage[Stack->top];
}

T peek(stack *Stack){
	return Stack->storage[Stack->top];
}