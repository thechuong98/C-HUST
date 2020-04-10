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