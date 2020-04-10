#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue_ll.c"

void readFiletoQueue(FILE *stream, Queue **Q){
	char buff[20];
	while(fscanf(stream, "%s", buff) != EOF){
		treeNode *temp = newNode(buff);
		enQueue(Q, temp);
	}
}

int Random(int n){
	return rand()%n+1;
}

void makeGame(Queue **Q, treeNode **root){
	srand(time(NULL));
	while(queueSize(*Q) > 1){
		int a = Random(100);
		// printf("%d ", a);
		treeNode *node1 = deQueue(Q);
		treeNode *node2 = deQueue(Q);
		treeNode *node3;
		if(a % 2 == 0) node3 = newNode(node2->data);
		else node3 = newNode(node1->data);
		node3->left = node1;
		node3->right = node2;
		enQueue(Q, node3);
	}
	*root = deQueue(Q);
}

void breadth_first(treeNode *root){
  Queue *Q = creatQueue();
  treeNode *temp;
  enQueue(&Q, root);
  while(!isEmptyQueue(&Q)){
    temp = deQueue(&Q);
    printf("%s", temp->data);
    if(root->left != NULL) enQueue(&Q, temp->left);
    if(root->right != NULL) enQueue(&Q, temp->right);
  }
}


int main(int argc, char const *argv[]){
	Queue *Q = creatQueue();
	FILE *fin = fopen("usopen.txt", "r");
	readFiletoQueue(fin, &Q);
	treeNode *root = NULL;
	// traversing(Q);
	makeGame(&Q, &root);
	/* printLevelOrder(root);  */
	breadth_first(root);
}
