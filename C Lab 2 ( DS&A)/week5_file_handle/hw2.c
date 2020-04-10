#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char model[20];
  char rom[10];
  float display;
  char price[10];
} phone;

int lineCounter(char *fn){
  FILE *f = fopen(fn, "r");
  if ( f == NULL){
    printf("Cannot open the file\n");
    return 0;
  }
  int numOfLines = 1;
  char c;
  while ((c = fgetc(f)) != EOF){
    if (c == '\n') numOfLines++;
  }
  fclose(f);
  return(numOfLines);
}

void txt2bin(char *fnIn, char *fnOut, phone phones[], int n){
  FILE *fi = fopen(fnIn, "r");
  FILE *fo = fopen(fnOut, "w+b");

  if(fi == NULL){
    printf("cannot open the file.\n");
    return;
  }
  for(int i = 0; i < n; ++i){
    fscanf(fi, "%s", phones[i].model);
    fscanf(fi, "%s", phones[i].rom);
    fscanf(fi, "%f", &phones[i].display);
    fscanf(fi, "%s", phones[i].price);
  }
  fwrite(phones, sizeof(phone), n, fo);
  fclose(fi);
  fclose(fo);
}

void readDat(char *fn, phone phones[], int n){
  FILE *f = fopen(fn, "rb");
  if(f == NULL){
    printf("cannot open the file.\n");
    return;
  }
  fread(phones, sizeof(phone), n, f);
  fclose(f);
}

void NokiaProducts(phone phones[], int n){
  int count = 0;
  char c;
  for(int i = 0; i < n; ++i){
    if(strstr(phones[i].model, "Nokia") != NULL){
      if(count >= 10){
	printf("Enter any key to see the next page!");
	count = 0;
	scanf("%c", &c);
      }
      else {
	printf("%s %s %.1f %s\n",
	       phones[i].model,
	       phones[i].rom,
	       phones[i].display,
	       phones[i].price);
	count++;
      }
    }
  }
}

void searchByModel(phone phones[], int n){
  char model[10];
  printf("What the model do you want to search : ");
  scanf("%s", model);
  for(int i = 0; i < n; ++i){
    if(strstr(phones[i].model, model) != NULL){
	printf("%s %s %.1f %s\n",
	       phones[i].model,
	       phones[i].rom,
	       phones[i].display,
	       phones[i].price);
      }
  }
    return;
}

int main(){
  int choice = 0;

  int n = lineCounter("phoneDB.txt");
  phone *phones = (phone *)malloc(n*sizeof(phone));
  
  while(choice != 5){
    printf("Choose an option : \n");
    printf("1. Convert txt to binary file \n");
    printf("2. Read data from .dat file \n");
    printf("3. Nokia products\n");
    printf("4. search by model\n");
    printf("Your option : ");
    scanf("%d", &choice);

    switch(choice){
    case 1: {
      txt2bin("phoneDB.txt", "phoneDB.dat", phones, n);
      break;
    }
    case 2: {
      readDat("phoneDB.dat", phones, n);
      break;
    }
    case 3: {
      NokiaProducts(phones, n);
      break;
    }
    case 4: {
      searchByModel(phones, n);
      break;
    }
    default: {
      printf("Please choose one of those options\n");
      break;
    }
    }
  }
}
