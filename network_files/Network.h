/*Network.h*/
#ifndef NETWORK_H
#define NETWORK_H

typedef struct Network_info{
  short **adjacent;
  double **dist;
  int numPoint;
  int numEdge;
}Network_info;

Network_info func_makeNetworkInformation(FILE*);
void func_freeNetwork(Network_info);

#endif
