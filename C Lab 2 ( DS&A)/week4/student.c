#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_LEN 30
#define PHONENUM 30

typedef struct student{
	int stt_;
	char id_[15];
	char name_[NAME_LEN];
	char phoneNum_[PHONENUM];
	double grade_;
} student;

int countLine(char *input){
	int count = 0;
	int c;
	FILE *f = fopen(input, "r");
	while((c = fgetc(f)) != EOF){
		if(c == '\n') count++;
	}
	return count;
}

void readData(char *input, student *Students, int numofStudents){
	FILE *f = fopen(input, "r");
	if(f == NULL) printf("Cannot open the file\n");
	else{
		while(!feof(f)){
			for(int i = 0; i < numofStudents; ++i){
				fscanf(f, "%d", &Students[i].stt_);
				fscanf(f, "%s", Students[i].id_);
				fscanf(f, "%s", Students[i].name_);
				fscanf(f, "%s", Students[i].phoneNum_);
			}
		}
	}
}


void markInput(student *Students, int n){
	for(int i = 0; i < n; ++i){
		printf("Mark for student %s\n", Students[i].name_);
		scanf("%lf", &Students[i].grade_);
	}
}

void printData(char *output, student *Students, int n){
	FILE *f = fopen(output, "w+");
	if (f == NULL) printf("Cannot open the file");
	else{
		for(int i = 0; i < n; ++i){
			fprintf(f, "%-4d%-11s%-30s%-30s%.2lf\n", Students[i].stt_,
				Students[i].id_, Students[i].name_, Students[i].phoneNum_,
				Students[i].grade_);
		}
	}
}

int main(){
	int numofStudents = countLine("student_list.txt");
	student *Students = (student *)calloc(numofStudents, sizeof(student));
	readData("student_list.txt", Students, numofStudents);
	markInput(Students, numofStudents);
	printData("grade.txt", Students, numofStudents);
}
