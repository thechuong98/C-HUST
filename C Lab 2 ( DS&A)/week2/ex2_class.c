#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void replace_char(char *str, char c1, char c2);

int main(){
  char str[50] = "Chu The Chuong";
  char c1 = 'C';
  char c2 = 'u';
  replace_char(str, c1, c2);
  printf("%s", str);
}

void replace_char(char *str, char c1, char c2){
  for(int i = 0; i < strlen(str) - 1; ++i){
    if(*(str+i) == c1){
      *(str+i) = c2;
    }
  }
}
