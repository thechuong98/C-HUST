#include <stdio.h>
#include "phonebook.h"

int main(){
	char name[80];
	long number;
	int choice;
	PhoneBook pb = createPhoneBook();

	do {
		printf("1. Add new \n");
		printf("2. Look up\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Name:\n"); scanf("%s", name);
				printf("Number:\n");scanf("%d", &number);
				addPhoneNumber(name, number, &pb);
				break;
		}
	}
	return 0;
}