#include <stdio.h>
#include "stack.c"

int main(){
	int choice = 0;
	stackNode *intStack = (stackNode *)malloc(sizeof(stackNode));
	// stackNode *doubleStack;
	// stack_init(&intStack, STACK_INT);
	stack_init(&intStack, STACK_DOUBLE);

	while(choice != 5){
		printf("1. Push an integer.\n");
		printf("2. Peek\n");
		printf("3. Pop an integer.\n");
		printf("4. Undo.\n");
		printf("5. Quit.\n");
		scanf("%d", &choice);
		double i;

		switch(choice){
			case 1: 
				push(&intStack, 3.4);
				break;
			case 2:
				peek(&intStack, &i);
				printf("top is %lf\n", i);
				break;
			case 3:
				pop(&intStack, &i);
				printf("Popped %lf\n", i);
				break;
		}
	}
}