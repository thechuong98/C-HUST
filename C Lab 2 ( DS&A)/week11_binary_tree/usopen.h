#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* T;
typedef struct treeNode{
	T data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *newNode(T data){
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
