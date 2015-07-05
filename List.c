#include "List.h"

List_int *func_makeRootOfList(void){
  List_int *root;
  root = (root *)calloc(1,sizeof(root));
  root->next = NULL;
}


