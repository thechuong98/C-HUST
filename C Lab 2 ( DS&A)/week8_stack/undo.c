#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackLinked-eltype-string.h"
#define  MAX 50

int main(){
  int n;
  char c[MAX];
  char popValue[MAX], Undo[MAX], UndoPush[MAX];
  char command[MAX];
  stack stack1, stack2, stack3;
  init_stack(&stack1);
  init_stack(&stack2);
  init_stack(&stack2);

  do{
    printf("----------\n");
    printf("Menu\n");
    printf("1. Push\n");
    printf("2. Peek\n");
    printf("3. Pop\n");
    printf("4. Undo\n");
    printf("5. Exit\n");
    do{
      printf("Enter(1-5): ");
      scanf(" %d", &n);
    }while(n>5 || n<1);

    switch (n){
  case 1:
    printf("Enter number: ");
    scanf(" %s", c);
    push(c, &stack1);
    
    strcpy(command,"push");
    push(command, &stack2);
    break;
  case 2:
    top(&stack1);
    break;
  case 3:
    strcpy(popValue,pop(&stack1));
    push(popValue, &stack3);
    strcpy(command,"pop");
    push(command, &stack2);
    break;
  case 4:
    strcpy(Undo,pop(&stack2));

    if(strcmp(Undo,"push")==0){
      strcpy(UndoPush,pop(&stack1));
    }

    if(strcmp(Undo,"pop")==0){
      push(pop(&stack3) ,&stack1);
    }
    
    break;
  }

  }while(n!=5);




  return 0;
}
