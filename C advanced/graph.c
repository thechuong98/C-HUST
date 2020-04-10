#include "graph.h"

Graph createGraph(){
	Graph graph = make_jrb();
	return graph;
}

void new_Vertex(Graph graph, char *v1){
	JRB tree;
	JRB node = jrb_find_str(graph, v1);

	if (node == NULL){
		tree = make_jrb();
		jrb_insert_str(graph, v1, new_jval_v(tree));
	}
}

void addEdge(Graph graph, char  *v1, char *v2){
	JRB tree;
	JRB node = jrb_find_str(graph, v1);

	if (node == NULL){
		tree = make_jrb();
		jrb_insert_str(graph, v1, new_jval_v(tree));
	} else {
		tree = (JRB)jval_v(node->val);
	}
	if(jrb_find_str(tree, v2) == NULL){
		jrb_insert_str(tree, v2, new_jval_i(1));
	}
	node = jrb_find_str(graph,v2);
	if (node == NULL){
		tree = make_jrb();
		jrb_insert_str(graph,v2, new_jval_v(tree));
	} else {
		tree = (JRB)jval_v(node->val);
	}
	if(jrb_find_str(tree, v1) == NULL){
		jrb_insert_str(tree, v1, new_jval_i(1));
	}
}

int n_vertices(Graph graph){
	JRB node;
	int n_vertices = 0;
	jrb_traverse(node, graph){
		n_vertices++;
	}
	return n_vertices;
}

int n_edges(Graph graph){
	JRB node;
	JRB tree, tree_node;
	int n_edges = 0;
	jrb_traverse(node, graph){
		tree = (JRB)jval_v(node->val);
		jrb_traverse(tree_node, tree){
			n_edges++;
		}
	}
	return n_edges/2; //each egde is counted twice
}

int getAdjacentVertices(Graph graph, char *vertex, int print, char output[MAX_LEN][MAX_LEN]){
	JRB node = jrb_find_str(graph, vertex);
	JRB tree;
	int total = 0;
	if (node != NULL) {
		tree = (JRB) jval_v(node->val);
		total = 0;
		jrb_traverse(node, tree){
			strcpy(output[total], jval_s(node->key));
	    	if(print == 1) printVertex(jval_s(node->key));
	    	total++;
		}
	}
	return total;
}


void printVertex(char *v) { 
	int a0 = v[0]-'0';
  	int b0 = v[1]-'0';
	printf("%d%d\n", a0+1, b0+1); }

void BFS(Graph graph, char *start, char *stop, void (*print)(char *)){
	JRB visited;
	Dllist node, queue;
	int n, i;
	char *u, *v;
	char output[MAX_LEN][MAX_LEN];

	//Initialize the stack
	queue = new_dllist();
	dll_append(queue, new_jval_s(start));
	visited = make_jrb();

	while (!dll_empty(queue)) {
		//Take one vertex from the stack
		node = dll_first(queue);
		u = malloc(sizeof(node->val));
		strcpy(u, jval_s(node->val));
		dll_delete_node(node);

		//if not yet vistied, visit that vertex
		if (jrb_find_str(visited, u) == NULL) {
			print(u);
			jrb_insert_str(visited, u, new_jval_i(1));
			//stop if visit the destination
			if (strcmp(u, stop) == 0) break;

			//add unvisited neighbors to the stack

			n = getAdjacentVertices(graph, u, 0, output);
			for ( i = 0; i < n; i++){
				v = output[i];
				if (jrb_find_str(visited, v) == NULL)
					dll_append(queue, new_jval_s(v));
			}
		}
	}
	jrb_free_tree(visited);
}

// int DFS(Graph graph, char *start, char *stop, void (*print)(char *)){
// 	JRB visited;
// 	Dllist node, stack;
// 	int n, i;
// 	char *u, *v;
// 	char output[MAX_LEN][MAX_LEN];

// 	//Initialize the stack
// 	stack = new_dllist();
// 	dll_prepend(stack, new_jval_s(start));
// 	visited = make_jrb();

// 	while (!dll_empty(stack)) {
// 		//Take one vertex from the stack
// 		node = dll_first(stack);
// 		u = malloc(sizeof(node->val));
// 		strcpy(u, jval_s(node->val));
// 		dll_delete_node(node);

// 		//if not yet vistied, visit that vertex
// 		if (jrb_find_str(visited, u) == NULL) {
// 			// print(u);
// 			jrb_insert_str(visited, u, new_jval_i(1));
// 			//stop if visit the destination
// 			if (strcmp(u, stop) == 0){
// 				return 1;
// 				break;
// 			}

// 			//add unvisited neighbors to the stack

// 			n = getAdjacentVertices(graph, u, 0, output);
// 			for ( i = 0; i < n; i++){
// 				v = output[i];
// 				if (jrb_find_str(visited, v) == NULL)
// 					dll_prepend(stack, new_jval_s(v));
// 			}
// 		}
// 	}
// 	jrb_free_tree(visited);
// 	return 0;
// }

int Visited(JRB visited, char *vertex) {
    return jval_i(jrb_find_str(visited, vertex)->val);
}

