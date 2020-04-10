// ------------hw111.c----------------------
#include<stdio.h>

int countEven(int* a, int size){
   int count = 0;
   for(int i = 0; i < size; ++i){
       if (*(a+i) % 2 == 0)
           count++;
   }
   return count;
}

int main(){
   int a[6] = {1,2,3,4,5,6};
   int count = countEven(a, 6);
   printf("%d\n", count);

   return 0;
}
// -----------hw112.c------------------------
#include<stdio.h>

double *maximum(double *a, int size){
	double *ptr = NULL;
	if (size == 0) return NULL;
	double max = a[0];
	for (int i = 1; i < size; ++i){
	if (*(a+i) >= max) {
           max = *(a+i);
           ptr = a+i;
       }
   }
   return ptr;
}

int main(){
   double a[5] = {1,2,3,4,5};
   double *ptr = maximum(a, 5);
   printf("%p, %p", a, ptr);

   return 0;
}

// ------------hw113.c-----------------------
#include<stdio.h>

void subArr(int *a, int size){
	for(int i = 0; i < size; ++i){
       for (int j = i; j < size; ++j){
           for (int k = i; k <= j; ++k)
               printf("%d", a[k]);
               printf("\n");
       }
   }

}

int main(){
   	int a[4] = {1,2,3,4};
   	subArr(a, 4);
	return 0;
}

// -------------hw114.c----------------------
#include <stdio.h>

void reverseIndex(int *a, int size){
	int temp = 0;
	for (int i = 0; i < size; ++i){
		int j = size - i - 1;
		if (i < j){
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	for (int k = 0; k < size; ++k){
		printf("%d", a[k]);
	}
	printf("\n");
}

void reversePtr(int *a, int size){
	int temp = 0;
	for (int i = 0; i < size; ++i){
		int j = size - i - 1;
		if (i < j){
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
		}
	}
	for (int k = 0; k < size; ++k){
		printf("%d", *(a+k));
	}
	printf("\n");
}

int main(){
	int a[5] = {1,2,3,4,5};
	reverseIndex(a, 5);
	int b[5] = {6,7,8,9,10};
	reversePtr(b, 5);

	return 0;
}
