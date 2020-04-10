#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
  char name[30];
  char tel[15];
  char email[30];
} user;

void writeData(char *fn, user users[], int n){
  FILE *f = fopen(fn, "w+b");
  fwrite(users, sizeof(user), n, f);
  fclose(f);
}

void readData(char *fn, user users[], int n){
  FILE *f = fopen(fn, "rb");
  if(f == NULL){
    printf("cannot open the file\n");
  }
  else{
    fread(users, sizeof(user), n, f);
  }
  fclose(f);
}

void modifyData(char *fn, int start, int n){
  FILE *f = fopen(fn, "r+b");
  if(f == NULL) printf("cannot open the file\n");
  else{
    user *users = (user *)malloc(n*sizeof(user));
    if (users == NULL)
      {
	printf("Memory allocated fail\n");
      }
    fseek(f, (start-1)*sizeof(user), SEEK_SET);
    fread(users, sizeof(user), n, f);
    for(int i = 0; i < n; ++i){
      printf("Person number %d:\n", i+1);
      printf("Name : %s\n", users[i].name);
      printf("Tel: : %s\n", users[i].tel);
      printf("Email : %s\n\n", users[i].email);
    }
  }
}

int main(){
  user users[] ={
    {
      "Chu The Chuong",
      "0981082834",
      "ABC"
    },
    {
      "Nguyen Duc Dung",
      "123456789",
      "CDE"
    },
    {
      "Tran Bich Ngoc",
      "345678912",
      "EFG"
    }
  };

  int n = sizeof(users)/sizeof(users[0]);
  writeData("phone.dat", users, n);
}
