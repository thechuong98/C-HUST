/*
void *realloc(void *ptr, size_t size)
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char *str;
  /*Init memory allocation*/
  str = (char *)malloc(15*sizeof(char));
  strcpy(str, "chuthechuong");
  printf("String = %s, Adress = %p\n", str, str);

  /*Reallocate memory*/
  str = (char *)realloc(str,25*sizeof(char)); //it move the whole array to a new address which have enough memory blocks
  strcat(str, ".com");
  printf("String = %s, Adress = %p\n", str, str);

  free(str);
  return 0;
