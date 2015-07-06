#include "../network_filed/Network.h"

typedef struct Arc{
  double cost;
  int edge[2];
}Arc;

Arc *func_prim(Network_info);

