#ifndef QUEUE_H
#define QUEUE_H
	
#include<stdio.h>
#include<stdlib.h>

typedef int T;

typedef struct queueNode{
	T val;
	struct queueNode *next;
	struct queueNode *prev;
} qNode;

typedef struct queue{
	qNode *rear;
	qNode *front;
	size_t size;
} queue;

qNode *newNode(T val){
	qNode *newNode = (qNode *)malloc(sizeof(qNode));
	if(newNode == NULL){
		printf("Out of memory!\n");
		return NULL;
	}
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}


void init_queue(queue **Q){
	(*Q)->rear = (qNode *)malloc(sizeof(qNode));
	(*Q)->front = (qNode *)malloc(sizeof(qNode));
}

void enQueue(queue **Q, T val){
	qNode *lastNode = (*Q)->front;
	(*Q)->front = newNode(val);
	if(lastNode != NULL) lastNode->prev = (*Q)->front;
	if((*Q)->rear == NULL) (*Q)->rear = (*Q)->front;
	(*Q)->size += 1;
}

void deQueue(queue **Q, T val){
	
}

#endif // QUEUE_H
	