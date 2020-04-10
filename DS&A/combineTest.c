#include "CSlist.h"
#include "Cstack.h"
#include "Cqueue.h"

//reverse a queue;
int main(){
	queue Q;
	stack S;
	queue_new(&Q, sizeof(int));
	stack_new(&S, sizeof(int));
	int arr[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; ++i){
		enQueue(&Q, &arr[i]);
	}
	list_for_each(&Q.list, iterator_int);

	while(!isEmptyQueue(&Q)){
		stack_push(&S, deQueue(&Q));
		list_for_each(&Q.list, iterator_int);
		printf("S->head : %d\n", *(int *)S.list.head->data);
	}

	// list_for_each(&S.list, iterator_int);
	while(!(stack_is_empty(&S))){
		enQueue(&Q, stack_pop(&S));
	}
	list_for_each(&Q.list, iterator_int);
}