#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfdr/jrb.h"
#include "libfdr/dllist.h"
#define MAX_LEN 100

typedef JRB Graph;

Graph createGraph();
void new_Vertex(Graph graph, char *v1);
void addEdge(Graph graph, char *v1, char *v2);
int getAdjacentVertices(Graph graph, char *v, int print, char output[MAX_LEN][MAX_LEN]); // wanna print ?
int checkAdjacent(Graph graph,char *v1, char *v2);
void dropGraph(Graph graph);
void printVertex(char *v);
void BFS(Graph graph, char *start, char *stop, void (*print)(char *));
int DFS(Graph graph, char *start, char *stop, void (*print)(char *));
int count_path(Graph graph, char *start, char *stop);
int n_vertices(Graph graph);
int n_edges(Graph graph);
Dllist shortest_path(Graph graph, char *start, char *stop);
int Visited(JRB visited, char *vertex);

#endif	//end GRAPH_H