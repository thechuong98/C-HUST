#include "graph.h"

void creatGraph(Graph *G, int elementSize, int sizemax){
	G->elementSize = elementSize;
	G->sizemax = sizemax;
	G->matrix = malloc(sizeof(elementSize * sizemax *sizemax));
}

void addEdge(Graph G, int v1, int v2){
	G.matrix[v1*G.sizemax + v2] = 1;
	G.matrix[v2*G.sizemax + v1] = 1;
}

int adjacent(Graph G, int v1, int v2){
	return G.matrix[v1*G.sizemax + v2];
}

int getAdjacentVertices(Graph G, int vertex, int *output){
	int total = 0;
	for(int i = 0; i < G.sizemax; ++i){
		if (adjacent(G, vertex, i)){
			output[total++] = i;
		}
	}
	return total;
}

void dropGraph(Graph G){
	free(G.matrix);

}