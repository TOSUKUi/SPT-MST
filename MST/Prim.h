#include<stdlib.h>
#include<stdio.h>
#include "../network_files/Network.h"

typedef struct Arc{
  double cost;
  int edge[2];
}Arc;

Arc *func_prim(Network_info,int);