int DFS(Graph graph, char *start, char *stop, void (*print)(char *)) {
    int totalVertices = 0;
    JRB node;

    JRB visited = make_jrb();
    // Initialize as not visited
    jrb_traverse(node, graph) {
        jrb_insert_str(visited, jval_s(node->key), new_jval_i(0));
        totalVertices++;
    }

    Dllist stack = new_dllist();
    Jval current_node;
    // Append the first vertex to the list
    dll_append(stack, new_jval_s(start));

    while (!dll_empty(stack)) {
        current_node = dll_last(stack)->val;
        dll_delete_node(dll_last(stack));
        
        if (!Visited(visited, jval_s(current_node))) {
            // PrintVertex(jval_i(current_node));

            // Stop traverse if met end vertex
            if (strcmp(jval_s(current_node), stop) == 0) { 
                return 1;
            }

            // Set the current node as visited
            jrb_find_str(visited, jval_s(current_node))->val = new_jval_i(1); 

            // Push all connected vertices to the stack
            char adj[MAX_LEN][MAX_LEN];
            int totalAdj = 0;
            totalAdj = getAdjacentVertices(graph, jval_s(current_node), 0, adj);
            for (int i = 0; i < totalAdj; i++) {
                if (!Visited(visited, adj[i])) {
                    dll_append(stack, new_jval_s(adj[i]));
                }
            }
        }   
    }
    return 0;
}

int count_path(Graph graph, char *start, char *stop){

}


int checkAdjacent(Graph graph, char *v1, char *v2){
	JRB node = jrb_find_str(graph, v1);
	if (node == NULL) 
		return 0;
	else {
		if ( jrb_find_str((JRB)jval_v(node->val), v2) == NULL)
			return 0;
		else 
			return 1;
	}
}

void dropGraph(Graph graph){
	JRB node;
	jrb_traverse(node, graph){
		jrb_free_tree( (JRB)jval_v(node->val) );
	}
	jrb_free_tree(graph);
}


// Dllist shortest_path(Graph graph, char *start, char *stop) {
//     int totalVertices = 0;
//     JRB node;

//     JRB visited = make_jrb();
//     JRB previous_node = make_jrb();

//     // Initialize as not visited and no previous node
//     jrb_traverse(node, graph) {
//         jrb_insert_str(visited, jval_s(node->key), new_jval_i(0)); 
//         //jrb_insert_int(previous_node, jval_i(node->key), new_jval_i(-1)); 
//         totalVertices++;
//     }

//     Dllist queue = new_dllist();
//     Jval current_node;
//     // Append the first vertex to the list & set previous node of starting node as -1
//     dll_append(queue, new_jval_s(start));
//     jrb_insert_str(previous_node, start, new_jval_i(-1)); 

//     while (!dll_empty(queue)) {
//         current_node = dll_first(queue)->val;
//         dll_delete_node(dll_first(queue));
//         Dllist shortest_path = new_dllist();
        
//         if (!Visited(visited, jval_s(current_node))) {
//             // Stop traverse and output shortest path if met end vertex
//             if (strcmp(jval_s(current_node), stop) == 0) {
//                 dll_prepend(shortest_path, current_node);

//                 // Traceback
//                 while (strcmp(jval_s(current_node),start) != 0) {
//                     current_node = jrb_find_int(previous_node, jval_i(current_node))->val;
//                     dll_prepend(shortest_path, current_node);
//                 }
//                 return shortest_path;
//             }

//             // Set the current node as visited
//             jrb_find_str(visited, jval_s(current_node))->val = new_jval_i(1);

//             // Enqueue all connected vertices & set previous_node of those as this node
//             char adj[MAX_LEN][MAX_LEN];
//             int totalAdj = 0;
//             totalAdj = getAdjacentVertices(graph, jval_s(current_node), 0, adj);
//             for (int i = 0; i < totalAdj; i++) {
//                 if (!Visited(visited, adj[i])) {
//                     dll_append(queue, new_jval_s(adj[i]));
//                     jrb_insert_str(previous_node, adj[i], current_node); 
//                 }
//             }
//         }   
//     }
//     return NULL;
// }

Dllist shortest_path(Graph graph, char *start, char *stop){   
  JRB visited, parentNode, jnode;
  Dllist path, queue, node;
  char output[MAX_LEN][MAX_LEN];
  char *u;
  int total;

  visited = make_jrb();  
  parentNode = make_jrb();  
  queue = new_dllist();    
  dll_append(queue, new_jval_s(start));  // add start vao queue
  while(!dll_empty(queue)){    
    node = dll_first(queue);       // enqueue node dau tien, lay gia tri va xoa node
    u = malloc(sizeof(node->val));
    strcpy(u, jval_s(node->val));
    dll_delete_node(node);

    if(strcmp(u, stop) == 0){   // dung vong lap khi gap stop
      path = new_dllist();
      dll_prepend(path, new_jval_s(u));  
      jnode = jrb_find_str(parentNode, u); 

      while(jnode!=NULL){
       
        dll_prepend(path, jnode->val);
        strcpy(u, jval_s(jnode->val));
        jnode = jrb_find_str(parentNode, u);
      
      }
      jrb_free_tree(visited);
      jrb_free_tree(parentNode);
      return path;
    }

    if(jrb_find_str(visited, u)==NULL){ // neu u chua co mat trong cay chua cac phan tu da duyet
      jrb_insert_str(visited, u, new_jval_i(0));   // them node u vao cay visited
      total = getAdjacentVertices(graph, u, 0, output);   // lay tat ca cac node co adjacent voi node u 
      for(int i = 0;i < total; i++){
        if(jrb_find_str(visited, output[i]) == NULL){  // neu cac node day chua duoc duyet, them vao queue
          dll_append(queue, new_jval_s(output[i]));
          if(jrb_find_str(parentNode, output[i])==NULL){   
            jrb_insert_str(parentNode,output[i], new_jval_s(u));  // node nao chua co trong parent thi cho vao
          }
        }
      }
    }
  }
  return NULL;
}