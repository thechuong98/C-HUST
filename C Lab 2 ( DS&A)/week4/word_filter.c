#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

void replaceToxicWord(FILE* f, char *toxicList[], int n, char alt){
	char currentWord[100];
	fscanf(f, "%s", currentWord);
	while(!feof(f)){
		for(int i = 0; i < n; ++i){
			if(strcasecmp(currentWord, toxicList[i]) == 0){
				fseek(f, -strlen(currentWord), SEEK_CUR);
				for(int j = 0;j < strlen(currentWord); ++j){
					fputc(alt, f);
				}
			}
		}
		fscanf(f, "%s", currentWord);
	}
}

int main(int argc,const char* argv[]){
	char *toxicList[] = {
		"bitch",
		"shit",
		"damn",
		"heck",
		"what"
	};
	int n = sizeof(toxicList)/sizeof(toxicList[0]);
	if (argc == 3){
		char alt = *argv[2];
		FILE *f = fopen(argv[1], "r+");
		if(f == NULL) printf("Cannot open the file!\n");
		else replaceToxicWord(f, toxicList, n, alt);
	}
	else printf("syntax error\n");
	return 0;
}
