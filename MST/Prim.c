/*Prim.c*/
Arc *func_prim(Network_info ni,int start){
  int i,j;
  Arc *arc;
  int *U;
  Arc minarc;
  U = (int *)calloc(ni.numPoint,sizeof(int));
  arc = (Arc *)calloc(ni.numEdge,sizeof(Arc));
  U[start] = 1;
 
  while(sum < ni.numPoint){
    sum = 0;
    for (i = 0; i < ni.numPoint; i++) {
      if(U[i]){
	for (j = 0; j < ni.numPoint; j++) {
	  if (!U[i] && ni.adjacent[i][j]) {
	    if(dist[i][j] < min){
	      min = dist;
	      minarc.cost = dist[i][j];
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
