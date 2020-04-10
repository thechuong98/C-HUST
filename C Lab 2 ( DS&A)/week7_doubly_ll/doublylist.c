#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
	struct node *prev;
} node;

node *current, *previous, *tail;
int length = 0;

node *newNode(int val){
	node *new = (node *)malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return new;
}

int isEmpty(node *root){
	if(root == NULL) return 0;
	return 1;
}

// INSERTION

void insertAtHead(node *root, int val){
	node *new = newNode(val);
	if(root == NULL) root = tail = new;
	else{
		new->prev = NULL;
		new->next = root;
		root->prev = new;
		root = new;
	}
	length += 1;
}

void insertAtTail(node *root, int val){
	node *new = newNode(val);
	if(root == NULL) root = tail = new;
	else{
		current = root;
		while(current->next != NULL){
			current = current->next;
		}
		new->next = NULL;
		new->prev = current;
		current->next = new;
		tail = new;
	}
	length += 1;
}

void insertAtPos(node *root, int val, int pos){
	current = root;
	node *new = newNode(val);
	if(root == NULL || pos == 0){
		insertAtHead(root, val);
	}
	else{
		for(int i = 0; (i < pos) && (current->next != NULL); ++i){
			current = current->next;
			if(current == NULL) break;	
		}
		new->next = current->next;
		new->prev = current;
		current->next->prev = new;
		current->next = new;
	}
	length += 1;
}



void insertAfter(int val){
	node *new = newNode(val);
	new->next = current->next;
	new->prev = current;
	current->next->prev = new;
	current->next = new;
	length += 1;
}

void insertBefore(int val){
	node *new = newNode(val);
	current = current->prev;
	insertAfter(val);
	length += 1;
}

void deleteAtHead(node *root){
	current = root;
	root = root->next;
	root->prev = NULL;
	free(current);
	length -= 1;
}

void deleteAtTail(node *root){
	current = root;
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	free(current);
	current = previous;
	length -= 1;
}

void deleteAtPos(node *root, int pos){
	current = root;
	for(int i = 0; i < pos && current->next != NULL;++i){
		previous = current;
		current = current->next;
		if(current == NULL) return;
	}
	previous->next = current->next;
	current->next->prev = previous;
	free(current);
	length -= 1;
}

void displayNode(node *n){
	printf("%d\n", n->val);
}

void traversingList(node *root){
	current = root;
	while(current != NULL){
		displayNode(current);
		current = current->next;
	}
}

void freeList(node *root){
	current = root;
	while(current != NULL){
		current = current->next;
		free(current);
	}
}

node *sentinelSearch(node **root, int key){
  node *cur = *root;
  while(cur->next != NULL){
    cur = cur->next;
  }
  int last = cur->val; // cur now is the last node in list;
  cur->val = key;
  node *cur2 = *root;
  while(cur2->val != key && cur2->next != NULL){
    cur2 = cur2->next;
  }
  cur->val = last;
  if(cur2->next != NULL || key == cur->val){
    return cur2;
  }
  else return NULL;
}

int main(){
	length = 1;
	node *root2 = newNode(2);
	insertAtTail(root2, 3);
	traversingList(root2);
	printf("is 4 in list : %d\n", sentinelSearch(&root2, 4) != NULL); 
}
