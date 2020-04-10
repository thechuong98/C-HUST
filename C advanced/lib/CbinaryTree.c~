#include "CbinaryTree.h"
#include "CSlist.h"
#include "Cqueue.h"
#include "Cstack.h"

void tree_new(tree *tree, int elementSize){
  tree->elementSize = elementSize;
  tree->root = NULL;
}

treeNode *newNode(void *element, int elementSize){
  treeNode *node = (treeNode *)malloc(sizeof(treeNode));
  node->data = malloc(elementSize);
  node->data = element;
  node->left = node->right = NULL; 

  return node;
}

//insert to tree
void tree_insert(tree *tree, void *element){

}

//find the size
int tree_size(treeNode *root){
  if(root == NULL) return 0;
  return tree_size(root->left) + tree_size(root->right) + 1;
}

//level Order Traversal
void level_order(tree *tree){
  if(tree->root == NULL) return;
  queue Q;
  stack S;
  queue_new(&Q, sizeof(tree->root));
  stack_new(&S, sizeof(tree->root));
  enQueue(&Q, tree->root);
  treeNode *node = (treeNode *)malloc(sizeof(tree->root));
  while(!isEmptyQueue(&Q)){
    node = deQueue(&Q);
    stack_push(&S, node);
    if(node->left != NULL) enQueue(&Q, node->left);
    if(node->right != NULL) enQueue(&Q, node->right);
  }
  list_for_each_end(S.list.head, iterator_name_tree);
}

//level Order Traversal Reverse
void level_order_reverse(treeNode *root){
  if(root == NULL) return;
  queue Q;
  stack S;
  queue_new(&Q, sizeof(root));
  stack_new(&S, sizeof(root));
  enQueue(&Q, root);
  treeNode *node = NULL;
  while(!isEmptyQueue(&Q)){
    node = deQueue(&Q);
    if(node->right != NULL) enQueue(&Q, node->right);
    if(node->left != NULL) enQueue(&Q, node->left);
    stack_push(&S, node);
  }
  while(!stack_is_empty(&S)){
    iterator_name_tree(stack_pop(&S));
  }
}

//find max depth
int tree_depth(treeNode *root){
  if (root == NULL) return 0;
  return tree_depth(root->left) > tree_depth(root->right) ? tree_depth(root->left)+1:tree_depth(root->right)+1;
}

//get deepest Node
treeNode *deepest_node(treeNode *root){
  if (root == NULL) return NULL;
  queue Q;
  queue_new(&Q, sizeof(root));
  enQueue(&Q, root);
  treeNode *node = NULL;
  while (!isEmptyQueue(&Q)){
    node = deQueue(&Q);
    if(node->left != NULL) enQueue(&Q, node->left);
    if(node->right != NULL) enQueue(&Q, node->right);
  }
  iterator_name_tree(node);
  return node;
}

//find number of leaves
int tree_num_leaves(treeNode *root){
  if(root == NULL) return 0;
  if(root->left == NULL && root->right == NULL) return 1;
  if(root->left == NULL && root->right != NULL) return tree_num_leaves(root->right);
  if(root->left != NULL && root->right == NULL) return tree_num_leaves(root->left);
  return tree_num_leaves(root->left) + tree_num_leaves(root->right);
}

//find number of full node
int tree_full_node(treeNode *root){
  if(root == NULL) return 0;
  if(root->left == NULL && root->right == NULL) return 0;
  if(root->left != NULL && root->right == NULL) return tree_full_node(root->left);
  if(root->left == NULL && root->right != NULL) return tree_full_node(root->right);
  return 1 + tree_full_node(root->left) + tree_full_node(root->right);
}

//find LCA(least common ancestor) of two node;
treeNode *LCA(treeNode *root, treeNode *node1, treeNode *node2){
  if(root == NULL) return NULL;
  if(root == node1 || root == node2){
    return root;
  } 
  treeNode *left = LCA(root->left, node1, node2);
  treeNode *right = LCA(root->right, node1, node2);
  //if node1 and node2 in both sides
  if(left != NULL && right != NULL) return root; 
  else
    if(left != NULL) return left;
    else return right;
}
//find max node
treeNode *tree_max(treeNode *root, comparator cmp){
  if(root == NULL) return NULL;
  queue Q;
  queue_new(&Q, sizeof(root));
  enQueue(&Q, root);
  treeNode *node = NULL;
  treeNode *maxNode = root;
  while(!isEmptyQueue(&Q)){
    node = deQueue(&Q);
    if(cmp(maxNode->data, node->data) < 0) maxNode = node;
    if(node->left != NULL) enQueue(&Q, node->left);
    if(node->right != NULL) enQueue(&Q, node->right);
  }
  return maxNode;
}
//find min node
treeNode *tree_min(treeNode *root, comparator cmp){
  if(root == NULL) return NULL;
  queue Q;
  queue_new(&Q, sizeof(root));
  enQueue(&Q, root);
  treeNode *node = NULL;
  treeNode *minNode = root;
  while(!isEmptyQueue(&Q)){
    node = deQueue(&Q);
    if(cmp(minNode->data, node->data) > 0) minNode = node;
    if(node->left != NULL) enQueue(&Q, node->left);
    if(node->right != NULL) enQueue(&Q, node->right);
  }
  return minNode;
}
//find a node, return NULL if not found
treeNode *tree_search(treeNode *root, void *element, comparator cmp){
  if(root == NULL) return NULL;
  if(cmp(root->data, element) == 0) return root;
  else{
    treeNode *tmp = tree_search(root->left, element, cmp);
    if(tmp != NULL) return tmp;
    else return tree_search(root->right, element, cmp);
  }
}



