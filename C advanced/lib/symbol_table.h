/*
*/
#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_
#include "typedef.h"

#define DEFAULT_SIZE 10

typedef struct{
	void *key;
	void *value;
} Entry;

typedef Entry *(*new_entry_function)(void *, void *);
typedef int (*compare_key_function)(void *, void *);

typedef struct {
	Entry *entries;
	int size;
	int nmemb;
	New_entry_function new_entry;
	Compare_key_function cmp;
} symbol_table;

symbol_table *new_symbol_table(New_entry_function new_entry, Compare_key_function cmp);
Entry *get_entry_by_key(symbol_table *sym_tab, void *key);
void modify_value(Entry *entry, void *new_val);
void double_symbol_table_size(symbol_table *sym_tab);
void append(symbol_table *sym_tab, Entry *new_entry);
void add(symbol_table *sym_tab, void *key, void *value);
void drop(symbol_table *sym_tab);

#endif