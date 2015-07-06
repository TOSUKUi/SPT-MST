/*Prim.c*/
#include"Prim.h"
Arc *func_prim(Network_info ni,int start){
  int i,j;
  Arc *arc;
  int *U;
  Arc minarc;
  int sum = 0;
  double min;
  int length = 0;
  U = (int *)calloc(ni.numPoint,sizeof(int));
  arc = (Arc *)calloc(ni.numEdge,sizeof(Arc));
  U[start] = 1;
 
  while(sum < ni.numPoint){
    min = 5000;
    sum = 0;
    for (i = 0; i < ni.numPoint; i++) {
      if(U[i]){
	for (j = 0; j < ni.numPoint; j++) {
	  if (!U[j] && ni.adjacent[i][j]) {
	    if(ni.dist[i][j] < min){
	      min = ni.dist[i][j];
	      minarc.cost = ni.dist[i][j];
	      minarc.edge[0] = i;
	      minarc.edge[1] = j;
	    }
	  }
	}
      }
    }
    U[minarc.edge[1]] = 1;
    arc[length] = minarc;
    length++;
    for(i=0;i<ni.numPoint;i++)
      sum += U[i];
  }
  return arc;
}
