#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_ll.c"

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}


listNode* creatNew(int mem, int ID){
	listNode *newNode = (listNode *)malloc(sizeof(newNode));
	newNode->data = mem;
	newNode->ID = ID;
	newNode->next = NULL;
	return newNode;
}

int isIdExist(Queue **Q, int id){
	listNode *temp = (*Q)->front;
	while(temp != NULL){
		if(temp->ID == id) return 1;
		temp = temp->next;
	}
	return 0;
}

void killID(Queue **Q, int id){
	listNode *temp = (*Q)->front;
	listNode *prev = NULL;
	int found = 0;
	while(!found){
		if(temp->ID == id) found = 1;
		else if(temp == NULL){
			printf("ID is not in the list\n");
			return;
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
	if(prev == NULL) (*Q)->front = (*Q)->front->next;
	else {
		prev->next = temp->next;
		// free(temp);
	}
}

void display(listNode *node){
	printf("%d : %dmb\n", node->ID, node->data);
}

void displayAll(Queue **Q){
	listNode *cur = (*Q)->front;
	while(cur != NULL){
		display(cur);
		cur = cur->next;
	}
}


int main(int argc, char *argv[]){
	if(argc == 3){
		int numOfProcess = atoi(argv[1]);
		int mem_capacity = atoi(argv[2]);
		int choice = 0;
		Queue *Q = creatQueue();
		listNode *temp = malloc(sizeof(listNode));
		int id = 0;
		int memory = 0;
		do{
			printf("1.Creat a new program(with a given"
				"amount of necessary memory and ID)\n");
			printf("2. Kill the program\n");
			printf("3. Task manager\n");
			printf("4. Quit\n");
			scanf("%d", &choice);
			switch(choice){
				case 1:
					printf("ID, memory: \n");
					scanf("%d, %d", &id, &memory);
					clear_buffer();
					if(mem_capacity >= memory && !isIdExist(&Q, id) && numOfProcess >= 1 && id>0 && id < 10){
						enQueue(&Q, memory , id);
						mem_capacity -= memory;
						numOfProcess -= 1;
					}
					else{
						printf("Out of memory! or ID exist!\n");
					}
					break;
				case 2:
					printf("ID? : \n");
					scanf("%d", &id);
					clear_buffer();
					killID(&Q, id);
					break;
				case 3:
					printf("------In process------\n");
					displayAll(&Q);
					break;
				default:
					printf("Enter a number 1-4 please\n");
					break;
			} 
			printf("----------------------\n");

		}while(choice != 4);
	}
	else{
		printf("Not in form. (program #ofprocess memory_capacity)\n");
	}
}