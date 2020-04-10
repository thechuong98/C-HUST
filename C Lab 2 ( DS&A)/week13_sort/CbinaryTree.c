#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
  memcpy(node->data, element, elementSize);
  node->left = node->right = NULL; 

  return node;
}

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
// void iterator_name(void *data){
//   phoneAddress *a = (phoneAddress *)data;
//   printf("Found string value: %s\n", a->name);
// }
//ham so sanh
// int comparator_name(void *a, void *b){
//   phoneAddress *p1 = (phoneAddress *)a;
//   phoneAddress *p2 = (phoneAddress *)b;
//   return strcmp(p1->name, p2->name);
// }

void LDR(treeNode *root, treeIterator iterator){
  if(root == NULL) return;
  LDR(root->left, iterator);
  iterator(root->data);
  LDR(root->right, iterator);

}

// int main(){
//   phoneAddress a;
//   strcpy(a.name, "Chu The Chuong");
//   strcpy(a.tele, "0981082834");
//   phoneAddress b;
//   strcpy(b.name, "Vu Thanh Tung");
//   strcpy(b.tele, "1925159814");
//   phoneAddress c;
//   strcpy(c.name, "Nguyen Duc Dung");
//   strcpy(c.tele, "0981123834");
//   tree tree;
//   tree_new(&tree, sizeof(phoneAddress));
//   treeNode *node = newNode(&a, sizeof(phoneAddress));
//   tree_insert_bst(&(tree.root), &b, sizeof(phoneAddress), comparator_name);
//   tree_insert_bst(&(tree.root), &c, sizeof(phoneAddress), comparator_name);
//   tree_delete_bst(&(tree.root), &b, sizeof(phoneAddress), comparator_name);
//   iterator_name(tree.root->data);
// }
