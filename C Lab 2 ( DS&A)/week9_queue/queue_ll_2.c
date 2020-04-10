#include <stdio.h>
#include <stdlib.h>

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

typedef struct listNode{
	int wait;
	struct listNode *next;
} listNode;

typedef struct Queue{
	listNode *front;
	listNode *rear;
} Queue;

Queue *creatQueue(){
	Queue *Q = (Queue*)malloc(sizeof(Queue)); 
	Q->rear = (listNode *)malloc(sizeof(listNode)); //khi nao creat thi nho allocate
	Q->front = NULL; //check if the data structure is empty
	return Q;
}

int isEmptyQueue(Queue **Q){
	return(*Q)->front == NULL;
}

int getQueueLength(Queue **Q){
	int len = 0;
	listNode *temp;
	temp = (*Q)->front;
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}


int deQueue(Queue **Q){
	int data = 0;
	listNode *temp;
	if(isEmptyQueue(Q)){
		printf("Queue is empty\n");
		return 0;	}
	else{
		temp = (*Q)->front;
		data = (*Q)->front->wait;
		(*Q)->front = (*Q)->front->next;
		free(temp);
	}
	return data;
}

// int min(int a[], int n){ //customer will go to min length queue
// 	int min = a[0];
// 	for(int i = 1; i < n; ++i){
// 		if(a[i]<min){
// 			min = a[i];
// 		}
// 	}
// 	return min;
// }

int getWaitTime(Queue **Q){ //return the time that the last person have to wait
	if((*Q)->front == NULL) return 0; // if the queue is empty;
	return (*Q)->rear->wait; //return the last one have to wait
}


void enQueue(Queue **Q){
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	if(newNode == NULL) return;
	newNode->wait = getWaitTime(Q) + 15; // + 15 for next getWaitTime, we -15 when we print;
	newNode->next = NULL;
	(*Q)->rear->next = newNode;
	(*Q)->rear = newNode;
	if((*Q)->front == NULL){
		(*Q)->front = (*Q)->rear;
	}
}

void updateQueue(Queue **Q, int minute){
	listNode *temp = (*Q)->front;
	listNode *prev = temp;
	if(temp == NULL) return;
	while(temp != NULL){
		temp->wait -= minute;
		prev = temp;
		temp = temp->next;
		if(prev->wait <= 0) deQueue(Q);
	}
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





