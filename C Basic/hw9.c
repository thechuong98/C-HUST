//---------------------------hw91.c---------------------------
#include <stdio.h>

int main(){

	int A[100];

	//Input an array
	for(int i = 0; i < 100; i++){
		printf("Enter the element number %d: ", i+1);
		scanf("%d", &A[i]);
	}

	int sumOdd = 0;
	// find sum of odd number
	for(int i = 0; i < 100; i++){
		if (A[i] % 2 != 0){
			sumOdd += A[i];
		}
	}
    printf("Sum of Odd number in array: %d\n", sumOdd);

    //Find minimum
    int minElement = A[0];
    for(int i = 1; i < 100; i++){
    	if (A[i] < minElement){
    		minElement = A[i];
    	}
    }
    printf("Minimum Elements: %d\n", minElement);

}

//--------------------------hw92.c------------------------

#include <stdio.h>

int isEqual(int A[], int B[], int size){
	for(int i = 0; i < size; i++){
		if (A[i] != B[i]) return 0;
	}
	return 1;
}

int main(){
	int n = 0;
	printf("How many elements you want for both array: ");
	scanf("%d", &n);
	int A[n], B[n];
	printf("Enter the first array\n");
	for(int i = 0; i < n; i++){
		printf("Element number %d: ", i+1);
		scanf("%d", &A[i]);
	}
	printf("Enter the next one\n");
	for (int j = 0; j < n; j++){
		printf("Element number %d: ", j+1);
		scanf("%d", &B[j]);
	}

	if (isEqual(A, B, n)) printf("Two arrays are equal\n");
	else printf("Two arrays are not equal\n");
	
}

//----------------------------hw93.c----------------------

#include <stdio.h>

void DecSort(int A[], int size){
	for(int i = 0; i < (size-1); ++i){
		for (int j = 0; j < (size-i-1); ++j){
			if(A[j] < A[j+1]){
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}

void DecOddSort(int A[], int size){
	for(int i = 0; i < (size-1); ++i){ // do i times 
		for (int j = 0; j < (size-i-1); ++j){ //consider j elements after i times
			if (A[j] % 2 != 0){  //if a element doesnt divides 2, then consider it
				for(int k = 0; k < (size-j-1); ++k){ //compare it with size-j-1 elements after it
					if ((A[j+k]>A[j]) && (A[j+k] % 2 != 0)){ //swap
						int temp = A[j];
						A[j] = A[j+k];
						A[j+k] = temp;
					}
				}
			}
		}
	}
}


int main(){	
	int A[10];
	for(int i = 0; i < 10; i++){
		printf("Enter element number %d: ", i+1);
		scanf("%d", &A[i]);
	}

	//Decreasing Odd Elements Sort
	DecOddSort(A, 10);
	for(int i = 0; i < 10; ++i){
		printf("%d", A[i]);
	}
	printf("\n");

	//Decrease Sort
	DecSort(A, 10);
	for(int i = 0; i < 10; ++i){
		printf("%d", A[i]);
	}
	printf("\n");

	return 0;

}

//--------------------------------hw94.c-------------------

#include <stdio.h>

int main(){
	int a[3][3] = {{1, -2, 3}, {2, -4, 1}, {3, -5, 3}};
	int b[3][3] = {{3, -2, 2}, {1, -2, 2}, {5, -1, 2}};
	int c[3][3] = {0};
	printf("Enter elements for A and B: \n");

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			for (int k = 0; k < 3; ++k){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			printf("C%d%d: %d\n",i+1, j+1, c[i][j]);
		}
	}
}

// --------------------------------hw95.c--------------------------

#include <stdio.h>

int isSymmetric(int A[], int size){
	for (int i = 0; i < size/2; i++){
		if (A[i] != A[size-1-i]){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	int n = 0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; ++i){
		printf("Enter element number %d: ", i+1);
		scanf("%d", &A[i]);
	}
	if (isSymmetric(A, n)){
		printf("The array is symmetric\n");
	}
	else printf("The array is not symmetric\n");

	return 0;
}

// ------------------------hw96.c---------------------------------

#include <stdio.h>

void reverse(float A[], int size){
	float temp;
	for (int i = 0; i < size/2; ++i){
		temp = A[i];
		A[i] = A[size-i-1];
		A[size-i-1] = temp;
	}
}

int main(){
	int n = 0;
	printf("How many elements do you want: ");
	scanf("%d", &n);
	float A[n];

	for(int i = 0; i < n; ++i){
		printf("Enter elements number %d: ", i+1);
		scanf("%f", &A[i]);
	}

	reverse(A, n);

	for(int i = 0; i<n; ++i){
		printf("%.2f ", A[i]);
	}

	return 0;

}