#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct element{
	int val;
} T;

typedef struct treeNode{
	int val;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *newNode(int val);
treeNode *randomInsert(treeNode *root, int val);
void freeTree(treeNode *root);
void DLR(treeNode *root);
void LDR(treeNode *root);
void LRD(treeNode *root);
void LevelOrder(treeNode *root);
int countNode(treeNode *root);
// int depth(treeNode *root);
treeNode *FindMax(treeNode *root);
treeNode *FindMin(treeNode *root);
int searchNode(treeNode *root, int val);
void insertNode(treeNode *root, int val);
int sizeTree(treeNode *root);
void LevelOrderReverse(treeNode *root);
void deleteTree(treeNode *root);
int treeHeight(treeNode *root);
treeNode *deepestNode(treeNode *root, int level, int *maxLen, int *val);
int numberOfLeaves(treeNode *root);
int numberOfFullNode(treeNode *root);
int numberOfHalfNode(treeNode *root);
int treeWidth(treeNode *root, int *ptr);
int levelWithMaxSum(treeNode *root);
int maxPathSum(treeNode *root, int *res);
void printPathsRecur(treeNode *root, int paths[], int pathLength);
int hasPathSum(treeNode *root, int sum);
int treeSum(treeNode *root);
treeNode *LCA(treeNode *root, treeNode *a, treeNode *b);
void ZigzacTraversal(treeNode *root);
int isoMetric(treeNode *root1, treeNode *root2);
treeNode *mirror(treeNode *root);
int OddSum(treeNode *root);
int EvenLeaf(treeNode *root);
treeNode *parent(treeNode *root, int val);
int depth(treeNode *root, int val, int depth);
int isLeaf(treeNode *node);
int check(treeNode *root);
//insert node in BST
void insertBST(treeNode **root, int val);


#endif // BINARY_TREE_H

