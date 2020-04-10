#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

typedef struct student{
  char username[30];
  char password[30];
  double score;
} student;

void clear_buffer(){
    int ch;
    while ((ch=getchar()) !='\n' && ch!=EOF);
}

void iterator_student(void *data){
  student *a = (student *)data;
  if(strcmp(a->username ,"Admin") == 0) return;
  printf("%s %s\n", a->username, a->password);
}

int checkUser(char *str){
  for(int i = 0; i < strlen(str); ++i){
    if(str[i] == ' ') return 0;
  }
  return 1;
}

int checkPass(char *str){
  if (strlen(str) < 6) return 0;
  for(int i = 0; i < strlen(str); ++i){
    if(str[i] == ' ') return 0;
  }
  return 1;
}

int cmp_username(void *a, void *b){
  student *s1 = (student *)a;
  student *s2 = (student *)b;
  if(strcmp(s1->username, s2->username) < 0) return -1;
  else if(strcmp(s1->username, s2->username) > 0) return 1;
  else if(strcmp(s1->username, s2->username) == 0 && strcmp(s1->password, s2->password) == 0)
    return 0;
}

void getDatafromFile(char *fn, tree *bst){
  FILE *fin = fopen(fn, "r");
  char buff[100];
  while(fgets(buff, 100, fin) != NULL){
    student *a = malloc(sizeof(student));
    sscanf(buff, "%s\t%s\t%lf", a->username, a->password, &a->score);
    tree_insert_bst(&(bst->root), a, bst->elementSize, cmp_username);
  }
}

treeNode *logIn(tree *bst){
  int countWrong = 0;
  student *log = malloc(sizeof(student));
  printf("Enter username : ");
  do{
    clear_buffer();
    scanf("%[^\n]s", log->username);
    if(checkUser(log->username) == 0){
      printf("Username must not have space\n");
      printf("Enter it again : ");
      countWrong += 1;
    }
    if (countWrong == 3) exit(1);
  } while(checkUser(log->username) == 0);
  printf("Enter password : ");
  do{
    clear_buffer();
    scanf("%[^\n]s", log->password);
    if(checkPass(log->password) == 0){
      printf("Password must have more than 6 character and must not have space\n");
      printf("Enter it again : ");
      countWrong += 1;
    }
    if(countWrong == 3) exit(1);
  } while(checkPass(log->password) == 0);
  treeNode *a = tree_search(bst->root, log, cmp_username);
  if( a != NULL ) return a;
  else return NULL;
}

void modify_data(FILE *stream, treeNode *root){
  if(root == NULL) return;
  modify_data(stream, root->left);
  student *tmp = (student *)(root->data);
  fprintf(stream, "%s\t%s\t%.2lf\n", tmp->username, tmp->password, tmp->score);
  modify_data(stream, root->right);
}

void student_do(student **a, tree *bst){
  int option;
  do{
    printf("1. Score\n");
    printf("2. Change password\n");
    printf("3. Modify data\n");
    printf("4. Log Out\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      printf("Score of student %s : %lf\n", (*a)->username, (*a)->score);
      break;
    }
    case 2:{
      char first[30], second[30];
      do{
       	do{
	  clear_buffer();
	  printf("Enter new password : ");
	  scanf("%[^\n]s", first);
	  if(checkPass(first) == 0){
	    printf("Password must have more than 6 character and must not have space\n");
	    printf("Enter it again : ");
	  }
	} while(checkPass(first) == 0);
	do{
	  clear_buffer();
	  printf("Enter new password again : ");
	  scanf("%[^\n]s", second);
	  if(checkPass(second) == 0){
	    printf("Password must have more than 6 character and must not have space\n");
	    printf("Enter it again : ");
	  }
	} while(checkPass(second) == 0);
	if(strcmp(first, second) == 0) {
	  strcpy((*a)->password, first);
	  printf("Password changed\n");
	}
	else printf("2 password are not the same\n");
      } while(strcmp(first, second) != 0);
      break;
    }
    case 3:{
      FILE *fout = fopen("de2014.txt", "w");
      modify_data(fout, bst->root);
      break;
    }
    }
  } while(option != 4);
}

void admin_do(student **a, tree *bst){
    int option;
  do{
    printf("1. Add student\n");
    printf("2. LDR in username order\n");
    printf("3. Delete\n");
    printf("4. Modify\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      student *add = malloc(sizeof(student));
      do{
	clear_buffer();
	printf("Enter new username : ");
	scanf("%[^\n]s", add->username);
	if(checkUser(add->username) == 0){
	  printf("Username must not have space\n");
	  printf("Enter it again : ");
	}
      } while(checkUser(add->username) == 0);
      do{
	clear_buffer();
	printf("Enter new password : ");
	scanf("%[^\n]s", add->password);
	if(checkPass(add->password) == 0){
	  printf("Password must have more than 6 character and must not have space\n");
	  printf("Enter it again : ");
	}
      } while(checkPass(add->password) == 0);
      tree_insert_bst(&(bst->root), add, bst->elementSize, cmp_username);
      break;
    }
    case 2:{
      LDR(bst->root, iterator_student);
      break;
    }
    case 3:{
      FILE *fout = fopen("de2014.txt", "w");
      modify_data(fout, bst->root);
      break;
    }
    case 4:{
      break;
    }
    }
  } while(option != 4);
}




int main(){
  tree bst;
  tree_new(&bst, sizeof(student));
  getDatafromFile("de2014.txt", &bst);
  LDR(bst.root, iterator_student);
  int option;
  do{
    printf("\n---------------------\n");
    printf("Student Management\n");
    printf("1.Log in\n");
    printf("2.Exit\n");
    printf("\n---------------------\n");
    scanf("%d", &option);
    switch(option){
    case 1:{
      treeNode *log = logIn(&bst);
      if(log != NULL){
	student *logData = (student *)(log->data);
	if(strcmp(logData->username, "Admin") == 0){
	  printf("Admin log In Successfully\n");
	  admin_do(&logData, &bst);
	  
	}
	else if(1){
	  printf("Student %s LogIn successfully\n", logData->username);
	  student_do(&logData, &bst);
	}
      }
      else printf("Logging failed\n");
      break;
    }
    case 2:{
      printf("Bye bye");
    }
    default:{
      printf("Enter one of those options\n");
      break;
    }
    }
  }while(option != 2);
}
