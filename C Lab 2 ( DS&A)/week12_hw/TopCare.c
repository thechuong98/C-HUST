#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CbinaryTree.c"

typedef struct customer{
	char ID[11];
	char name[30];
	int cost;
	int TP;
	int DT;
	int MM;
} customer;

int compare_dic_order(void *customer1, void *customer2){
	customer *c1 = (customer *)customer1;
	customer *c2 = (customer *)customer2;
	return strcmp(c1->name, c2->name);
}

treeNode *tree_find_customer(treeNode *root, char *name, comparator cmp){
	customer *node = (customer *)malloc(sizeof(customer));
	memcpy(node->name, name, sizeof(customer)); //cho nay neu de strlen(word) thi co the word la "i\000" nhung node->word lai la "i\177 => k co terminate
	treeNode *temp;
	if(root == NULL) return NULL;
	if(cmp(root->data, node) == 0) return root;
	else if(cmp(root->data, node) > 0) temp = tree_find_customer(root->left, name, cmp);
	else temp = tree_find_customer(root->right, name, cmp);
	return temp;
}

void read_file(char *in, treeNode **BST){
	FILE *fin = fopen(in, "r");
	char buffer[100];
	while(fgets(buffer, 100, fin) != NULL){
		customer Customer;
		Customer.TP = 0;
		Customer.DT = 0;
		Customer.MM = 0;
		//tokenize the string
		char *token = strtok(buffer, "\t");
		strcpy(Customer.ID, token);
		token = strtok(NULL, "\t");
		strcpy(Customer.name, token);
		token = strtok(NULL, "\t");
		int TP = atoi(token);
		token = strtok(NULL, "\t");
		int DT = atoi(token);
		token = strtok(NULL, "\t");
		int MM = atoi(token);
		treeNode *tmp = tree_find_customer(*BST, Customer.name, compare_dic_order);
		if(tmp == NULL){
			Customer.cost = TP + DT + MM;
			if(TP != 0){
				Customer.TP = 1;
			}
			if(DT != 0){
				Customer.DT = 1;
			}
			if(MM != 0){
				Customer.MM = 1;
			}
			tree_insert_bst(BST, &Customer, sizeof(customer), compare_dic_order);
		}
		else{
			((customer *)(tmp->data))->cost += TP + DT + MM;
			if(TP != 0) ((customer *)(tmp->data))->TP++;
			if(DT != 0) ((customer *)(tmp->data))->DT++;
			if(MM != 0) ((customer *)(tmp->data))->MM++;
		}
	}
}

void iterator_cus(void *data){
	customer *a = (customer *)data;
	printf("%-11s\t%-30s\t%-10d\tTP=%d DT=%d MM=%d\n", a->ID, a->name, a->cost, a->TP, a->DT, a->MM);
}

int main(){
	tree tree;
	tree_new(&tree, sizeof(customer));
	read_file("Topcare.txt", &(tree.root));
	LDR(tree.root, iterator_cus);
}