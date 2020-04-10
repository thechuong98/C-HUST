#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

typedef struct team{
  int id;
  char name[30];
  int score;
  int goal;
  int lose;
} team;

typedef struct match{
  team *team1;
  team *team2;
  int goal1;
  int goal2;
} match;

void getData(char *fn, list *list){
  FILE *fin = fopen(fn, "r");
  int num_of_team = 0;
  fscanf(fin, "%d\n", &num_of_team);
  for(int i = 0; i < num_of_team; ++i){
    //malloc de xin cap phat, neu khong se cap phat lien tuc tai 1 o
    team *A = malloc(sizeof(team));
    fscanf(fin, "%d\t%[^\n]s", &A->id, A->name);
    list_append(list, A);
  }
  fclose(fin);
}

void iteration_team(void *dataField){
  team *a = (team*) dataField;
  printf("%d %s %d %d %d\n",a->id, a->name, a->score, a->goal, a->lose);
}

team *getTeamFromId(list *teams, int id){
  listNode *head = teams->head;
  while(((team *)(head->data))->id != id) head = head->next;
  return head->data;
}

void schedule(char *fn, list *teams, queue *Q){
  FILE *fin = fopen(fn, "r");
  char buffer[100];
  int num_of_team = 0;
  fscanf(fin, "%d\n", &num_of_team);
  for(int i = 0; i < num_of_team; ++i){
    fgets(buffer, 100, fin); //get a line;
  }
  for(int j = 0; j < num_of_team-1; ++j){
    match *match1 = malloc(sizeof(match));
    match *match2 = malloc(sizeof(match));
    int team_1, team_2, team_3, team_4;
    fgets(buffer, 100, fin);
    puts(buffer);
    fscanf(fin, "%d\t%d\n", &team_1, &team_2);
    match1->team1 = getTeamFromId(teams, team_1); 
    match1->team2 = getTeamFromId(teams, team_2); 
    enQueue(Q, match1);
    printf("%s-%s\n", match1->team1->name, match1->team2->name);
    fscanf(fin, "%d\t%d\n", &team_3, &team_4);
    match2->team1 = getTeamFromId(teams, team_3); 
    match2->team2 = getTeamFromId(teams, team_4); 
    enQueue(Q, match2);
    printf("%s-%s\n", match2->team1->name, match2->team2->name);
  }
  fclose(fin);
}

void update_result(queue *Q){
  for(int i = 0; i < queue_size(Q)/2; ++i){
    if(!isEmptyQueue(Q)){
      match *deMatch = deQueue(Q);
      printf("Set the resutl of match between %s - %s\n", deMatch->team1->name, deMatch->team2->name);
      scanf("%d-%d", &deMatch->goal1, &deMatch->goal2);
      if(deMatch->goal1 > deMatch->goal2){
	deMatch->team1->score += 3;
      }
      else if(deMatch->goal1 < deMatch->goal2){
	deMatch->team2->score += 3;
      }
      else {
	deMatch->team1->score += 1;
	deMatch->team2->score += 1;
      }
      deMatch->team1->goal += deMatch->goal1;
      deMatch->team2->goal += deMatch->goal2;
      deMatch->team1->lose += deMatch->goal2;
      deMatch->team2->lose += deMatch->goal1;
    }
  }
}

int getMinScore(list *teams){
  listNode *head = teams->head;
  int min_score = ((team *)(head->data))->score;
  while(head != NULL){
    if(((team *)(head->data))->score < min_score){
      min_score = ((team *)(head->data))->score;
    }
    head = head->next;
  }
  return min_score;
}

listNode *delete_min_score(listNode *head, int min_score){
  if(head == NULL) return NULL;
  if(((team *)(head->data))->score == min_score){
    return delete_min_score(head->next, min_score);
  }
  head->next = delete_min_score(head->next, min_score);
  return head;
}


int main(){
  list teams;
  list_new(&teams, sizeof(team));
  queue Q;
  queue_new(&Q, sizeof(match));
  
  int option;
  do{
    printf("\n---------------------\n");
    printf("UEFA Championship\n");
    printf("1.Print teams\n");
    printf("2.Schedule\n");
    printf("3.Updated Result\n");
    printf("4.Analysis\n");
    printf("5.Quit\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      getData("bongda.txt", &teams);
      list_for_each(&teams, iteration_team);
      break;
    }
    case 2:{
      schedule("bongda.txt", &teams, &Q);
      break;
    }
    case 3:{
      update_result(&Q);
      list_for_each(&teams, iteration_team);
      break;
    }
    case 4:{
      int min_score = getMinScore(&teams);
      teams.head = delete_min_score(teams.head,  min_score);
      list_for_each(&teams, iteration_team);
      break;
    }
    case 5:
      printf("Bye bye\n");
      break;
    }
  } while(option != 5);
}
