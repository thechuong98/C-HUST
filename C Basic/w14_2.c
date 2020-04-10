#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    char id[6];
    char name[31];
    float grade;
    char level;
} student;

char getLevel(float grade)
{
    if (grade >= 9 && grade <= 10)
        return 'A';
    else if (grade < 9 && grade >= 8)
        return 'B';
    else if (grade < 8 && grade >= 6.5)
        return 'C';
    else
        return 'D';
}

student inputStudent(int order)
{
    student s;
    printf("Enter the information of student %d : \n", order);
    printf("Student ID : ");
    scanf("%s", s.id);
    printf("name : ");
    scanf("%s", s.name);
    printf("Grade : ");
    scanf("%f", &s.grade);
    printf("\n\n");
    s.level = getLevel(s.grade);

    return s;
}


int cmpStudent(student *a, student *b)
{
    if (a->grade > b->grade)
        return -1;
    else if (a->grade < b->grade)
        return 1;
    else
        return 0;
}

int main()
{
    student studentInfo[100];
    float studentGrade[100];
    int n;
    int i;

    printf("Enter the number of student : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        studentInfo[i] = inputStudent(i + 1);


    qsort(studentInfo, n, sizeof(student), (int(*)(const void*,const void*))cmpStudent);

    for (i = 0; i < n; i++) {
        printf("%s\t%.1f\t%c\n", studentInfo[i].name, studentInfo[i].grade, studentInfo[i].level);
    }
    return 0;
}
