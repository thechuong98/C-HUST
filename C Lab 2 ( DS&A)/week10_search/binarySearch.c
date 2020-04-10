#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binarySearch(int List[],int val, int low, int high){
  if(high > low){
    int mid = (low+high)/2;
    if(List[mid] == val){
      return 1;
    }
    else{
      if(List[mid] > val) binarySearch(List, val, low, mid-1);
      else binarySearch(List, val, mid+1, high);
    }
  }
  return 0;
}

int main(){
  int List[5] = {1,2,3,4,5};
  printf("6 is in the list : %d\n", binarySearch(List, 6, 0, 4)); 
}
