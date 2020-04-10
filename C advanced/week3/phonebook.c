#include <stdlib.h>
#include "phonebook.h"

#define INITIAL_SIZE 10
#define INCREMENTAL_SIZE 5

phonebook createPhoneBook(){
	phonebook pb;
	pb.entries = (PhoneEntry*)malloc(INITIAL_SIZE*sizeof(PhoneEntry))
	pb.total = 0;
	pb.size = INITIAL_SIZE;
	return pb;
}

void dropPhoneBook(PhoneBook *pb){
	free(pb->entries);
}

void addPhoneNumber(char *name, long number, PhoneBook *book){
	PhoneEntry *e = getPhoneNumber(name, book);
	PhoneEntry *new_entries;
	if(e == NULL){
		if(book->total >= book->size){
			new_entries = (PhoneEntry*)malloc((book->size + INCREMENTAL_SIZE)*sizeof(PhoneEntry));
			memcpy(new_entries, book->entries, sizeof(book->total * sizeof(PhoneEntry)));
			book->entries= new_entries;
			book->size += INCREMENTAL_SIZE;
		}
		else{
			strcpy(book->entries[book->total]->name, name);
			book->entries[book->total]->number = number;
			book->total++;
		}
	}
	else{
		e->number = number;
	}

}

PhoneEntry *getPhoneNumber(char *name, phoneBook *book){
	int i;
	for (i = 0; i < book->total; ++i){
		if(strcmp(name, book->entries[i]->name) == 0) break;
	}
	if(i < book->total) return &(book->entries[i]);
	else return NULL;
}