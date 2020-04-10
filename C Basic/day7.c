#include <stdio.h>
#include <math.h>

int main(){
	// for (int i = 1; i <= 10; i++){
	// 	printf("%d %d\n", i, i*i);
	// }

	// for (int i = 1; i <= 10; i++){
	// 	for (int j = 1; j <= i; j++){
	// 		printf("#");
	// 	}
	// 	printf("\n");
	// }
	for (int x = 0; x <= 100; x++){
		if (x==0 || x==1) continue;
		else if (x==2 || x==3) printf("%d\n", x);
		else{
			int y = sqrt(x);
			for(int i = 2; i <= y; i++){
				if ( x % i == 0) break;
				else{
					if ( i == y ) printf("%d\n", x);
				}
			}
		}
	}
}