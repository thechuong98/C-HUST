#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/ADT/symbol_table.h"

Entry *new_phone_book_entry(void *key, void *value) {
	Entry *new_entry = (Entry *)malloc(sizeof(Entry));
	new_entry->key = key;
	new_entry->value = value;
	return new_entry;
}

int key_cmp(void *entry_key, void *search_key) {
	return strcmp((char *)entry_key, (char *)search_key);
}

int main() {

	Symbol_table *phone_book =
		new_symbol_table(new_phone_book_entry, key_cmp);

	add(phone_book, "Thanh", "111");
	add(phone_book, "Dung", "222");
	add(phone_book, "Chuong", "333");
	add(phone_book, "Tung", "444");
	add(phone_book, "Ngoc", "555");
	add(phone_book, "Phung", "666");
	add(phone_book, "Vinh", "777");
	add(phone_book, "Long", "888");
	add(phone_book, "Quang", "999");
	add(phone_book, "Hieu", "101010");
	add(phone_book, "Binh", "111111");
	

	Entry *phone_book_entry = get_entry_by_key(phone_book, "Binh");
	printf("pointer: %p \n", phone_book_entry);
	printf("value : %s \n", (char *)phone_book_entry->value);
	return 0;
}
