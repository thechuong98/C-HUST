#include <stdio.h>
#include <string.h>

void line_count_word(FILE *IN){
  char buff[100];
  size_t len;
  while(fgets(buff, 100, IN) != NULL){
    len = strlen(buff)-1;
    fprintf(IN, "%lu %s", len, buff);
  }
}

int main(){
  FILE *IN;
  char input[100];
  printf("Enter the file_name : ");
  scanf("%s", input);
  if((IN = fopen(input, "r+")) == NULL) printf("Cannot open the file\n");
  else line_count_word(IN);
}
