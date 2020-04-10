#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int order;
  char id[10];
  char phone[15];
  char name[30];
  double grade;
} student;

int lineCounter(char *fn){
  FILE *fp = fopen(fn, "r");
  if(fp == NULL){
    printf("cannot open the file.\n");
    return 0;
  }
  char c;
  int numOfLine = 1;
  while(!feof(fp)){
    c = fgetc(fp);
    if(c == '\n'){
      numOfLine++;
    }
  }
  fclose(fp);
  return numOfLine;
}

void getDatafromText(char *fn, student students[], int n){
  FILE *fp = fopen(fn, "r");
  if(fp == NULL){
    printf("cannot open the file.\n");
    return;
  }
  for(int i = 0; i < n; ++i){
    fscanf(fp, "%d", &students[i].order);
    fscanf(fp, "%s", students[i].id);
    fscanf(fp, "%s", students[i].phone);
    fseek(fp, 3, SEEK_CUR);
    fscanf(fp, "%[^\t]s", students[i].name);
    fscanf(fp, "%lf",&students[i].grade);
  }
  fclose(fp);
}

void exportData(char *fn, student arr[], int n) {
  
  FILE *fp = fopen(fn, "wb");
  if (fp == NULL) {
    printf("Can not open file %s\n", fn);
    return;
  }
  
  fwrite(arr, sizeof(student), n, fp);
  
  fclose(fp);
  
  return;
}

void readDataFromFileDat(char *fn, student students[], int n) {
  
  FILE *fp = fopen(fn, "rb");
  if (fp == NULL) {
    printf("Can not open file %s\n", fn);
    return;
  }
  
  fread(students, sizeof(student), n, fp);
  
  int i; /* counter */
  for (i = 0; i < n; i++) {
    printf("Student   : %d \n", i + 1);
    printf("Full name : %s\n", students[i].name);
    printf("Id        : %s\n", students[i].id);
    printf("Phone     : %s\n", students[i].phone);
    printf("Grade     : %lf\n", students[i].grade);
    printf("------------------------------------\n\n");
  }
  fclose(fp);
  return;
}

void searchAndUpdate(char *fn, student students[], int n) {
  
  FILE *fp = fopen(fn, "rb");
  if (fp == NULL) {
    printf("Can not open file %s\n", fn);
    return;
  }
  
  fread(students, sizeof(student), n, fp);
  
  char id[10];
  printf("\nId need to search and update : ");
  scanf(" %s", id);
  
  int i; /* counter */
  for (i = 0; i < n; i++) {
    if (strcmp(students[i].id, id) == 0) {
      printf("New grade :  ");
      scanf(" %lf", &students[i].grade);
    }
  }
  
  fclose(fp);
  
  fp = fopen(fn, "wb");
  fwrite(students, sizeof(student), n, fp);
  fclose(fp);
  return;
}

int main() {
  
  int n; /* number of line in file */
  int op;
  student *arr;
  
  n = lineCounter("grade_table.txt");
  /* allocate memory for student array */
  arr = (student *)malloc(n * sizeof(student));
  
  printf("There are 3 options : \n");
  printf("1: Text2Dat \n");
  printf("2: Display .dat file \n");
  printf("3. search and update \n");
  printf("Your option : ");
  scanf("%d", &op);
  
  switch (op) {
  case 1: {
    getDatafromText("grade_table.txt", arr, n);
    exportData("grade_table.dat", arr, n);
    break;
  }
  case 2: {
    readDataFromFileDat("grade_table.dat", arr, n);
    break;
  }
  case 3: {
    searchAndUpdate("grade_table.dat", arr, n);
    readDataFromFileDat("grade_table.dat", arr, n);
    break;
  }
  }
  
  
  
  return 0;
}
