#include<stdlib.h>
#include "Network.h"
Network_info func_makeNetworkInformation(FILE *fp){
  
  int begin,end;
  double distance;
  int i,j;
  Network_info ni;
  
  fscanf(fp,"%d",&ni.numPoint);
  
  ni.adjacent = (short **)malloc(sizeof(short *)*ni.numPoint);
  for(i = 0;i < ni.numPoint;i++)
    ni.adjacent[i] = (short *)malloc(sizeof(short)*ni.numPoint);

  ni.dist = (double **)malloc(sizeof(double *)*ni.numPoint);
  for(i = 0;i < ni.numPoint;i++)
    ni.dist[i] = (double *)malloc(sizeof(double)*ni.numPoint);
  
  for(i=0;i<ni.numPoint;i++)
    for(j=0;j<ni.numPoint;j++)
      ni.adjacent[i][j] = 0;

  for(i=0;i<ni.numPoint;i++)
    for(j=0;j<ni.numPoint;j++)
      ni.dist[i][j] = 0;
  
  while(fscanf(fp,"%d %d %lf",&begin,&end,&distance) != EOF){
    ni.adjacent[begin][end]++;
    ni.adjacent[end][begin]++;
    ni.dist[begin][end] = distance;
    ni.dist[end][begin] = distance;
    ni.numEdge++;
   }  


  return ni;
}    

void func_freeNetwork(Network_info ni){
  int i,j;
  for(i=0;i<ni.numPoint;i++)
    free(ni.dist[i]);
  free(ni.dist);
  for(i=0;i<ni.numPoint;i++)
    free(ni.adjacent[i]);
  free(ni.adjacent);
}
