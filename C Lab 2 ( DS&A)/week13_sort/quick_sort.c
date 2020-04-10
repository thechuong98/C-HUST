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

void swap(int arr[], int x, int y){
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

int Partition(int arr[], int left, int right){
  int pivot = left;
  swap(arr, pivot, right);
  for(int i = left; i < right; ++i){
    if(arr[i] <= arr[right]){
      swap(arr, i, left);
      left += 1;
    }
  }
  swap(arr, left, right);
  return left;
  
}

void quick_sort(int arr[], int left, int right){
  int pivot;
  if(left < right){
    pivot = Partition(arr, left, right);
    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot+1, right);
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
  quick_sort(arr, 0, sizeof(arr)/sizeof(int)-1);
  print_to_file("quick_sort.txt", arr, 200000);
}
