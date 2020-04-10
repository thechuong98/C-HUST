#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 30

void printOut(char array[][len], const char* key, int n){
	for(int i = 0; i < n; ++i){
		if(strstr(array[i], key) != NULL) printf("%s", array[i]);
	}
}


void sentinelSearch(char array[][len], const char *key, int n){
	char last[len];
	strcpy(last, array[n-1]);
	printf("%s", last);
	strcpy(array[n-1], key);
	int i = 0;
	while(strstr(array[i], key) == NULL){
		i++;
	}
	strcpy(array[n-1], last);
	if(i < n-1 || strstr(array[i], key) != NULL){
		printf("%s", array[i]);
	}
}

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

void txtToArray(char *fin, char array[][len], unsigned int n){
	FILE *streamIn = fopen(fin, "r");
	char buffer[len];
	if(fin == NULL) printf("cannot open the file.\n");
	int i = 0;
	while(fgets(buffer, sizeof(buffer), streamIn)){
		strcpy(array[i], buffer);
		i++;
	}
	fclose(streamIn);
}

int main(int argc, const char *argv[]){
	if(argc == 3){
		if(strcmp(argv[1], "look") != 0){
			printf("format : %% look characterstring");
			return 0;
		}
		unsigned int n = lineCounter("words.txt");
		char array[n][len];
		txtToArray("words.txt", array, n);
		sentinelSearch(array, argv[2], n);
	}
}