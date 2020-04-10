#include "Cstack.h"

int main(){
	stack testStack;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 10;
	stack_new(&testStack, sizeof(int));
	stack_push(&testStack, &a);
	stack_push(&testStack, &b);
	stack_push(&testStack, &c);
	stack_push(&testStack, &d);
	int *pop = (int *)stack_pop(&testStack);
	printf("%d\n", *pop);
	list_for_each(&testStack.list, iterator_int);
	printf("list_size : %d\n", list_size(&testStack.list));
}