#ifndef __SYMBOL_TABLE
#define __SYMBOL_TABLE

#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 10

typedef struct {
	void *key;
	void *value;
} Entry;

typedef Entry *(* New_entry_function)(void *, void *);
typedef int (* Compare_key_function)(void *, void *);

typedef struct {
	Entry *entries;
	int size;
	int nmemb;
	New_entry_function new_entry;
	Compare_key_function cmp;
} Symbol_table;

Symbol_table *new_symbol_table(New_entry_function new_entry, Compare_key_function cmp) {
	Symbol_table *ret = (Symbol_table *)malloc(sizeof(Symbol_table));
	Entry *entries = (Entry *)malloc(DEFAULT_SIZE * sizeof(Entry));

	ret->entries = entries;
	ret->size = DEFAULT_SIZE;
	ret->new_entry = new_entry;
	ret->cmp = cmp;
	ret->nmemb = 0;
	return ret;
}

Entry *get_entry_by_key(Symbol_table *container, void *search_key) {
	int nmemb = container->nmemb;
	Entry *entries = container->entries;
	Compare_key_function cmp = container->cmp;
	for (int i = 0; i < nmemb; i++) {
		if (cmp(entries[i].key, search_key) == 0) {
			return entries + i;
		}
	}
	return NULL;
}

void modify_entry_value(Entry *old_entry, void *new_value) {
	old_entry->value = new_value;
	return;
}

void double_symbol_table_size(Symbol_table *symbol_table) {
	int old_size = symbol_table->size;
	int new_size = old_size * 2;
	Entry *old_entries = symbol_table->entries;

	Entry *new_entries = (Entry *)realloc(old_entries, new_size * sizeof(Entry));
	
	symbol_table->entries = new_entries;
	symbol_table->size = new_size;
	return;
}

void append_entry_to_table(Symbol_table *container, Entry *new_entry) {
	int size = container->size;
	int nmemb = container->nmemb;
	
	if (nmemb == size) {
		double_symbol_table_size(container);
	}
	
	container->entries[nmemb] = *new_entry;
	container->nmemb ++;
	free(new_entry);
	return;
}

void add(Symbol_table *container, void *key, void *value) {
	
	Entry *search_entry = get_entry_by_key(container, key);
	if (search_entry == NULL) {
		Entry *new_entry = container->new_entry(key, value);
		append_entry_to_table(container, new_entry);
	} else {
		modify_entry_value(search_entry, value);
	}
	return;
}




#endif
