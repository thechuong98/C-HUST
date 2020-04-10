#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

typedef struct team{
  char id[10];
  int score;
} team;

typedef struct match{
  team *team1;
  team *team2;
  int goal1;
  int goal2;
} match;


void iteration_team(void *dataField){
  team *a = (team*) dataField;
  printf("%s %d\n",a->id, a->score);
}

int comparator_id(void *a, void *b){
  team *team1 = (team *)a;
  team *team2 = (team *)b;
  if(strcmp(team1->id, team2->id) < 0) return -1;
  else if(strcmp(team1->id, team2->id) > 0) return 1;
  else return 0;
}

int comparator_score(void *a, void *b){
  team *team1 = (team *)a;
  team *team2 = (team *)b;
  if(team1->score > team2->score) return 1;
  else if(team1->score < team2->score) return -1;
  else return 0;
}

team *getTeamFromId(treeNode *root, char *id){
  if(root == NULL) return NULL;
  if(strcmp(((team *)(root->data))->id, id) == 0) return root->data;
  if(strcmp(((team *)(root->data))->id, id) < 0) return getTeamFromId(root->right, id);
  if(strcmp(((team *)(root->data))->id, id) > 0) return getTeamFromId(root->left, id);
}



void file_to_tree(char *fn, tree *teams){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    match *match = malloc(sizeof(match));
    team *team1_tmp= malloc(sizeof(team));
    team *team2_tmp = malloc(sizeof(team));
    sscanf(buff, "%s\t%s\t%d\t%d", team1_tmp->id, team2_tmp->id, &match->goal1, &match->goal2);

    match->team1 = getTeamFromId(teams->root, team1_tmp->id);
    if(match->team1 == NULL){
      tree_insert_bst(&(teams->root), team1_tmp, teams->elementSize, comparator_id);
      match->team1 = getTeamFromId(teams->root, team1_tmp->id);
    }
    match->team2 = getTeamFromId(teams->root, team2_tmp->id);
    if(match->team2 == NULL){
      tree_insert_bst(&(teams->root), team2_tmp, teams->elementSize, comparator_id);
      match->team2 = getTeamFromId(teams->root, team2_tmp->id);
    }

    if(match->goal1 > match->goal2) match->team1->score += 3;
    else if(match->goal2 > match->goal1) match->team2->score += 3;
    else{
      match->team1->score += 1;
      match->team2->score += 1;
    }
  }
}

void printScore(tree *teams, team *team_tmp){
  treeNode *search = tree_search(teams->root, team_tmp, comparator_id);
  if(search != NULL) {
    team *search_data = (team *)(search->data);
    printf("Diem cua doi %s la %d\n", search_data->id, search_data->score);
  }
  else printf("Khong thay doi bong nay\n");
}

treeNode *minScore(treeNode *root){
  if(root == NULL) return NULL;
  treeNode *min;
  treeNode *minLeft = minScore(root->left);
  treeNode *minRight = minScore(root->right);
  if(minLeft != NULL && minRight != NULL){
    if(((team *)(minLeft->data))->score > ((team *)(minRight->data))->score) min = minRight;
    else if(((team *)(minLeft->data))->score > ((team *)(minRight->data))->score) min = minLeft;
    else min = minRight;
  }
  else if(minLeft != NULL && minRight == NULL) min = minLeft;
  else if(minRight != NULL && minLeft == NULL) min = minRight;
  else min = root;

  if(((team *)(root->data))->score > ((team *)(min->data))->score) return min;
  if(((team *)(root->data))->score < ((team *)(min->data))->score) return root;
  return root;
}

void XuongHang(tree *teams, int num){
  for(int i = 0; i < num; ++i){
    tree_delete_bst(&(teams->root), tree_min(teams->root, comparator_score)->data, teams->elementSize, comparator_id);
  }
}

void export(FILE *stream, treeNode *root){
  if(root == NULL) return;
  export(stream, root->left);
  team *tmp = (team *)(root->data);
  fprintf(stream, "%s\t%d\n", tmp->id, tmp->score);
  export(stream, root->right);
}

int main(){
  tree teams;
  tree_new(&teams, sizeof(team));
  int option;
  do{
    printf("\n---------------------\n");
    printf("UEFA Championship\n");
    printf("1.Creat Tree\n");
    printf("2.Print result\n");
    printf("3.Search\n");
    printf("4.Xuong Hang\n");
    printf("5.Export\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      file_to_tree("de2013.txt", &teams);
      break;
    }
    case 2:{
      LDR(teams.root, iteration_team);
      break;
    }
    case 3:{
      team *team = malloc(sizeof(team));
      printf("Enter the id of team :");
      scanf("%s", team->id);
      printScore(&teams, team);
      break;
    }
    case 4:{
      XuongHang(&teams, 2);
      break;
    }
    case 5:{
      FILE *stream = fopen("ketqua2013.txt", "w+");
      export(stream, teams.root);
      fclose(stream);
      break;
    }
    case 6:{
      printf("Bye bye\n");
      break;
    }
    default:{
      printf("Enter one of those options\n");
      break;
    }
    }
  }while(option != 6);
}
