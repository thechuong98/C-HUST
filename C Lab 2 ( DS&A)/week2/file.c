#include <stdio.h>

//fopen FILE *fptr; fopen("name", "mode"); remember to compare with NULL;
// "r+" = r+w(exist); "w+" = r+w (creat); "a+" creat or open to append;

enum {SUCCESS, FAIL};

int main(){
  FILE *fptr;
  char filename[] = "OK.txt";
  int reval = SUCCESS;

  if((fptr = fopen(filename, "r")) == NULL){
    printf("Cannot open the file");
    reval = FAIL;
  }
  else {
    printf("The value of fptr : 0x%p\n", fptr);
    printf("Ready to close the file.\n");
    fclose(fptr);
  }

  return reval;
}
