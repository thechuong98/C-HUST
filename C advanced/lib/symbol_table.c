#include "symbol_table.h"

symbol_table *new_symbol_table(New_entry_function new_entry, Compare_key_function cmp){
	symbol_table *sym_tab = (symbol_table *)malloc(sizeof(symbol_table));
	Entry *entries = (Entry *)malloc(DEFAULT_SIZE * sizeof(Entry));
	sym_tab->entries = entries;
	sym_tab->size = DEFAULT_SIZE;
	sym_tab->nmemb = 0;
	sym_tab->new_entry = new_entry;
	sym_tab->cmp = cmp;

	return sym_tab;
}

Entry *get_entry_by_key(symbol_table sym_tab, void *search_key){
	int nmemb = sym_tab->nmemb;
	Entry *entries = sym_tab->entries;
	Compare_key_function cmp = sym_tab->cmp;
	for(int i = 0; i < nmemb; ++i){
		if(cmp(entries[i].key,  search_key) == 0 ){
			return entries + i;
		}
	}
	return NULL;
}

void modify_entry_value(Entry *old_entry, void *new_value) {
	old_entry->value = new_value;
	return;
}

void double_symbol_table_size(symbol_table *sym_tab) {
	int old_size = sym_tab->size;
	int new_size = old_size * 2;
	Entry *old_entries = sym_tab->entries;

	Entry *new_entries = (Entry *)realloc(old_entries, new_size * sizeof(Entry));
	
	sym_tab->entries = new_entries;
	sym_tab->size = new_size;
	return;
}

void append_entry_to_table(symbol_table *sym_tab, Entry *new_entry) {
	int size = sym_tab->size;
	int nmemb = sym_tab->nmemb;
	
	if (nmemb == size) {
		double_symbol_table_size(sym_tab);
	}
	
	sym_tab->entries[nmemb] = *new_entry;
	sym_tab->nmemb ++;
	free(new_entry);
	return;
}

void add(symbol_table *sym_tab, void *key, void *value) {
	
	Entry *search_entry = get_entry_by_key(sym_tab, key);
	if (search_entry == NULL) {
		Entry *new_entry = sym_tab->new_entry(key, value);
		append_entry_to_table(sym_tab, new_entry);
	} else {
		modify_entry_value(search_entry, value);
	}
	return;
}

void drop_symbol_table(symbol_table *sym_tab) {
  free(sym_tab->entries);
  return;
}
