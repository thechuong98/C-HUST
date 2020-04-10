#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void my_strcat(char *s1, char *s2){
  size_t size_s1 = strlen(s1);
  size_t size_s2 = strlen(s2);
  s1 = (char *)realloc(s1, (size_s1 + size_s2)*sizeof(char));
  strcpy(s1+size_s1, s2);
}

int main(){
  char c;
  char *s1 = (char *)malloc(MAX);
  char *s2 = (char *)malloc(MAX);
  scanf("%[^\n]s", s1);
  while((c = getc(stdin)) != '\n');
  scanf("%[^\n]s", s2);
  my_strcat(s1, s2);
  printf("%s", s1);
}
