#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../lib/sort/quickSort.h"
#include "../lib/random/rand.c"

typedef struct {
	char *name;
	char *phoneNumber;
} PhoneBook;

void printPhoneBooks(PhoneBook *arr, int nmemb) {
	printf("\n----------------------------------\n");
	for (int i = 0; i < nmemb; i++) {
		printf("%s %s\n", arr[i].name, arr[i].phoneNumber);
	}
	printf("-----------------------------------\n");
	return;
}

PhoneBook getRandPhoneBook() {
	char *randName = randString(10);
	char *randPhoneNum = randPhoneNumber(10);
	PhoneBook phonebook;
	phonebook.name = randName;
	phonebook.phoneNumber = randPhoneNum;
	return phonebook;
}

PhoneBook *generateRandPhoneBookArray(int nmemb) {

	PhoneBook *arr = (PhoneBook *)malloc( nmemb * sizeof(PhoneBook));
	for (int i = 0; i < nmemb; i++) {
		arr[i] = getRandPhoneBook();
	}
	return arr;
}

void writePhoneBooksToFile(char *fn, PhoneBook *arr, int nmemb) {

	FILE *f = fopen(fn, "w+");
	if (f == NULL) {
		printf("Can not open file to write \n");
		return;
	}

	for (int i = 0; i < nmemb; i++) {
		fprintf(f, "%s %s\n", arr[i].name, arr[i].phoneNumber);
	}

	fclose(f);
	return;
}

PhoneBook *ReadPhoneBooksFromFile (char *fn, int *nmemb) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file to read! \n");
		return NULL;
	}

	fscanf(f, "%d ", nmemb);
	PhoneBook *arr = (PhoneBook *)malloc( (*nmemb) * sizeof(PhoneBook));

	int i = 0;
	char buff[100];
	while (fgets(buff, 100, f) != NULL) {
		char *name = (char *)malloc(30 * sizeof(char));
		char *phoneNumber = (char *)malloc(30 * sizeof(char));
		sscanf(buff, "%s %s", name, phoneNumber);
		arr[i].name = name;
		arr[i].phoneNumber = phoneNumber;
		i++;
	}
	
	return arr;
}

int cmpPhoneBookByName(void const *a, void const *b) {
	PhoneBook *ptr_a = (PhoneBook *)a;
	PhoneBook *ptr_b = (PhoneBook *)b;
	return strcmp(ptr_a->name, ptr_b->name);
}

int main() {

	int n;
	PhoneBook *arr = ReadPhoneBooksFromFile("phonebook.txt", &n);
	quick_sort_two_way(arr, 0, n - 1, sizeof(PhoneBook), cmpPhoneBookByName);
	printPhoneBooks(arr, n);
	return 0;
}