#ifndef __CBTREE_H
#define __CBTREE_H

#include "typedef.h"
// from previous post on linked-list implementation
// in C
typedef struct treeNode{
  void *data;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

typedef struct tree {
  treeNode *root;
  int elementSize;
} tree;

void tree_new(tree *tree, int elementSize);
treeNode *newNode(void *element, int elementSize);
void tree_insert(tree *tree, void *element);
void iterator_name(void *data);
void tree_find(treeNode *root, void *element);
void DLR(treeNode *root, treeIterator);
void LDR(treeNode *root, treeIterator);
void LRD(treeNode *root, treeIterator);
void levelOrder(tree *tree);
int tree_count(tree *tree);
int depth(tree *tree);
treeNode *tree_max(treeNode *root);
treeNode *tree_min(treeNode *root);
int tree_search(tree *tree, void *element);
int tree_size(tree *tree);
void tree_delete(tree *tree);
int tree_height(tree *tree);
int tree_width(tree *tree);
int tree_num_leaves(tree *tree);
int tree_level_max(tree *tree);
treeNode *get_parent(tree *tree, void *element);
void tree_insert_bst(treeNode **root, void *element, int elementSize, comparator cmp);
void tree_delete_bst(treeNode **root, void *element, int elementSize, comparator cmp);
#endif
