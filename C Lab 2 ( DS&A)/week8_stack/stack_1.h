#include <stdlib.h>
#include <stdio.h>

typedef int T;

typedef struct stackNode {
	T data;
	struct stackNode *next;
} stackNode;

void stack_init(stackNode **stack) {
	*stack = NULL;
	return;
}

T getData() {
	T data;
	printf("Data : ");
	scanf("%d", &data);
	
	return(data);
}

stackNode *makeNode(T data) {

	stackNode *newnode = (stackNode *)malloc(sizeof(stackNode));
	newnode->data = data;
	newnode->next = NULL;
	
	return(newnode);
}

void push(stackNode **top, T data) {

	stackNode *newnode = makeNode(data);
	newnode->next = *top;
	*top = newnode;

	return;
}

T pop(stackNode **top) {

	T data = (*top)->data;
	stackNode *p = *top;
	*top = (*top)->next;
	free(p);
	return(data);
}

T peak(stackNode **stack) { 
	return((*stack)->data);
}

int isEmpty(stackNode **top) {
	return( *top == NULL );
}

void freeStack(stackNode **top) {

	stackNode *curr = *top;
	stackNode *temp;
	
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*top = NULL;
}
