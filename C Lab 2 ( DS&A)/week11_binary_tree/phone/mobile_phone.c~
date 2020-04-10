#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_tree_phone.c"

int main(){
	int n = lineCounter("phone_address.txt");
	T *data = (T *)malloc(n*sizeof(T));
	treeNode *root = NULL;
	int choice = 0;
	char fn3[30];
	char email[30];
	do{
		printf("------------------\n");
		printf("1.Read data and print tree\n");
		printf("2.find and print to a file\n");
		printf("3.print in order to a file\n");
		printf("5.print Max, Min\n");
		printf("4.quit\n");
		printf("------------------\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				txt2tree("phone_address.txt", "phone_address.dat", data, n, &root);
				traversing(root);
				break;
			case 2:
				printf("What email you want to find : ");
				scanf("%s", email);
				treeNode *fNode = searchEmail(root, email);
				FILE *f = fopen("search.txt", "a+");
				printNode(f, fNode);
				fclose(f);
				break;
			case 3:
				printf("Enter the file name: ");
				scanf("%s", fn3);
				FILE *fout = fopen(fn3, "w+");
				printLDR(fout, root);
				fclose(fout);
				break;
			case 4:
				break;
			case 5:
				printNode(stdout, findMin(root));
				printNode(stdout, findMax(root));
				break;
			default:
				printf("Wrong choice !! \n");
		}
	} while(choice != 4);

}




