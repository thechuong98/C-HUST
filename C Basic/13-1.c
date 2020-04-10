#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
	char id[9];
	char name[31];
	float grade;
	char level;
} student;

void printStudent(student s){
	printf("ID | Name     | Grade | Level\n");
	printf("%s | %s     | %1.1f | %c\n", s.id, s.name, s.grade, s.level);
}

int main(){
	int i, n;
	student std_list[MAX], tmp;
}