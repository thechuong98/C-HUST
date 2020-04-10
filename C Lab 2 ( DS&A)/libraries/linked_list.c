#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int T;

typedef struct Node{
	T data;
	struct Node *next;
} node;

node *newNode(T data){
	node *newNode = (node *)malloc(sizeof(node));
	if(newNode == NULL){
		printf("Out of memory!\n");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insert(node **root, T data, int position){
	node *new = newNode(data);
	node *cur = *root;
	node *prev;
	if(position == 1){ //insert at the beginning
		new->next = *root;
		*root = new;
	}
	else{
		for(int i = 0; (cur != NULL) && i < position - 1; ++i){
			prev = cur;
			cur = cur->next;
		} 
		if(cur == NULL){ //insert at the end;
			prev->next = new;
			new->next = NULL;
		}
		else{ //insert at middle
			prev->next = new;
			new->next = cur;
		}
	}
}

void delete(node **root, int position){
	node *cur, *prev;
	if(*root == NULL){
		printf("List Empty");
		return;
	}
	cur = *root;
	if(position == 1){ //delete at head;
		cur = *root;
		*root = (*root)->next;
		free(cur);
		return;
	}
	else{
		for(int i = 0; cur != NULL && i < position-1; ++i){
			prev = cur;
			cur = cur->next;
		}
		if(cur == NULL){ //at end
			printf("Position does not exist!\n");
		}
		else{
			prev->next = cur->next;
			free(cur);
		}
	}
}

void displayNode(node *node){
	printf("%d\n", node->data);
}

void traverse(node **root){
	for(node *cur = *root; cur != NULL; cur = cur->next){
		displayNode(cur);
	}
}

