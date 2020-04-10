#include <stdio.h>
#include <stdlib.h>

typedef struct elementtype
{
  int num;
  char ch;
}treeType;

typedef struct treeNode
{
  treeType value;
  struct treeNode* left;
  struct treeNode* right;
}treeNode;

treeType readNode()
{
  treeType new;
  printf("number:");
  scanf("%d",&new.num);
  return new;
}




typedef struct node
{
  treeNode* tree;
  struct node* next;
}stackNode;

typedef struct stack
{
  stackNode *top;
}stack;




void makeNullTree(treeNode** tree)
{
  *tree = NULL;
}

int isEmpty(treeNode* tree)
{
  if(tree == NULL)
    return 1;
  else return 0;
}

treeNode* leftChild(treeNode* T)
{
  if(T != NULL) return T->left;
  else return NULL;
}

treeNode* rightChild(treeNode* T)
{
  if(T != NULL) return T->right;
  else return NULL;
}

treeNode* newNode(treeType val)
{
  treeNode* new = (treeNode*)malloc(sizeof(treeNode));
  new->left = NULL;
  new->right = NULL;
  new->value = val;
  return new;
}

int isLeaf(treeNode* N)
{
  if(N !=NULL)
    return (leftChild(N) == NULL) && (rightChild(N) ==NULL);
  else return -1;
}

int nb_nodes(treeNode* T)
{
  if(isEmpty(T)) return 0;
  else return 1 + nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}

treeNode* createfrom2(treeType val,treeNode* L, treeNode* R)
{
  treeNode* New;
  New = (treeNode*)malloc(sizeof(treeNode));
  New->value = val;
  New->left = L;
  New->right = R;
  return New;
}

treeNode* Add_LeftMost(treeNode** Tree,treeType val)
{
  treeNode* new = newNode(val);
  if(new == NULL) return new;
  if(*Tree == NULL)
    *Tree = new;
  else{
    treeNode* Lnode = *Tree;
    while (Lnode->left != NULL)
      Lnode = Lnode->left;
    Lnode->left = new;
  }
  return new;
}

treeNode* Add_RightMost(treeNode** Tree,treeType val){
  treeNode* new = newNode(val);
  if(new == NULL) return new;
  if(*Tree == NULL)
    *Tree = new;
  else{
    treeNode* Rnode = *Tree;
    while (Rnode->right != NULL)
      Rnode = Rnode->right;
    Rnode->right = new;
  }
  return new;
}

// binary search tree

treeNode* Search(int x,treeNode* Root)
{
  if (Root == NULL) return NULL; // not found
  else if (Root->value.num == x) //found x
    return Root;
  else if (Root->value.num < x)
    //continue searching in the right sub tree
    return Search(x,Root->right);
  else {
    // continue searching in the left sub tree
    return Search(x,Root->left);
  }
}

void insertNode(int x,treeNode** Root )
{
  if (*Root == NULL){
    // Create a new node for key x 
    *Root=(treeNode*)malloc(sizeof(treeNode));
    (*Root)->value.num = x;
    (*Root)->left = NULL;
    (*Root)->right = NULL;
  }
  else if (x < (*Root)->value.num) insertNode(x, &(*Root)->left);
  else if (x > (*Root)->value.num) insertNode(x, &(*Root)->right);
}

int DeleteMin (treeNode** Root )
{
  int k;
  if ((*Root)->left == NULL){
    k=(*Root)->value.num;
    (*Root) = (*Root)->right;
    return k;
  }
  else return DeleteMin(&(*Root)->left);
}

void DeleteNode(int x,treeNode** Root)
{
  if(*Root!=NULL)
    if(x < (*Root)->value.num) DeleteNode(x, &(*Root)->left);
    else if(x > (*Root)->value.num) DeleteNode(x, &(*Root)->right);
    else if(((*Root)->left==NULL)&&((*Root)->right==NULL))
      *Root=NULL;
    else if ((*Root)->left == NULL)
      *Root = (*Root)->right;
    else if ((*Root)->right==NULL)
      *Root = (*Root)->left;
    else (*Root)->value.num = DeleteMin(&(*Root)->right);
}

//end BST

// traversal

void preOrder(treeNode* tree)
{
  if(tree != NULL){
    printf("%d\t",tree->value.num);
    preOrder(tree->left);
    preOrder(tree->right);
  }
}

void inOrder(treeNode* tree)
{
  if(tree != NULL){
    inOrder(tree->left);
    printf("%c",tree->value.ch);
    inOrder(tree->right);
  }
}

void postOrder(treeNode* tree)
{
  if(tree!=NULL)
    {
      postOrder(tree->left);
      postOrder(tree->right);
      printf("%d\t",tree->value.num);
    }
}












int isEmptyS(stack s)
{
  if(s.top == NULL)
    return 1;
  else return 0;
}

stackNode* newNodeS(treeNode* val)
{
  stackNode* new = (stackNode*)malloc(sizeof(stackNode));
  new->tree = val;
  new->next = NULL;
  return new;
}

void push(treeNode* val,stack *s)
{
  stackNode* new = newNodeS(val);
  new->next = (*s).top;
  (*s).top = new;
}

treeNode* pop(stack *s)
{
  if(isEmptyS(*s) == 1){
    printf("Empty\n");
  }else{
    treeNode* value = (*s).top->tree;
    stackNode* to_free = (*s).top;
    (*s).top = (*s).top->next;
    free(to_free);
    return value;
  }
}









/*int main()
{
  // create BST
  treeNode* BST;
  makeNullTree(&BST);
  insertNode(7,&BST);
  insertNode(4,&BST);
  insertNode(9,&BST);
  insertNode(2,&BST->left);
  insertNode(6,&BST->left);
  insertNode(8,&BST->right);
  insertNode(11,&BST->right);
  insertNode(1,&BST->left->left);
  insertNode(3,&BST->left->left);
  insertNode(5,&BST->left->right);
  insertNode(10,&BST->right->right);
  //

  //Test
  
  DeleteNode(9,&BST);
  //printf("%d\n",DeleteMin(&BST));
  //treeNode* tmp = Search(11,BST);
  //printf("%d\n",tmp->left->value.num);

  postOrder(BST);
  printf("\n");
  inOrder(BST);
  printf("\n");
  //preOrder(BST);
  //printf("\n");

  //
  
  return 0;
}
*/

//STACK




