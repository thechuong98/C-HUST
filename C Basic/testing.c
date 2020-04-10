#include <stdio.h>
void clean_stdin(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


int main(){
	char Name[50];
	char Description[500];
	double Rating;
	char Address[100];
	fgets(Name, 50, stdin);
	clean_stdin();
	printf("%s", Name);
}