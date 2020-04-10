#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>

typedef int element;



void insert_sort(element list[], int n){
	int i,j;
	element next;
	for(i=1; i<n; i++){
		next = list[i];
		for(j=i-1;j>=0 && next<list[j];j--){
			list[j+1]=list[j];
		}
		list[j+1]=next;
	}
}

void select_sort(element list[], int n){
	int i,j,min,tmp;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++)
			if(list[j]<list[min])
				min=j;
		tmp = list[i];
		list[i] = list[min];
		list[min]=tmp;
	}
}

void bubble_sort(element arr[], int n)
{
   int i, j, tmp;
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1]){
           		tmp=arr[j];
           		arr[j]=arr[j+1];
           		arr[j+1]=tmp;
           }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    element tmp;
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
    	tmp=arr[i];
        arr[i]= arr[largest];
        arr[largest]=tmp;
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heap_sort(int arr[], int n)
{
	element tmp;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        tmp=arr[0];
        arr[0]= arr[i];
        arr[i]=tmp;
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



void insert(int *list,int n){
	clock_t tic = clock();
	insert_sort(list,n);
	clock_t toc = clock();

	printf("Elapsed time of insertion sort: %f seconds\n",(double) (toc-tic)/CLOCKS_PER_SEC);

	FILE *f=fopen("insert_sort.txt","w");
	if(f==NULL){
		printf("Cannot open file insert_sort.txt\n");
		return;
	}

	for(int i=0;i<n;i++){
		fprintf(f,"%d   ",list[i]);
	}
	fclose(f);
	printf("The list has been saved to file \"insert_sort.txt\"\n");
}



void select_(int * list2,int n2){
	clock_t tic = clock();
	select_sort(list2,n2);
	clock_t toc = clock();

	printf("Elapsed time of selection sort: %f seconds\n",(double) (toc-tic)/CLOCKS_PER_SEC);

	FILE *f=fopen("select_sort.txt","w");
	if(f==NULL){
		printf("Cannot open file select_sort.txt\n");
		return;
	}

	for(int i=0;i<n2;i++){
		fprintf(f,"%d   ",list2[i]);
	}
	fclose(f);
	printf("The list has been saved to file \"select_sort.txt\"\n");
}

void bubble(int *list3,int n3){
	clock_t tic = clock();
	select_sort(list3,n3);
	clock_t toc = clock();

	printf("Elapsed time of bubble sort   : %f seconds\n",(double) (toc-tic)/CLOCKS_PER_SEC);

	FILE *f=fopen("bubble_sort.txt","w");
	if(f==NULL){
		printf("Cannot open file bubble_sort.txt\n");
		return;
	}

	for(int i=0;i<n3;i++){
		fprintf(f,"%d   ",list3[i]);
	}
	fclose(f);	
	printf("The list has been saved to file \"bubble_sort.txt\"\n");
}

void heap(int *list4,int n4){
	clock_t tic = clock();
	heap_sort(list4,n4);
	clock_t toc = clock();

	printf("Elapsed time of heap sort   : %f seconds\n",(double) (toc-tic)/CLOCKS_PER_SEC);

	FILE *f=fopen("heap_sort.txt","w");
	if(f==NULL){
		printf("Cannot open file heap_sort.txt\n");
		return;
	}

	for(int i=0;i<n4;i++){
		fprintf(f,"%d   ",list4[i]);
	}
	fclose(f);
	printf("The list has been saved to file \"heap_sort.txt\"\n");

}

int main(){

	int i,option;
	int *list;
	int n=200000;

	list = (int *) malloc (n*sizeof(int));

	while (option!=6){
		printf("__________MENU__________\n");
		printf("1.Initialize the list\n");
		printf("2.Insertion Sort\n");
		printf("3.Selection Sort\n");
		printf("4.Bubble Sort\n");
		printf("5.Heap Sort\n");
		printf("6.Exit\n");
		printf("Your choice: "); scanf("%d",&option);
		while (option<1 || option>6){
			printf("Invalid value!\n");
			printf("Your choice: "); scanf("%d",&option);
		}
		__fpurge(stdin);

		switch(option){
			case 1:{
				srand(time(NULL));
				for(i=0;i<n;i++)
					list[i]=rand()%3000000;
				

				/*for(i=0;i<n;i++)
					printf("%d  ",list[i]);
				printf("Done!\n");*/

				break;
			}
			case 2:{
				insert(list,n);
				break;
			}
			case 3:{
				select_(list,n);
				break;
			}
			case 4:{
				bubble(list,n);
				break;
			}
			case 5:{
				heap(list,n);
				break;
			}
		}
	}

	free(list);
	return 0;
}