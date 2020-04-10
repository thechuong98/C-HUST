#include <stdio.h>
#include <stdlib.h>

typedef struct listNode{
	int ID;
	int data;
	struct listNode *next;
} listNode;

typedef struct Queue{
	listNode *front;
	listNode *rear;
} Queue;

Queue *creatQueue(){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->rear = (listNode *)malloc(sizeof(listNode));
	Q->front = NULL;
	return Q;
}

int isEmptyQueue(Queue **Q){
	return(*Q)->front == NULL;
}

void enQueue(Queue **Q, int data, int id){
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	if(newNode == NULL) return;
	newNode->data = data;
	newNode->ID = id;
	newNode->next = NULL;
	(*Q)->rear->next = newNode;
	(*Q)->rear = newNode;
	if ((*Q)->front == NULL){
		(*Q)->front = (*Q)->rear;
	}
}

int deQueue(Queue **Q){
	int data = 0;
	listNode *temp;
	if(isEmptyQueue(Q)){
		printf("Queue is empty\n");
		return 0;	}
	else{
		temp = (*Q)->front;
		data = (*Q)->front->data;
		(*Q)->front = (*Q)->front->next;
		free(temp);
	}
	return data;
}

void deleteQueue(Queue **Q){
	listNode *temp;
	while((*Q)->front){
		temp = (*Q)->front;
		(*Q)->front = (*Q)->front->next;
		free(temp);
	}
	free(*Q);
}

// void reverseQueue(Queue **Q){
// 	stack *S = creatStack();
// 	while(!isEmptyQueue(Q)){
// 		push(S, deQueue(Q))
// 	}
// 	while(!isEmptyStack){
// 		enQueue(Q, pop(S));
// 	}
// }


