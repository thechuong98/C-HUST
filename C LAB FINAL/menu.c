#include "LIB/CSlist.h"
#include "LIB/Cstack.h"
#include "LIB/Cqueue.h"
#include "LIB/CbinaryTree.h"

int main(){  
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
      break;
    }
    case 2:{
      break;
    }
    case 3:{
      break;
    }
    case 4:{
      break;
    }
    case 5:{
      printf("Bye bye\n");
      break;
    }
    default:{
      printf("Enter one of those options\n");
      break;
    }
    }
  }while(option != 5);
}
