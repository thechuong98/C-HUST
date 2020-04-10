#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10

typedef struct{
	int *matrix;
	int elementSize;
	int sizemax;
} Graph;

void creatGraph(Graph *G, int elementSize, int sizemax);
void addEdge(Graph G, int v1, int v2);
int adjacent(Graph G, int v1, int v2);
int getAdjacentVertices(Graph G, int vertex, int *output);
void dropGraph(Graph G);

#endif