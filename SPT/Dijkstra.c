#include "Dijkstra.h"

int *func_dijkstra(Network_info ni,int start,int goal){
  int i,current;
  int *route;
  Node *graph;
  int *U;
  int length = 0;
  U = (int *)calloc(ni.numPoint,sizeof(int));
  graph = (Node *)calloc(ni.numPoint,sizeof(Node));
  route = (int *)calloc(ni.numPoint,sizeof(int));
  
  for (i = 0;i < ni.numPoint; i++) {
    graph[i].dist_parent = 20000000;
    graph[i].parent = -1;
    route[i] = -1;
  }
  
  graph[start].dist_parent = 0;
  
  while(1){
    current = func_getMinimumNodeIndex(ni,U,graph);
    if(current != goal){
      func_setLengthOfAdjacencyNodes(ni,current,U,graph);
      route[length] = current;
      length++;
      U[current] = 1;
    }else break;    
  }
  free(U);
  free(graph);

  return route;  
}

void func_setLengthOfAdjacencyNodes(Network_info ni,int current,int *U,Node *graph){
  int i;
  for(i=0;i<ni.numPoint;i++)
    if(!U[i] && ni.adjacent[current][i]){
      graph[i].dist_parent = func_min(graph[current].dist_parent + ni.dist[current][i],graph[i].dist_parent);
      if(graph[i].dist_parent == graph[current].dist_parent + ni.dist[current][i])
	graph[i].parent = current;
    }
}

int func_getMinimumNodeIndex(Network_info ni,int *U,Node *graph){
  int i;
  double min = 20000000;
  
  int index;
  for (i = 0;i < ni.numPoint; i++) {
    if(!U[i] && graph[i].dist_parent < min){
      min = graph[i].dist_parent;
      index = i;
    }    
  }
  return index;
}

int func_min(int a,int b){
  if (a < b) return a;
  else return b;
}
