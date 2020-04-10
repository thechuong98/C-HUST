#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}
typedef struct treeNode{
	char *data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

typedef struct listNode{
	treeNode node;
	struct listNode *next;
} listNode;

typedef struct Queue{
	listNode *front;
	listNode *rear;
} Queue;

treeNode *newNode(char *data){
	treeNode *new = (treeNode *)malloc(sizeof(treeNode));
	if(new == NULL){
		printf("Out of memory!\n");
		exit(1);
	}
	else{
		new->left = NULL;
		new->right = NULL;
		new->data = data;
	}
	return new;
}

Queue *creatQueue(){
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->rear = (listNode *)malloc(sizeof(listNode));
	Q->front = NULL;
	return Q;
}

int isEmptyQueue(Queue **Q){
	return(*Q)->front == NULL;
}

void enQueue(Queue **Q, treeNode *nodePtr){
	listNode *newNode = (listNode *)malloc(sizeof(listNode));
	if(newNode == NULL) return;
	newNode->node.data = (char *)malloc(20*sizeof(char));
	strcpy(newNode->node.data, nodePtr->data); // if newNode->data = data then all the data is the same
	newNode->node.left = nodePtr->left;
	newNode->node.right = nodePtr->right;
	newNode->next = NULL;
	(*Q)->rear->next = newNode;
	(*Q)->rear = newNode;
	if ((*Q)->front == NULL){
		(*Q)->front = (*Q)->rear;
	}
}

treeNode *deQueue(Queue **Q){
	listNode *temp;
	if(isEmptyQueue(Q)){
		printf("Queue is empty\n");
		return 0;	
	}
	else{
		temp = (*Q)->front;
		(*Q)->front = (*Q)->front->next;
	}
	return &(temp->node);
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

void traversing(Queue *Q){
	listNode *cur = Q->front;
	while(cur != NULL){
		printf("%s\n", cur->node.data);
		cur = cur->next;
	}
}

int queueSize(Queue *Q){
	if(Q->front == NULL) return 0;
	listNode *cur = Q->front;
	int count = 0;
	while(cur != NULL){
		cur = cur->next;
		count++;
	}
	return count;
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

int height(treeNode *node){
	if(node == NULL) return 0;
	else{
		int lheight = height(node->left);
		int rheight = height(node->right);
		if(lheight>rheight) return lheight+1;
		else return rheight+1;
	}
}

void printGivenLevel(treeNode *root, int level){
	if(root == NULL) return;
	if(level == 1) printf("%s ", root->data);
	else if(level>1){
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}
	printf("\n");
}


void printLevelOrder(treeNode *root){
	int h = height(root);
	for(int i = 1; i<=h; ++i){
		printf("Level %d : \n", i);
		printGivenLevel(root, i);
	}
}