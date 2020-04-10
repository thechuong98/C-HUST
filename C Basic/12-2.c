#include<stdio.h>
#include<math.h>
int is_prime(int n){
    if (n==2 || n==3) return 1;
    if (n>3){
        double t = sqrt(n);
        for(int i = 2; i <= t ; i++){
            if (n%i == 0) return 0;
            else continue;
        }
        return 1;

    }
}

int main(){
    int number = 0;
    printf("Enter the number : ");
    scanf("%d", &number);
    for (int i = 2; i <= number; i++){
        if (is_prime(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}
