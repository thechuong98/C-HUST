#include "dll_phone.c"
typedef char* keyType;

node *sentinelSearch(node *root, keyType key){
  node *cur = root;
  while(cur->next != NULL){ //get Tail
    cur = cur->next;
  }
  node *tail = cur;

  T last = tail->data; // now cur is last node;
  strcpy(tail->data.model, key);
  //start searching
  cur = root;
  int i = 1;
  while(strcmp(cur->data.model, key) != 0 && cur->next != NULL){
    cur = cur->next;
    i++;
  }
  tail->data = last;
  if(i < listLength(root) || (strcmp(key, cur->data.model) == 0)){
    return cur;
  }
  else{
    return NULL;
  }
}

int compare(node *a, node *b){
	if(a == NULL || b == NULL) return 0;
	if(strcmp(a->data.model, b->data.model) == 0 &&
		strcmp(a->data.rom, b->data.rom) == 0 &&
		a->data.display == b->data.display &&
		strcmp(a->data.price, b->data.price) == 0) return 1;
	else return 0;
}


void verify1(node *root1, node *root2){
	printf("List of products found in list 1 but not in list 2 : \n");
	int count = 0;
	for(node *cur1 = root1; cur1->next != NULL; cur1 = cur1->next){
		// for(node *cur2 = root2; cur2->next!= NULL; cur2 = cur2->next){
		if(sentinelSearch(root2, cur1->data.model) == NULL){
			count++;
			printf("%d. %s\n", count, cur1->data.model);	
		}	
		// }
	}

}

void verify3(node *root1, node *root2){
	printf("List of products found in list 1 and in list 2 but not the same : \n");
	int count = 0;
	for(node *cur1 = root1; cur1->next != NULL; cur1 = cur1->next){
		if(compare(sentinelSearch(root2, cur1->data.model), cur1)){
			count++;
			printf("%d. %s\n", count, cur1->data.model);
		}
	}
}


int main(){
	int n1 = lineCounter("phoneDB_1.txt");
	int n2 = lineCounter("phoneDB_2.txt");
	phone *phones1 = (phone *)malloc(n1*sizeof(phone));
	phone *phones2 = (phone *)malloc(n2*sizeof(phone));
	txt2bin("phoneDB_1.txt", "phoneDB_1.dat", phones1, n1);
	txt2bin("phoneDB_2.txt", "phoneDB_2.dat", phones2, n2);
	node *root1 = NULL;
	node *root2 = NULL;
	readDatatoList("phoneDB_1.dat", &root1);
	readDatatoList("phoneDB_2.dat", &root2);
	traversingList(root1);
	traversingList(root2);
	int option;
	do{
		printf("---------------------------------\n");
		printf("\n1. All records found in list 1 but not in list 2\n2. All records found in list 2 but not in list 1\n3. All records that are in list 1 and list 2 with the same key but have different values for different field\n4.Quit\n\n");
		printf("Your choice: "); scanf("%d", &option);
		printf("---------------------------------\n");
		switch(option){
			case 1:
			verify1(root1, root2);
			break;
			case 2:
			verify1(root2, root1);
			break;
			case 3:
			verify3(root1, root2);
			break;
			case 4:
			break;
			default: printf("Wrong choice!!!\n\n");
		}
	}while(option!=4);
}