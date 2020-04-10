#ifndef __CBTREE_H
#define __CBTREE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
void DLR(treeNode *root, treeIterator);
void LDR(treeNode *root, treeIterator);
void LRD(treeNode *root, treeIterator);
void level_order(tree *tree);
void level_order_reverse(treeNode *root);
int tree_size(treeNode *root);
int tree_depth(treeNode *root);
treeNode *deepest_node(treeNode *root);
int tree_num_leaves(treeNode *root);
int tree_full_node(treeNode *root);
treeNode *LCA(treeNode *root, treeNode *node1, treeNode *node2);
treeNode *tree_max(treeNode *root, comparator cmp);
treeNode *tree_min(treeNode *root, comparator cmp);
treeNode *tree_search(treeNode *root, void *element, comparator cmp);
void tree_delete(tree *tree);
int tree_height(tree *tree);
int tree_width(treeNode *root);
int tree_level_max(tree *tree);
treeNode *get_parent(tree *tree, void *element);
void tree_insert_bst(treeNode **root, void *element, int elementSize, comparator cmp);
void tree_delete_bst(treeNode **root, void *element, int elementSize, comparator cmp);
void iterator_name_tree(void *data);
#endif
