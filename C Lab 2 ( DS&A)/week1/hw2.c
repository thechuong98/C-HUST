	#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char* creatSentence(char *articles[], char *nouns[], char *verbs[], char *prepositions[]){
	char* sentence = calloc((50), sizeof(char));;
	strcat(sentence, articles[rand()%5]);
	strcat(sentence, " ");
	strcat(sentence, nouns[rand()%5]);
	strcat(sentence, " ");
	strcat(sentence, verbs[rand()%5]);
	strcat(sentence, " ");
	strcat(sentence, prepositions[rand()%5]);
	strcat(sentence, " ");
	strcat(sentence, articles[rand()%5]);
	strcat(sentence, " ");
	strcat(sentence, nouns[rand()%5]);
	//Capitalize first letter
	sentence[0] = toupper(sentence[0]);
	strcat(sentence, ".");

  return sentence;
}

int main(){
	srand (time(NULL));
	char* articles[5] = {"the", "a", "one", "some", "any"};
	char* nouns[5] = {"boy", "girl", "dog", "town", "car"};
	char* verbs[5] = {"drove", "jumped", "ran", "walked", "skipped"};
	char* prepositions[5] = {"to", "from", "over", "under", "on"};
	for(int i = 0; i < 10; ++i){
		char *sentence = creatSentence(articles, nouns, verbs, prepositions);
		printf("%s\n", sentence);
	}
}