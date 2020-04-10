#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CSlist.h"

void data_generate(char *fn){
  FILE *fin = fopen(fn, "w+");
  srand(time(NULL));
  for(int i = 0; i < 200000; ++i){
    int rand_num = rand()%10000;
    fprintf(fin, "%d ", rand_num);
  }
  fclose(fin);
}

void data_to_array(char *fn, int arr[], int n){
  FILE *fin = fopen(fn, "r");
  int num;
  int i = 0;
  while(fscanf(fin, "%d", &num) == 1){
    arr[i] = num;
    i++;
  }
  fclose(fin);
}

void merge(int arr[], int low, int mid, int high){
  int i, j, k;
  int n1 = mid-low+1;
  int n2 = high-mid;
  //Creat temp arr;
  int L[n1], R[n2];
  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[low + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1+ j];
  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = low; // Initial index of merged subarray
  while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
        {
	  arr[k] = L[i];
	  i++;
        }
      else
        {
	  arr[k] = R[j];
	  j++;
        }
      k++;
    }
  
  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }
  
  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
}

void merge_sort(int arr[], int low, int high){
  int mid;
  if(low < high){
    mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
  }
}

void print_to_file(char *fn, int arr[], int n){
  FILE *fout = fopen(fn, "w+");
  for(int i = 0; i < n; ++i){
    fprintf(fout, "%d ", arr[i]);
  }
}

int main(){
  int arr[200000];
  data_generate("int_arr.txt");
  data_to_array("int_arr.txt", arr, 200000);
  merge_sort(arr, 0, sizeof(arr)/sizeof(int)-1);
  //print_to_file("quick_sort.txt", arr, 200000);
  for(int i = 0; i < 200000; ++i){
    printf("%d ", arr[i]);
  }
}
