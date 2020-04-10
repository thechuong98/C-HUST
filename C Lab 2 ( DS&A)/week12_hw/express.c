#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTreeStack.h"

treeNode* express(char* line)
{
  stack oprand;
  oprand.top = NULL;
  for(int i=0;i<strlen(line);i++){
    if(line[i] >= '0' && line[i] <= '9'){
      treeType val;
      val.ch = line[i];
      treeNode* tmp = newNode(val);
      push(tmp,&oprand);
    }else if(line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/'){
      treeType val;
      val.ch = line[i];
      treeNode* opr1 = pop(&oprand);
      treeNode* opr2 = pop(&oprand);
      treeNode* tmp = createfrom2(val,opr2,opr1);
      push(tmp,&oprand);
    }
  }
  treeNode* T = pop(&oprand);
  return T;
}

float evaluate(treeNode* T)
{
  switch(T->value.ch){
  case '0':
    {
      return 0;
      break;
    }
  case '1':
    {
      return 1;
      break;
    }
  case '2':
    {
      return 2;
      break;
    }
  case '3':
    {
      return 3;
      break;
    }
  case '4':
    {
      return 4;
      break;
    }
  case '5':
    {
      return 5;
      break;
    }
  case '6':
    {
      return 6;
      break;
    }
  case '7':
    {
      return 7;
      break;
    }
  case '8':
    {
      return 8;
      break;
    }
  case '9':
    {
      return 9;
      break;
    }
  case '+':
    {
      return evaluate(T->left) + evaluate(T->right);
      break;
    }
  case '-':
    {
      return evaluate(T->left) - evaluate(T->right);
      break;
    }
  case '*':
    {
      return evaluate(T->left) * evaluate(T->right);
      break;
    }
  case '/':
    {
      return evaluate(T->left) / evaluate(T->right);
      break;
    }
  }
}

int main(int argc,char* argv[])
{
  if(argc != 2)
    printf("Syntax Error!\n");
  else{
    printf("The result is: %g\n",evaluate(express(argv[1])));
  }
  return 0;
}
