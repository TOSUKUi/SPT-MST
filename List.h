#ifndef LIST_INT_H
#define LIST_INT_H
typedef struct List_int{
  int val;
  int index;
  struct List *next;
}List_int;

List_int *func_makeRootOfList(void);
List_int *func_addList(int);

#endif

