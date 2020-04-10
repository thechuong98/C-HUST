#include<stdio.h>

void swap(int *a, int *b, int *c){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int *p = &x;
    int *q = &y;
    int *r = &z;
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z,p,q,r, *p, *q, *r);

    swap(&x, &y, &z);
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z,p,q,r, *p, *q, *r);

    swap(&p, &q, &r);
    printf("x = %d, y = %d, z = %d, p = %p, q = %p, r = %p, *p = %d, *q = %d, *r = %d\n", x, y, z,p,q,r, *p, *q, *r);

    printf("%p %p", p, q);
    return 0;
}
