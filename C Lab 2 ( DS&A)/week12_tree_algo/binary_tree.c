#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

treeNode *newNode(int val){
	treeNode *new = (treeNode*)malloc(sizeof(treeNode));
	if(new == NULL){
		printf("Out of memory.\n");
		exit(1);
	}
	else{
		new->left = NULL;
		new->right = NULL;
		new->val = val;
	}
	return new;
}


void DLR(treeNode *root){
	if(root == NULL) return;
	printf("%d", root->val);
	DLR(root->left);
	DLR(root->right);
}

void LDR(treeNode *root){
	if(root == NULL) return;
	LDR(root->left);
	printf("%d", root->val);
	LDR(root->right);
}

void LRD(treeNode *root){
	if(root == NULL) return;
	LRD(root->left);
	LRD(root->right);
	printf("%d", root->val);
}

void LevelOrder(treeNode *root){
	if(root == NULL) return;

}

int countNode(treeNode *root){
	if(root == NULL) return 0;
	else return(1 + countNode(root->left) + countNode(root->right));
}

// int depth(treeNode *root){
// 	if(root == NULL) return 0;
// 	return (depth(root->left) >= depth(root->right) ? depth(root->left) : depth(root->right)) + 1;
// }

treeNode *FindMax(treeNode *root){
	int root_val;
	treeNode *left, *right;
	treeNode *max;
	max->val = -9999999;
	if(root != NULL){
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left->val > right->val) max = left;
		else max = right;
		if(root->val > max->val) max = root;
	}
	return max;
}

treeNode *FindMin(treeNode *root){
	int root_val;
	treeNode *left, *right;
	treeNode *min;
	min->val = 99999999;
	if(root != NULL){
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left->val < right->val) min = left;
		else min = right;
		if(root->val < min->val) min = root;
	}
	return min;
}

int searchNode(treeNode *root, int val){
	int temp;
	if(root == NULL) return 0;
	else{
		if(val == root->val) return 1;
		else{
			temp = searchNode(root->left, val);
			if (temp != 0) return temp;
			else return(searchNode(root->right, val));
		}
	}
}

void insertNode(treeNode *root, int val){
	treeNode *new = newNode(val);
	if(!root){
		root = new;
		return;
	}
	treeNode *temp = root;
	if(!temp->left) insertNode(temp->left, val);
	if(!temp->right) insertNode(temp->right, val);
}

int sizeTree(treeNode *root){
	if(root == NULL) return 0;
	else return (sizeTree(root->left) + 1 + sizeTree(root->right));
}

void deleteTree(treeNode *root){
	if(root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int treeHeight(treeNode *root){
	int leftHeight, rightHeight;
	if(root == NULL) return 0;
	else{
		leftHeight = treeHeight(root->left);
		rightHeight = treeHeight(root->right);
		if(leftHeight > rightHeight) return leftHeight + 1;
		else return rightHeight + 1;		
	}
}

// treeNode *deepestNode(treeNode *root, int level, int *maxlv, int *val){
// 	if(root == NULL) return NULL;
// }

int numberOfLeaves(treeNode *root){
	if(root == NULL) return 0;
	if((root->left == NULL) && (root->right == NULL)) return 1;
	return (numberOfLeaves(root->left) + numberOfLeaves(root->right));
}

int numberOfFullNode(treeNode *root){
	if(root == NULL) return 0;
	if((root->left != NULL) && (root->right != NULL)){
		return(1+numberOfFullNode(root->left) + numberOfFullNode(root->right));
	}
	else return(numberOfFullNode(root->left) + numberOfFullNode(root->right));
}

int numberOfHalfNode(treeNode *root){
	if(root == NULL) return 0;
	if(((root->left == NULL) && (root->right != NULL)) || ((root->left != NULL) &&(root->right == NULL)))
		return (1+numberOfHalfNode(root->left) + numberOfHalfNode(root->right));
	else return(numberOfHalfNode(root->left) + numberOfHalfNode(root->right));
}

int treeWidth(treeNode *root, int *ptr){
	int left, right;
	if(root == NULL) return 0;
	left = treeWidth(root->left, ptr);
	right = treeWidth(root->right, ptr);
	if(left+right> *ptr) *ptr = left+right;
	if(left > right) return left + 1;
	else return right + 1;
}



// int levelWithMaxSum(treeNode *root){

// }

// int maxPathSum(treeNode *root, int *res){
// 	if(root == NULL) return 0;
// 	int l = maxPathSum(root->left, res);
// 	int r = maxPathSum(root->right, res);
// 	int max_single = max(max(l, r) + root->val, root->val);
// 	int max_top = max(max_single, l+r+root->val);
// 	*res = max(res, max_top);
// 	return max_single;
// }

int isoMetric(treeNode *root1, treeNode *root2){
	if(root1 == NULL && root2 == NULL) return 1;
	if(root1 == NULL || root2 == NULL) return 0;
	return((root1->val == root2->val) && isoMetric(root1->left, root2->left) && isoMetric(root1->right, root2->right));
}

treeNode *mirror(treeNode *root){
	treeNode *temp;
	if(root == NULL) return NULL;
	mirror(root->left);
	mirror(root->right);
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	return root;
}

int OddSum(treeNode *root){
	if(root == NULL) return 0;
	if(root->val % 2 != 0) return(OddSum(root->left) + root->val + OddSum(root->right));
	else return (OddSum(root->left) + OddSum(root->right));
}	

int EvenLeaf(treeNode *root){
	if(root == NULL) return 0;
	if(root->val % 2 == 0) return(EvenLeaf(root->left) + 1 + EvenLeaf(root->right));
	else return (EvenLeaf(root->left) + EvenLeaf(root->right));
}

// int EvenMax(treeNode *root){
// 	int max = -9999;
// 	int maxLeft = -9999;
// 	int maxRight = -9999;
// 	if(root == NULL) return -9999;
// 	if(root->val % 2 == 0){
// 		maxLeft = EvenMax(root->left);
// 		maxRight = EvenMax(root->right);
// 		if(maxLeft > maxRight) max = maxLeft;
// 		else max = maxRight;
// 		if(max < root->val) max = root->val;
// 		return max;
// 	}
// }

treeNode *parent(treeNode *root, int val){
	treeNode *temp;
	if(root == NULL) return NULL;
	if(root->left->val == val) return root;
	if(root->right->val == val)return root;
	else {
		temp = parent(root->left, val);
		if(temp != NULL) return temp;
		temp = parent(root->right, val);
	}
	return temp;
}

// int depthNode(treeNode *root, int val, int depth){
// 	int depth = 1;
// 	if(root == NULL) return 0;
// 	if(root->val == val) return 1;
// 	else{
// 		int depth 
// 	}
// 	return 0;
// }

// int checkBalance(treeNode *root){
// 	if(root == NULL) return 0;
// }

int isLeaf(treeNode *node){
	if(node != NULL) return (node->left == NULL && node->right == NULL);
	else return 0;
}

int check(treeNode *root){
	if(root == NULL) return 1;
	if(root->left == NULL && root->right == NULL) return 1;
	if(root->left == NULL || root->right == NULL) return 0;
	return (check(root->left) && check(root->right));
}

 void insertBST(treeNode **root, int val){
	if(*root == NULL){
		*root = newNode(val);
	}
	else if(val < (*root)->val) insertBST(&(*root)->left, val);
	else if(val > (*root)->val) insertBST(&(*root)->right, val);
}