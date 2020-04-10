// Homework 14.1//
#include <stdio.h>
typedef struct Date{
	int d;
	int m;
	int y;
}Date;
int isLeapyear(int y){
	if(y%4==0 && y%100!=0)
			return 1;		
	else if(y%400==0) return 1;
	else return 0;
}
Date dateinput(){
	int dayofmonth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},
							{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	Date date;
	int dd,mm,yy;
	do{
		printf("Enter the date in the format dd/mm/yy: ");
		scanf("%d/%d/%d", &dd, &mm, &yy);
		date.d = dd;
		date.m = mm;
		date.y = yy;	
	}while(dd < 0 || dd > dayofmonth[isLeapyear(yy)][mm]|| mm < 0|| mm > 13);
	return date;
}
int datecmp(const Date d1,const Date d2){
	if(d1.y<d2.y || 
		(d1.y==d2.y && d1.m<d2.m) || 
		(d1.y==d2.y && d1.m == d2.y && (d1.d < d2.d))) return -1;
	else if (d1.y == d2.y && d1.m == d2.m && d1.d == d2.d) return 0;
	else return 1;
}
int main(){
	Date d1 = dateinput();
	Date d2 = dateinput();
	if(datecmp(d1,d2)==-1) printf("%d/%d/%d is before %d/%d/%d\n", d1.d, d1.m, d1.y, d2.d, d2.m, d2.y);
	else if(datecmp(d1,d2)) printf("%d/%d/%d is after %d/%d/%d\n", d1.d, d1.m, d1.y, d2.d, d2.m, d2.y);
	else printf("The two date is identical!!\n");
	return 0;
}


//Homework 14.2//
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char id[6];
    char name[31];
    float grade;
    char level;
} student;

char getLevel(float grade){
    if (grade >= 9 && grade <= 10)
        return 'A';
    else if (grade < 9 && grade >= 8)
        return 'B';
    else if (grade < 8 && grade >= 6.5)
        return 'C';
    else
        return 'D';
}

student inputStudent(int order){
    student s;
    printf("Enter the information of student %d : \n", order);
    printf("Student ID : ");
    scanf("%s", s.id);
    printf("Name : ");
    scanf("%s", s.name);
    printf("Grade : ");
    scanf("%f", &s.grade);
    printf("\n\n");
    s.level = getLevel(s.grade);

    return s;
}


int cmpStudent(student *a, student *b){
    if (a->grade > b->grade)
        return -1;
    else if (a->grade < b->grade)
        return 1;
    else
        return 0;
}

int main(){
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
        printf("%s\t%s\t%.1f\t%c\n",studentInfo[i].id, studentInfo[i].name, studentInfo[i].grade, studentInfo[i].level);
    }
    return 0;
}


// Homework 14.3//
#include <stdio.h>

typedef struct fraction
{
	float _nume;
	float _deno;

} fraction;

int fracInput(fraction fractions[]){
	float nume, deno;
	printf("Input fractions (| to stop) :\n");
	int i = 0;
	int count = 0;
	while(scanf("%f/%f", &nume, &deno)){
		fractions[i]._nume = nume;
		fractions[i]._deno = deno;
		i++;
		count++;
	}
	return count;
} 


void printFrac(fraction a){
	printf("%.1f/%.1f\n", a._nume, a._deno);
}

void printFracs(fraction *fractions, int n){
	printf("The array of fractions :\n");
	for(int i = 0; i < n; ++i) printFrac(fractions[i]);
}

void swap(fraction *a, fraction *b){
	fraction temp;
	temp._nume = a->_nume;
	temp._deno = a->_deno;
	a->_nume = b->_nume;
	a->_deno = b->_deno;
	b->_nume = temp._nume;
	b->_deno = temp._deno;
}

void inverseArray(fraction *fractions, int n){
	int i = 0;
	int j = n-1;
	while(i < j){
		swap(&fractions[i], &fractions[j]);
		i++;
		j--;
	}
}


int fracCmp(fraction a, fraction b){
	float value1 = a._nume/a._deno;
	float value2 = b._nume/b._deno;
	if(value1 < value2) return -1;
	else if (value1 == value2) return 0;
	else return 1;
}

int GCD(int n1, int n2)
{
    if (n2 != 0)
       return GCD(n2, n1%n2);
    else 
       return n1;
}

float fracValue(fraction a){
	return a._nume/a._deno;
}

fraction Multi(fraction a, fraction b){
	fraction c;
	c._nume = a._nume*b._nume;
	c._deno = a._deno*b._deno;
	return c;
}

fraction Add(fraction a, fraction b){
	fraction c;
	c._nume = a._nume*b._deno+a._deno*b._nume;
	c._deno = a._deno*b._deno;
	return c;
}

fraction LowestTerm(fraction c){
	fraction d;
	d._nume /= GCD(c._nume, c._deno);
	d._deno /= GCD(c._nume, c._deno);
	return d;
}

int main(){
	fraction fractions[100];
	int numofElement = fracInput(fractions); //number of element
	printFracs(fractions, numofElement);
	inverseArray(fractions, numofElement);
	printFracs(fractions, numofElement);
	//Compare
	printf("Now I will compare 2 first elements in the array after inverse\n");
	if(fracCmp(fractions[0], fractions[1])) printf("fractions[0]>fractions[1]\n");
	else if(fracCmp(fractions[1], fractions[0])) printf("fractions[1]>fractions[0]\n");
	else printf("fractions[0]=fractions[1]\n");
	//Multiply 
	printf("Now I will multiply 2 first elements in the array after inverse\n");
	printFrac(LowestTerm(Multi(fractions[0], fractions[1])));
	//Add
	printf("And add them\n");
	printFrac(LowestTerm(Add(fractions[0], fractions[1])));
	return 0;
}

