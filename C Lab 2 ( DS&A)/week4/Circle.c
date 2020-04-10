#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include <stdio_ext.h> // __fpurge(stdin);

typedef struct point{
  double x;
  double y; 
} point;

typedef struct circle{
  point center;
  double radius;
} circle;

double randNumber(int range){

	return rand() % range;
}

double distance(point P1, point P2){
	return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
}

int isIntersect(circle C1, circle C2){
	if((distance(C1.center, C2.center) < (C1.radius + C2.radius)) && (distance(C1.center, C2.center) < fabs(C1.radius - C2.radius))) return 1;
	else return 0;
}

void printCircles(circle Circles[], int numOfCircle){
	for(int i = 0; i < numOfCircle; ++i){
		printf("circle number %d: Center : (%.2f, %.2f), radius : %.2f\n", i+1, Circles[i].center.x, Circles[i].center.y, Circles[i].radius);
	}
}

void printMostIntersectionInfo(circle *Circles, int interSectcounter[], int num0fCircle){
	int most = interSectcounter[0];
	int most_index = 0;
	for(int i = 0; i < num0fCircle; ++i){
		if(most < interSectcounter[i]){
			most = interSectcounter[i];
			most_index = i;
		} 
	}
	if(most == 0) printf("No circle is in intersection\n");
	else{
		printf("The circle that intersection with the most circles is : \n");
		printf("Circle number %d, center (%.2f, %.2f), radius : %.2f\n", most_index+1, Circles[most_index].center.x, Circles[most_index].center.y, Circles[most_index].radius);
		for (int i = 0; i < num0fCircle; ++i){
			if(i == most_index) continue;
			if(isIntersect(Circles[most_index], Circles[i])){
				printf("Intersection with circle number %d, center : (%.2f, %.2f), radius: %.2f\n", i+1, Circles[i].center.x, Circles[i].center.y, Circles[i].radius);
			}
		}
	}
}


int main(){
	srand(time(NULL));
	int numOfCircle = 0;
	circle *Circles;
	printf("How many circles do you want ? : ");
	scanf("%d", &numOfCircle);
	Circles = (circle *)calloc(numOfCircle, sizeof(circle));
	int choice;
	printf("Choose option : \n");
	printf("1.Manual Input\n");
	printf("2.Random Input\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			for(int i = 0; i < numOfCircle; ++i){
				printf("circle number %d\n", i + 1);
				printf("Radius : ");
				scanf("%lf", &(Circles[i].radius));
				printf("Center(x,y) : ");
				scanf("%lf, %lf", &(Circles[i].center.x), &(Circles[i].center.y));
				
			}
			break;
		case 2:
			for(int i = 0; i < numOfCircle; ++i){
				Circles[i].center.x = (double)randNumber(10);
				Circles[i].center.y = (double)randNumber(10);
				Circles[i].radius = (double)randNumber(10);
			}
			break;
	}
	printCircles(Circles, numOfCircle);
	int *interSectcounter = (int *)calloc(numOfCircle, sizeof(int));
	for(int i = 0; i < numOfCircle;++i){
		for(int j = i + 1; j < numOfCircle; ++j){
			if(isIntersect(Circles[i], Circles[j])){
				interSectcounter[i] += 1;
				interSectcounter[j] += 1;
			}
		}
	} 
	
	printMostIntersectionInfo(Circles, interSectcounter, numOfCircle);
}
