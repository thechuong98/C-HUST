#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../lib/sort/quickSort.h"
#include "../lib/random/rand.c"

int *generateRandArray(int nmemb) {
	int *arr = (int *)malloc(nmemb * sizeof(int));
	srand(time(0));
	
	for (int i = 0; i < nmemb; i++) {
		arr[i] = rand();
	}
	
	return arr;
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int cmpInt(void const *a, void const *b) {
	int val_of_a = *(int *)a;
	int val_of_b = *(int *)b;
	return val_of_a - val_of_b;
}

typedef void (*runFunc )(void *, int, int, int , comparator);

void calculateRunTime(runFunc sort, char *testName) {

	int n = 1000000;
	int *arr = generateRandArray(n);
	
	clock_t begin = clock();
	sort(arr, 0, n - 1, sizeof(int), cmpInt);
	clock_t end = clock();

	double runTime = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("----------------------------------------\n");
	printf("%s :\n", testName);
	printf("length of array : n = %d\n", n);
	printf("Run time : %lf \n", runTime);
	printf("----------------------------------------\n");
	
	return;
}

int main() {
	calculateRunTime(quick_sort_two_way, "quick sort two way");
	calculateRunTime(quick_sort_three_way, "quick sort three way");
	return 0;
}