#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CSlist.h"

int main(){
	list testList;
	list_new(&testList, sizeof(int));

	int a = 5;
	list_prepend(&testList, &a);

	int b = 6;
	list_prepend(&testList, &b);
	list_prepend(&testList, &b);

	int c = 7;
	list_insert(&testList, &c, list_size(&testList)+1);
	list_insert(&testList, &c, list_size(&testList)+1);

	// int d = 7;
	// list_delete_data(&testList, &d, is_Same_int);

	// list_reverse(&testList);
	printf("list_size : %d\n", list_size(&testList));
	delete_duplicates(&testList);
	printf("list_size : %d\n", list_size(&testList));	
	list_for_each(&testList, iterator_int);
}