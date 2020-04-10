//-----------------hw101.c--------------------
#include <stdio.h>

int main(){
	int a,b,c;
	printf("a = ");
	scanf ("%d",&a);
	
	printf("b = ");
	scanf ("%d",&b);
	
	printf("c = ");
	scanf ("%d",&c);
	
	int *ptr = &a;
	printf("a = %d\n", *ptr);
	ptr = &b;
	printf("b = %d\n", *ptr);
	ptr = &c;
	printf("c = %d\n", *ptr);
	return 0;
}

// --------------------hw102.c----------------
#include<stdio.h>

int main(){
	int a[7] = {13, -355, 235, 47, 67, 943, 1222};
	
	for (int i = 0; i < 5; ++i){
    	printf("%p\n", &a[i]);
	}

	return 0;
}

//--------------------hw103.c------------------

#include <stdio.h>

int main(){
	float a,b,c;
	printf("Enter 3 float numbers: \n");
	scanf("%f %f %f", &a, &b, &c);
	float *ptr = &a;
	*ptr += 100;
	printf("a = : %.2f", a);
	ptr = &b;
	*ptr += 100;
	printf("\nb = : %.2f", b);
	ptr = &c;
	*ptr += 100;
	printf("\nc = : %.2f", c);
return 0;

}

//---------------------hw104.c-------------------

#include<stdio.h>

void rotate(double *a, double *b, double *c){
    double temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main(){
    double a,b,c;
    printf("Enter 3 numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    rotate(&a, &b, &c);
    printf("After swap: a = %lf, b = %lf, c = %lf", a, b, c);
    return 0;

}
//--------------------hw105.c-----------------------
#include<stdio.h>

void swap(int *a, int *b, int *c){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main(){
    int x = 1;
    int y = 2;
    int z = 3;
    int *p = &x;
    int *q = &y;
    int *r = &z;
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z, p, q, r, *p, *q, *r);

    swap(&x, &y, &z);
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z, p, q, r, *p, *q, *r);

    swap(&&p, &&q,&&r);
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z, p, q, r, *p, *q, *r);

    printf("%p %p", p, q);
    return 0;
}
//-------------------------------------------------