//Binary Search Trees
void tree_insert_bst(treeNode **root, void *element, int elementSize, comparator cmp){
  if(*root == NULL) {
    *root = newNode(element, elementSize);
  }
  else if(cmp(element, (*root)->data) < 0){
    tree_insert_bst(&((*root)->left), element, elementSize, cmp);
  }
  else if(cmp(element, (*root)->data) > 0){
    tree_insert_bst(&((*root)->right), element, elementSize, cmp);
  }
}


treeNode *tree_bst_min(treeNode *root){
  treeNode *cur = root;
  while(cur->left != NULL) cur = cur->left;
  return cur;
}

void tree_delete_bst(treeNode **root, void *element, int elementSize, comparator cmp){
   //base case
   if(*root == NULL) return;
   //compare to root
   if(cmp(element, (*root)->data) < 0) tree_delete_bst(&(*root)->left, element, elementSize, cmp);
   else if(cmp(element, (*root)->data) > 0) tree_delete_bst(&(*root)->right, element, elementSize, cmp);
   //if it is root
   else{
    if((*root)->left == NULL){
      treeNode *temp = (*root)->right;
      free((*root)->data);
      free(*root);
      *root = temp;
      return;
    }
    else if((*root)->right == NULL){
      treeNode *temp = (*root)->left;
      free((*root)->data);
      free(*root);
      *root = temp;
      return;
    }
    treeNode *temp = tree_bst_min((*root)->right);
    (*root)->data = temp->data;
    tree_delete_bst(&(*root)->right, temp->data, elementSize, cmp);
   }
}
//ham in
void iterator_name(void *data){
  phoneAddress *a = (phoneAddress *)data;
  printf("Found string value: %s\n", a->name);
}
void iterator_phone(void *data){
  phoneAddress *a = (phoneAddress *)data;
  printf("%s", a->tele);
}
//void *data is a treeNode;
void iterator_name_tree(void *data){
  treeNode *dataField = (treeNode *)data;
  phoneAddress *a = (phoneAddress *)dataField->data;
  printf("Found string value: %s\n", a->name);
}
//ham so sanh
int comparator_name(void *a, void *b){
  phoneAddress *p1 = (phoneAddress *)a;
  phoneAddress *p2 = (phoneAddress *)b;
  return strcmp(p1->name, p2->name);
}

void LDR(treeNode *root, treeIterator iterator){
  if(root == NULL) return;
  LDR(root->left, iterator);
  iterator(root->data);
  LDR(root->right, iterator);

}


int main(){
  phoneAddress a;
  strcpy(a.name, "Chu The Chuong");
  strcpy(a.tele, "0981082834");
  phoneAddress b;
  strcpy(b.name, "Vu Thanh Tung");
  strcpy(b.tele, "1925159814");
  phoneAddress c;
  strcpy(c.name, "Nguyen Duc Dung");
  strcpy(c.tele, "0981123834");
  phoneAddress d;
  strcpy(d.name, "Nguy Thien An");
  strcpy(d.tele, "1925159814");
  tree tree;
  tree_new(&tree, sizeof(phoneAddress));
  treeNode *node = newNode(&a, sizeof(phoneAddress));
  tree_insert_bst(&(tree.root), &c, sizeof(phoneAddress), comparator_name);
  tree_insert_bst(&(tree.root), &a, sizeof(phoneAddress), comparator_name);
  tree_insert_bst(&(tree.root), &b, sizeof(phoneAddress), comparator_name);
  // tree_insert_bst(&(tree.root), &d, sizeof(phoneAddress), comparator_name);
  // tree_delete_bst(&(tree.root), &b, sizeof(phoneAddress), comparator_name);
  LDR(tree.root, iterator_name);
  level_order(&tree);
  // level_order_reverse(tree.root);
  printf("%d \n", tree_depth(tree.root));
  treeNode *deepestNode = deepest_node(tree.root);
  printf("tree_size : %d\n", tree_size(tree.root));
  iterator_name_tree(LCA(tree.root, tree.root->left->right, tree.root->right));  
  iterator_name_tree(tree_min(tree.root, comparator_name)); 
  iterator_name_tree(tree_search(tree.root, &d, comparator_name));
}