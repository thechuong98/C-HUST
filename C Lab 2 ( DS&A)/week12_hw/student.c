#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CbinaryTree.h"
#include "Cqueue.h"

typedef struct student{
	char name[30];
} student;

int compare_dic_order(void *student1, void *student2){
	student *s1 = (student *)student1;
	student *s2 = (student *)student2;
	char s1_name[30]; //phai tao string thay the vi strtok thay doi char *
	char s2_name[30]; //de lam cho du lieu bi thay doi
	strcpy(s1_name, s1->name);
	strcpy(s2_name, s2->name);
	char first_s1[20];
	char first_s2[20];
	char mid_s1[20];
	char mid_s2[20];
	char last_s1[20];
	char last_s2[20];
	//s1
	char *token1 = strtok(s1_name, " ");
	strcpy(first_s1, token1);
	token1 = strtok(NULL, " ");
	strcpy(mid_s1, token1);
	token1 = strtok(NULL, " ");
	strcpy(last_s1, token1);
	//s2
	char *token2 = strtok(s2_name, " ");
	strcpy(first_s2, token2);
	token2 = strtok(NULL, " ");
	strcpy(mid_s2, token2);
	token2 = strtok(NULL, " ");
	strcpy(last_s2, token2);
	//compare 
	if(strcmp(last_s1, last_s2) > 0) return 1;
	else if(strcmp(last_s1, last_s2) < 0) return -1;
	else{
		if(strcmp(mid_s1, mid_s2) > 0) return 1;
		else if(strcmp(mid_s1, mid_s2) < 0) return -1;
		else{
			if(strcmp(first_s1, first_s2) > 0) return 1;
			else if(strcmp(first_s1, first_s2) < 0) return -1;
			else return 0;
		}
	}

}

int compare_dic_order_name(void *student1, void *student2){
	student *s1 = (student *)student1;
	student *s2 = (student *)student2;
	char s1_name[30]; //phai tao string thay the vi strtok thay doi char *
	char s2_name[30]; //de lam cho du lieu bi thay doi
	strcpy(s1_name, s1->name);
	strcpy(s2_name, s2->name);
	char first_s1[20];
	char first_s2[20];
	char mid_s1[20];
	char mid_s2[20];
	char last_s1[20];
	char last_s2[20];
	//s1
	char *token1 = strtok(s1_name, " ");
	strcpy(first_s1, token1);
	token1 = strtok(NULL, " ");
	strcpy(mid_s1, token1);
	token1 = strtok(NULL, " ");
	strcpy(last_s1, token1);
	//name
	//compare 
	if(strcmp(last_s1, s2->name) > 0) return 1;
	else if(strcmp(last_s1, s2->name) < 0) return -1;
	else return 0;
}

treeNode *tree_find_name(treeNode *root, char *name, comparator cmp){
	student *node = (student *)malloc(sizeof(student));
	memcpy(node->name, name, sizeof(student)); //cho nay neu de strlen(word) thi co the word la "i\000" nhung node->word lai la "i\177 => k co terminate
	treeNode *temp;
	if(root == NULL) return NULL;
	if(cmp(root->data, node) == 0) return root;
	else if(cmp(root->data, node) > 0) temp = tree_find_name(root->left, name, cmp);
	else temp = tree_find_name(root->right, name, cmp);
	return temp;
}

void read_file_insert(char *f, treeNode **BST){
	FILE *fin = fopen(f, "r");
	if(fin == NULL) return;
	char buff[100];
	while(fgets(buff, 100, fin) != NULL){
		student *a = (student *)malloc(sizeof(student));
		buff[strlen(buff)-1] = '\0';
		strcpy(a->name, buff);
		tree_insert_bst(BST, a, sizeof(student), compare_dic_order);
	}
	fclose(fin);
}

void iterator_student(void *data){
	student *a = (student *)data;
	printf("%s\n", a->name);
}

void BFS(treeNode *root){
	queue Q;
    queue_new(&Q, sizeof(treeNode));
    enQueue(&Q, &root);
    while(!isEmptyQueue(&Q)){
    	treeNode *tmp = malloc(sizeof(treeNode));
    	deQueue(&Q, &tmp);
    	if(tmp->right != NULL) enQueue(&Q, &tmp->right);
    	if(tmp->left != NULL) enQueue(&Q, &tmp->left);
    	iterator_student(tmp->data);
    }
    return;
}

int main(){
	tree tree;
	tree_new(&tree, sizeof(student));
	int opt;
	do{
    	printf("\nStudent List!\n");
    	printf("1. Read File\n");
    	printf("2. Print Result\n");
    	printf("3. Search name\n");
    	printf("5. BFS\n");
    	printf("4. Quit\n");
    	printf("Your choice:");
    	scanf("%d",&opt);

	    switch(opt){
    		case 1:{
				read_file_insert("Studentlist.txt", &(tree.root));
				break;
      		}
    		case 2:{
				LDR(tree.root, iterator_student);
				break;
    	  	}
    		case 3: {
				char lname[20];
				printf("Enter the last name: ");
				scanf("%s", lname);
				treeNode *tmp = tree_find_name(tree.root, lname, compare_dic_order_name);
				if(tmp != NULL) iterator_student(tmp->data);	
				else printf("Dont have the student\n");	
				break;		
      		}
    		case 4:
      		{
			printf("Many Thanks\n");
			break;
     	 	}
     	 	case 5:{
     	 		BFS(tree.root);
     	 		break;
     	 	}
   	 		default:{
    		  	printf("PLEASE choose the option from 1 - 4 !!\n");
   	 			break;
			}
		} 
  	}while( opt != 4);
}
