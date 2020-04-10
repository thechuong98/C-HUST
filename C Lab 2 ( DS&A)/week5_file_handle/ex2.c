#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct phoneAddress{
  char name[20];
  char tel[11];
  char email[25];
} phoneAddress;

void InputData(phoneAddress *Data){
  printf("Input name : ");
  scanf("%s", Data->name);
  printf("Input telephone number : ");
  scanf("%s", Data->tel);
  printf("Input email : ");
  scanf("%s", Data->email);
}

void ScanArrToFile(FILE *streamOut, phoneAddress *phonebook, int num){
  streamOut = fopen("phonebook.txt", "w+b");
  int irc = fwrite(phonebook, sizeof(phoneAddress), num, streamOut);
  fclose(streamOut);
}

void ScanFiletoArr(FILE *streamIn, phoneAddress *phonebook, int num){
  streamIn = fopen("phonebook.txt", "rb");
  if(streamIn == NULL) printf("Cannot open the file \n");
  int irc = fread(phonebook, sizeof(phoneAddress), num, streamIn);
  fclose(streamIn);
}

void AdjustFile(FILE *streamIO, phoneAddress *phonebook, int from, int to){
  streamIO = fopen("phonebook.txt", "w+b");
  if(streamIO == NULL) printf("Cannot open the file");
  
}

int main(){
  phoneAddress *phonebook = (phoneAddress*)calloc(100, sizeof(phoneAddress));
  for(int i = 0; i < 10; ++i){
    printf("Adding data for person %d", i+1);
    InputData(&phonebook[i]);
  }
  size_t num = (sizeof(phonebook)/sizeof(phoneAddress));

  
}
