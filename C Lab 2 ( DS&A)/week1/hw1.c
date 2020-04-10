#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <strings.h>


void getName(char A[][100],int n){
  for(int i = 0; i < n; ++i){
    printf("what is the name of the %d student : ", i+1);
    __fpurge(stdin);
    fgets(A[i], 100, stdin);
    A[i][strlen(A[i])-1] = '\0';
  }
}

char getLastName(char Name[],char LastName[][30],int index){
  // for(int i = strlen(Name) - 1;i >=0; i--){
  //   if (Name[i] != ' '){
  //     LastName[index][strlen(Name) - 1 - i] = Name[i];
  //   }
  //   else break;
  // }
  // printf("%s\n", LastName[index]);
  // LastName[index][strlen(LastName[index]) - 1] = '\0';

  // for(int j = 0 ; j < strlen(LastName[index])/2; ++j){
  //     char temp;
  //     temp = LastName[index][j];
  //     LastName[index][j] = LastName[index][strlen(LastName[index]) - j - 1];
  //     LastName[index][strlen(LastName[index]) - j - 1] = temp;
  // } 
  // printf("%s\n", LastName[index]);
    char *p = strrchr(Name, ' ');
    if (p && *(p + 1)) strcpy(LastName[index], p+1);
  }

void getLastNameArray(char A[][100], char B[][30], int n){
  for(int i = 0; i < n; ++i) {
    getLastName(A[i], B, i);
  }
}

void swap(char str1[100], char str2[100])
{
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void sortByLastName(char name[][100], char LastName[][30], int n){
  int i, j, min_index;
  for(int i = 0; i < n - 1; ++i){
    min_index = i;
    for(int j = i + 1; j < n; ++j){
      if(strcasecmp(LastName[j], LastName[min_index]) < 0){
        min_index = j;
      }
    }
    swap(LastName[i], LastName[min_index]);
    swap(name[i], name[min_index]); 

  }
}

void FindMax(char LastName[][30], int n){
  int max = 0;
  char max_name_index;
  for(int i = 0; i < n-1; ++i){
    int count = 1;
    for(int j = i+1; j < n; ++j){
      if(strcasecmp(LastName[i], LastName[j]) == 0) count++;
    }
    if (count > max){
      max = count;
      max_name_index = i;
    }
  }
  printf("%s : %d\n", LastName[max_name_index], max);
}


int main(){
  int numofS = 0;
  printf("How many number of students in your class : ");
  scanf("%d", &numofS);
  char name[numofS][100];
  char LastName[numofS][30];
  getName(name, numofS);
  getLastNameArray(name, LastName, numofS);
  sortByLastName(name, LastName, numofS);
  for(int i = 0; i < numofS; ++i){
    printf("%s\n", name[i]);
  }
  FindMax(LastName, numofS);

}