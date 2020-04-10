#ifndef __RED_BLACK_TREE_H__
#define __RED_BLACK_TREE_H__

typedef enum { RED, BLACK } Color;

typedef struct RBT_node {
	void *key;
	void *payload;
	Color color;
	struct RBT_node *left;
	struct RBT_node *right;
	struct RBT_node *parent;
} RBT_node;

typedef int (* Comparator_key)(void *, void *);

typedef struct {
	RBT_node *root;
	Comparator_key cmp_func;
	int nmemb;
} RBT;

RBT_node *new_RBT_node(void *key, void *payload) {
	RBT_node *new_node = (RBT_node *)malloc(sizeof(RBT_node));

	new_node->key = key;
	new_node->payload = payload;
	new_node->color = RED;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	
	return new_node;
}

RBT *new_RBT(Comparator_key cmp_func) {
	RBT *ret_RBT = (RBT *)malloc(sizeof(RBT));

	ret_RBT->root = NULL;
	ret_RBT->cmp_func = cmp_func;
	ret_RBT->nmemb = 0;
	
	return ret_RBT;
}

RBT_node *bst_insert(RBT_node *root, RBT_node *new_node, Comparator_key cmp_func) {

	if (root == NULL) {
		return new_node;
	}

	if (cmp_func(root->key, new_node->key) > 0) {
		root->left = bst_insert(root->left, new_node, cmp_func);
		root->left->parent = root;
	}
	else if (cmp_func(root->key, new_node->key) < 0) {
		root->right = bst_insert(root->right, new_node, cmp_func);
		root->right->parent = root;
	}

	return root;
}

int is_left_child(RBT_node *root) {
	if (root->parent) {
		return root == root->parent->left;
	}
	return 0;
}

int is_right_child(RBT_node *root) {
	if (root->parent) {
		return root == root->parent->right;
	}
	return 0;
}

void rotate_left(RBT_node **root, RBT_node *pt) {
	RBT_node *pt_right = pt->right; 
  
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
  
    pt_right->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        *root = pt_right; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
  
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right;

	return;
}

void rotate_right(RBT_node **root, RBT_node *pt) { 

	RBT_node *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        *root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
	return;
}

void swap_color(RBT_node *a, RBT_node *b) {
	Color temp_color;
	temp_color = a->color;
	a->color = b->color;
	b->color = temp_color;
	return;
}

void fix_violation(RBT_node **root, RBT_node *pt) 
{ 
    RBT_node *parent_pt = NULL; 
    RBT_node *grand_parent_pt = NULL; 
  
    while ((pt != *root) && (pt->color != BLACK) && 
           (pt->parent->color == RED)) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            RBT_node *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotate_left(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                rotate_right(root, grand_parent_pt); 
                swap_color(parent_pt, grand_parent_pt); 
                pt = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of pt is right child of Grand-parent of pt */
        else
        { 
            RBT_node *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
            { 
                grand_parent_pt->color = RED; 
                parent_pt->color = BLACK; 
                uncle_pt->color = BLACK; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotate_right(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                rotate_left(root, grand_parent_pt); 
                swap_color(parent_pt, grand_parent_pt); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    (*root)->color = BLACK;
	return;
}

void RBT_insert(RBT *tree, void *key, void *data) {
	RBT_node *new_node = new_RBT_node(key, data);
	tree->root = bst_insert(tree->root, new_node, tree->cmp_func);
	fix_violation(&(tree->root), new_node);
	return;
}

/**************** BEGIN tree traveral ********************************/

typedef void (* Todo)(RBT_node *root);


void _in_order(RBT_node *root, Todo todo) {
	if (root) {
		_in_order(root->left, todo);
		todo(root);
		_in_order(root->right, todo);
	}
	return;
}

void in_order(RBT *tree, Todo todo) {
	_in_order(tree->root, todo);
	return;
}

/********************************** END tree traversal **************/

#endif