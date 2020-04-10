#include "queue_ll_2.c"


int main(int argc, const char **argv){
	if(argc == 2){
		int numOfDesk = atoi(argv[1]);
		Queue *Q[numOfDesk];
		for(int i = 0; i < numOfDesk; ++i){
			Q[i] = creatQueue();
		}

		int cur_hour, prev_hour, cur_minute, prev_minute, period;
		int customer_at_time = 0;
		int customer_all = 0; //this two lines for the last purpose
		int wait_time = 0;

		//MAIN
		printf("The Bank\n");
		printf("-----------------------\n");
		printf("number of Desk : %d\n", numOfDesk);
		do{
			printf("Enter the time: ");
			scanf("%d:%d", &cur_hour, &cur_minute);
			clear_buffer();
			printf("Number of customer : ");
			scanf("%d", &customer_at_time);
			clear_buffer();

			period = (cur_hour - prev_hour)*60 + (cur_minute - prev_minute);
			updateQueue(&Q[0], period); //update Queue after a new time entered;
			updateQueue(&Q[1], period); 
			for(int i = 0; i < customer_at_time; ++i){
				if((customer_all + i) % 2 == 0) {
					enQueue(&Q[0]); // 15 : serveTime;
					printf("The %dth customer goes to the first desk and wait : %d minute\n", i+1, getWaitTime(&Q[0])-15);
					wait_time += getWaitTime(&Q[0])-15;
				}
				else{
					enQueue(&Q[1]);
					printf("The %dth customer goes to the second desk and wait : %d minute\n", i+1, getWaitTime(&Q[1])-15);
					wait_time += getWaitTime(&Q[1])-15;
				}
			}

			prev_hour = cur_hour; //update
			prev_minute = cur_minute; //update
			customer_all += customer_at_time; //update
		}while(cur_hour);
		printf("Average : %d Customers, have to wait %d minute, and in average %.2lf minute\n", customer_all, wait_time, (float)wait_time/customer_all);
	}
}