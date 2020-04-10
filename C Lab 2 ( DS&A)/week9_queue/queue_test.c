#include "queue_ll_2.c"

int getWaitTime(Queue **Q){
	listNode *temp = (*Q)->front;
	if(temp == NULL) return 0;
	while(temp != NULL){
		temp = temp->next;
	}
	return temp->wait; //return the last one have to wait
}

void enQueue(Queue **Q){
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	if(newNode == NULL) return;
	newNode->wait = getWaitTime(Q) + 15;
	newNode->next = NULL;
	(*Q)->rear->next = newNode;
	(*Q)->rear = newNode;
	if ((*Q)->front == NULL){
		(*Q)->front = (*Q)->rear;
	}
}

void updateQueue(Queue **Q, int minute){
	listNode *temp = (*Q)->front;
	if(temp == NULL) return;
	while(temp != NULL){
		temp->wait -= minute;
		if(temp->wait <= 0) deQueue(Q);
		temp = temp->next;
	}
}


int main(){
	Queue *Q = creatQueue();
	// enQueue(&Q);
	updateQueue(&Q, 30);
}