#include<stdio.h>
#include<stdlib.h>
#include"network_files/Network.h"
#include"SPT/Dijkstra.h"

FILE *func_InputFile(char *); //ファイル読み込み

int main(int argc, char *argv[])
{
  int i;
  double cost = 0;
  int start,goal;
  Network_info  ni;
  int *route;
  FILE *fp;
  if(argc < 2){
    printf("Show this program's Usage:\n");
    printf("~this~.out ");
    printf("\x1b[31m");
    printf("graph_file_path start goal\n");
    printf("\x1b[39m");
    exit(1);
  }
  //ファイルポインタの取得
  fp = func_InputFile(argv[1]);
  //start,goalの初期化
  start = atoi(argv[2]);
  goal = atoi(argv[3]);
  //ネットワークグラフに関する情報の取得
  ni = func_makeNetworkInformation(fp);
  //dijkstra法によるstart to goalの最短経路
  route = func_dijkstra(ni,start,goal);
  i=0;
  printf("最短経路は:");
  printf("%d ->",start);
    
  while(route[i+1] != -1){    
    cost += ni.dist[route[i]][route[i+1]];
    i++;      
    printf("%d ->",route[i]);
  }
  printf("\n");
  printf("経路長 = %d\n",cost);
  
  
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
