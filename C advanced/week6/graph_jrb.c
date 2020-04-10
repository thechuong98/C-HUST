#include <stdio.h>
#include <string.h>
#include "jrb.h"

typedef JRB Graph;

Graph creatGraph(){
	Graph G = make_jrb();
	return G;
}

void addEdge(Graph G, int v1, int v2){
	jrb node = jrb_find_int(G, v1);
	JRB tree;
	if(node == NULL)
		tree = make_jrb();
		jrb_insert_int(G, v1, new_jval_v(tree));
	}
	else{
		tree = (JRB)jval_v(node->val)
	}
	jrb_insert_int(tree, v2, new_jval_i(1));
}

int adjacent(Graph G, int v1, int v2){
	JRB node = jrb_find_int(G, v1)
	if(node == NULL) return 0;
	else{
		if(jrb_find_int((JRB)()))
	}
}

int getAdjacentVertices(Graph G, int v, int *output){
	JRB node = jrb_find_int(graph, v);
	JRB tree;
	int count = 0;
	if(node != NULL){
		tree = (JRB)jval_v(node->val);
		count = 0;
		jrb_traverse(tree){

		}
	}
}

void dropGraph(Graph G){

}

int main(){
	Graph G = creatGraph();
	addEdge(G, 1, 2);
}