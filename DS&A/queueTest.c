#include "Cqueue.h"

int main(){
	queue Q;
	queue_new(&Q, sizeof(int));
	printf("Queue is empty ? : %d \n", isEmptyQueue(&Q));
	int a = 3;
	int b = 4;
	enQueue(&Q, &a);
	enQueue(&Q, &b);
	int *deQ = (int *)deQueue(&Q);
	printf("deQueue : %d\n", *deQ);
	list_for_each(&Q.list, iterator_int);
	printf("queue length : %d\n", queue_size(&Q));
}