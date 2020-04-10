#include<stdio.h>
#include<stdlib.h>

//Array : fixed size when declared => Use dynamically allocate memory (stdlib.h)

//malloc(nbytes)

//Always check whether memory was successfully allocated (NULL for not successful)
//ex : you want 4 memory blocks , but there are just 3 blocks, it will not successful

//Type casting : 
//int p = (int )malloc(n*sizeof(int)); // because malloc return void * ;
//(p points to a dynamic array)

int main(){
  int n, *p, more;
  printf("How many numbers do you want to enter ? \n");
  scanf("%d", &n);
  /*Allocate an int array of the proper size*/
  p = (int *)malloc(n*sizeof(int));
  if(p == NULL){
    printf("Memory allocation failed!\n");
    return 1;
  }
  
  /*Get the numbers from the user*/
  for(int i = 0; i < n; ++i){
    scanf("%d", (p+i));
  }
  for(int i = n-1; i >=0; --i){
    printf("%d", *(p+i));
  }
  printf("\nEnter more number, enter the number of numbers\n");
  scanf("%d", &more);
  p = (int *)realloc(p, (n+more)*sizeof(int));
  for(int i = n; i < n + more; ++i){
    scanf("%d", (p+i));
  }
  for(int i = 0; i < n + more; ++i){
    printf("%d", *(p+i));
  }
  
  free(p);

  return 0;
}
