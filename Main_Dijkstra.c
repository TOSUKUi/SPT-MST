#include<stdio.h>
#include<stdlib.h>
#include"network_files/Network.h"
#include"SPT/Dijkstra.h"
#include"MST/Prim.h"
FILE *func_InputFile(char *); //ファイル読み込み

int main(int argc, char *argv[])
{
  int i,j;
  double cost = 0.0;
  int start,goal;
  Network_info  ni;
  int *route;
  FILE *fp;
  Node *graph;
  Arc *arc;
  int choose;
  if(argc < 2){
    printf("Show this program's Usage:\n");
    printf("~this~ ");
    printf("\x1b[31m");
    printf("graph_file_path\n");
    printf("\x1b[39m");
    exit(1);
  }
  //ファイルポインタの取得
  fp = func_InputFile(argv[1]);
  //ネットワークグラフに関する情報の取得
  ni = func_makeNetworkInformation(fp);
  
  printf("choose the using method.\n1:Dijkstra(Shortest path)\n2:Prim(minimum spanning tree)\n:");
  scanf("%d",&choose);


  for(i=0;i<ni.numPoint;i++){
    for(j=0;j<ni.numPoint;j++)
      printf("%d ",ni.adjacent[i][j]);
    printf("\n");
  }

  
  if(choose == 1){
//start,goalの初期化
    printf("start = ");
    scanf("%d",&start);
    printf("gpal = ");
    scanf("%d",&goal);
    //dijkstra法によるstart to goalの最短経路
    graph = func_dijkstra(ni,start,goal);
    for (i = goal; i != start; i = graph[i].parent) {
    printf("%d <-",i);
    }
    printf("%d start",start);
    printf("\n");
    
    printf("\n");
    printf("経路長 = %lf\n",graph[goal].dist_parent);
  }else if(choose == 2){
    printf("start = ");
    scanf("%d",&start);
    arc = func_prim(ni,start);
    for (i = 0; arc[i].cost != 0; i++) {
      printf("Arc : (%d , %d) cost = %lf\n",arc[i].edge[0],arc[i].edge[1],arc[i].cost);
    }
    printf("\n");
  } else{
    printf("Wrong input");
    exit(1);
  }
  
  
  /*for(i=0;i<ni.numPoint;i++){
    for(j=0;j<ni.numPoint;j++)
      printf("%lf ",ni.dist[i][j]);
    printf("\n");
    }*/
  
  
  
  return 0;
}

FILE *func_InputFile(char *input){
  FILE *fp;
  if((fp = fopen(input,"r")) == NULL){
    printf("Wrong the filename!!\n");
    exit(EXIT_FAILURE); //エラーなんで落ちます
  }
  return fp;
}
