#include "directed_graph.h"

Graph createGraph()
{
   Graph g; 
   g.edges = make_jrb();  
   g.vertices = make_jrb();  
   return g;
}

void addVertex(Graph g, int id, char* name)
{
     JRB node = jrb_find_int(g.vertices, id);
     if (node == NULL) // only add new vertex 
         jrb_insert_int(g.vertices, id, new_jval_s(strdup(name)));            
}

char *getVertex(Graph g, int id)
{
     JRB node = jrb_find_int(g.vertices, id);
     if (node == NULL) 
        return NULL;
     else                
        return jval_s(node->val);
}     

void addEdge(Graph graph, int v1, int v2)
{
     JRB node, tree;
     if (!hasEdge(graph, v1, v2))
     {
        node = jrb_find_int(graph.edges, v1);
        if (node==NULL) {
           tree = make_jrb();
           jrb_insert_int(graph.edges, v1, new_jval_v(tree));
        } else {
           tree = (JRB) jval_v(node->val);   
        }
        jrb_insert_int(tree, v2, new_jval_i(1));
     }
}

int hasEdge(Graph graph, int v1, int v2)
{
    JRB node, tree;
    node = jrb_find_int(graph.edges, v1);
    if (node == NULL)
       return 0;
    tree = (JRB) jval_v(node->val);
    if (jrb_find_int(tree, v2) == NULL)
       return 0;
    else
       return 1;       
}

int indegree(Graph graph, int v, int* output)
{
    JRB tree, node;
    int total = 0;   
    jrb_traverse(node, graph.edges) {
       tree = (JRB) jval_v(node->val);
       if (jrb_find_int(tree, v)){
          output[total] = jval_i(node->key);
          total++;
       }                
    }
    return total;   
}

int outdegree(Graph graph, int v, int* output)
{
    JRB tree, node;
    int total;
    node = jrb_find_int(graph.edges, v);
    if (node == NULL)
       return 0;
    tree = (JRB) jval_v(node->val);
    total = 0;   
    jrb_traverse(node, tree){
       output[total] = jval_i(node->key);
       total++;                
    }
    return total;   
}

// int DAG(Graph graph)
// {
//    int visited[1000];
//    int n, output[100], i, u, v, start;
//    Dllist node, stack;
//    JRB vertex;
   
//    jrb_traverse(vertex, graph.vertices){
//        memset(visited, 0, sizeof(visited));

//        start = jval_i(vertex->key);              
//        stack = new_dllist();
//        dll_append(stack, new_jval_i(start));
    
//        while ( !dll_empty(stack) ){
//           node = dll_last(stack);
//           u = jval_i(node->val);
//           dll_delete_node(node);
//           if (!visited[u]){
//               visited[u] = 1;
//               n = outdegree(graph, u, output);
//               for (i=0; i<n; i++){
//                   v = output[i];
//                   if ( v == start ) // cycle detected 
//                      return 0;
//                   if (!visited[v])    
//                      dll_append(stack, new_jval_i(v));
//               }
//           }           
//        }
//    }
//    return 1; // no cycle    
// }

//DAG 
Graph dag_graph;
int dag_start, dag_check;

void dag_visit(int v) {
  if (hasEdge(dag_graph, v, dag_start))
    dag_check = 1;
}

int DAG(Graph g) {
  JRB node;
  dag_graph = g;
  jrb_traverse(node, g.vertices) {
    dag_start = jval_i(node->key);
    dag_check = 0;
    DFS(g, dag_start, -1, dag_visit);
    if (dag_check == 1) return 0;
  }
  return 1;
}

void BFS(Graph graph, int start, int stop, void (*func)(int)){
  JRB visited;
  Dllist node, queue;
  int n, output[MAX_LEN], i, u, v;

  //Initialize the queue
  queue = new_dllist();
  dll_append(queue, new_jval_i(start));
  visited = make_jrb();

  while (!dll_empty(queue)) {
    //Take one vertex from the queue
    node = dll_first(queue);
    u = jval_i(node->val);
    dll_delete_node(node);

    //if not yet vistied, visit that vertex
    if (jrb_find_int(visited, u) == NULL) {
      func(u);
      jrb_insert_int(visited, u, new_jval_i(1));
      //stop if visit the destination
      if (u == stop) break;

      //add unvisited neighbors to the queue

      n = outdegree(graph, u, output);
      for ( i = 0; i < n; i++){
        v = output[i];
        if (jrb_find_int(visited, v) == NULL)
          dll_append(queue, new_jval_i(v));
      }
    }
  }
  jrb_free_tree(visited);
}

void DFS(Graph graph, int start, int stop, void (*func)(int)){
  JRB visited;
  Dllist node, stack;
  int n, output[MAX_LEN], i, u, v;

  //Initialize the stack
  stack = new_dllist();
  dll_prepend(stack, new_jval_i(start));
  visited = make_jrb();

  while (!dll_empty(stack)) {
    //Take one vertex from the stack
    node = dll_first(stack);
    u = jval_i(node->val);
    dll_delete_node(node);

    //if not yet vistied, visit that vertex
    if (jrb_find_int(visited, u) == NULL) {
      func(u);
      jrb_insert_int(visited, u, new_jval_i(1));
      //stop if visit the destination
      if (u == stop) break;

      //add unvisited neighbors to the stack

      n = outdegree(graph, u, output);
      for ( i = 0; i < n; i++){
        v = output[i];
        if (jrb_find_int(visited, v) == NULL)
          dll_prepend(stack, new_jval_i(v));
      }
    }
  }
  jrb_free_tree(visited);
}

int topologicalSort(Graph graph, int *output){
  JRB node;
  JRB indegreeTable = make_jrb();
  int cont, count, v;

  jrb_traverse(node, graph.vertices){
    v = jval_i(node->key);
    jrb_insert_int(indegreeTable, v, new_jval_i(indegree(graph, v, output)));
  }

  count = 0;
  cont = 1;
  while(cont){
    cont = 0;
    jrb_traverse(node, indegreeTable){
      if(jval_i(node->val) == 0){
        cont = 1;
        break;
      }
    }

    if(cont){
      output[count++] = jval_i(node->key);
      jrb_delete_node(node);
      jrb_traverse(node, indegreeTable){
        if(hasEdge(graph, output[count-1], jval_i(node->key))){
          node->val = new_jval_i(jval_i(node->val) - 1);
        }
      } 
    }
  }

  return count;
}

void dropGraph(Graph graph)
{
    JRB node, tree;
    jrb_traverse(node, graph.edges){
        tree = (JRB) jval_v(node->val);
        jrb_free_tree(tree);
    }
    jrb_free_tree(graph.edges);
    jrb_free_tree(graph.vertices);
}