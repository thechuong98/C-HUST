#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CbinaryTree.c"

typedef struct dataField{
	int count;
	char word[15];
} dataField;

int compare_dic_order(void *word1, void *word2){
	dataField *w1 = (dataField *)word1;
	dataField *w2 = (dataField *)word2;
	return strcmp(w1->word, w2->word);
}

void iterator_word(void *data){
	dataField *a = (dataField *)data;
	printf("%s : %d\n", a->word, a->count);
}

treeNode *tree_find_word(treeNode *root, char *word, comparator cmp){
	dataField *node = (dataField *)malloc(sizeof(dataField));
	memcpy(node->word, word, sizeof(dataField)); //cho nay neu de strlen(word) thi co the word la "i\000" nhung node->word lai la "i\177 => k co terminate
	treeNode *temp;
	if(root == NULL) return NULL;
	if(cmp(root->data, node) == 0) return root;
	else if(cmp(root->data, node) > 0) temp = tree_find_word(root->left, word, cmp);
	else temp = tree_find_word(root->right, word, cmp);
	return temp;
}

void wordCount(char *name, treeNode **BST){
	FILE *fin = fopen(name, "r");
	if(fin == NULL) return;
	else{
		char tmp[15];
		while(fscanf(fin, "%s", tmp) != EOF){
			if(tree_find_word(*BST, tmp, compare_dic_order) == NULL){
				dataField *node = (dataField *)malloc(sizeof(dataField));
				memcpy(node->word, tmp, sizeof(tmp));
				node->count = 1;
				tree_insert_bst(BST, node, sizeof(dataField), compare_dic_order);
			}
			else{
				dataField *temp = (dataField *)tree_find_word(*BST, tmp, compare_dic_order)->data;
				temp->count++;
			}
		}
	}
	fclose(fin);
}




int main(){
	tree tree;
	tree_new(&tree, sizeof(dataField));
	int opt=0;
  	do{
    	printf("\nWord Count!\n");
    	printf("1. Read File\n");
    	printf("2. Print Result\n");
    	printf("3. Search Word\n");
    	printf("4. Quit\n");
    	printf("Your choice:");
    	scanf("%d",&opt);

	    switch(opt){
    		case 1:{
				wordCount("text.txt", &(tree.root));
				break;
      		}
    		case 2:{
				LDR(tree.root, iterator_word);
				break;
    	  	}
    		case 3: {
				char word[15];
				printf("Enter the word: ");
				scanf("%s", word);
				treeNode *tmp = tree_find_word(tree.root, word, compare_dic_order);
				if(tmp != NULL) iterator_word(tmp->data);	
				else printf("Dont have the word\n");	
				break;		
      		}
    		case 4:
      		{
			printf("Many Thanks\n");
			break;
     	 	}
   	 		default:{
    		  	printf("PLEASE choose the option from 1 - 4 !!\n");
   	 			break;
			}
		} 
  	}while( opt != 4);
  return 0;	
}