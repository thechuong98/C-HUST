#include<stdio.h>
#include<math.h>

typedef struct point{
  double x;
  double y;
} point_t;

typedef struct circle{
  point_t center;
  double radius;
} circle_t;

int is_in_Circle(point_t P, circle_t C){
  double distance = sqrt((P.x-C.center.x)*(P.x-C.center.x)+(P.y-C.center.y)*(P.y-C.center.y));
  if(distance <= C.radius) return 1;
  else return 0;
}

int main(){
  point_t P;
  printf("Enter point P(x,y) : ");
  scanf("%lf, %lf", &P.x, &P.y);
  circle_t C;
  printf("Enter center of the Cirlcle C(x2,y2) : ");
  scanf("%lf, %lf", &C.center.x, &C.center.y);
  printf("Enter the circle's radius : ");
  scanf("%lf", &C.radius);
  if(is_in_Circle(P, C)) printf("The point is covered by the circle\n");
  else printf("The point is out of the circle\n");
}
