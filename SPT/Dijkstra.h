#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include<math.h>
#include<stdio.h>
#include "../network_files/Network.h"


typedef struct Node{
  double dist_parent;
  int parent;
}Node;

Node *func_dijkstra(Network_info,int,int);
void func_setLengthOfAdjacencyNodes(Network_info,int,int*,Node*);
int func_getMinimumNodeIndex(Network_info,int *,Node *);
double func_min(double,double);
#endif
