STP-MST: Main_Dijkstra.o SPT/Dijkstra.o network_files/Network.o MST/Prim.o
	gcc -Wall -O2  -o SPT-MST Main_Dijkstra.o SPT/Dijkstra.o network_files/Network.o MST/Prim.o

Main_Dijkstra.o:Main_Dijkstra.c
	gcc -c Main_Dijkstra.c

Dijkstra.o:SPT/Dijkstra.c
	gcc -c SPT/Dijkstra.c

Network.o:network_files/Network.c
	gcc -c network_files/Network.c

Prim.o:MST/Prim.c
	gcc -c MST/Prim.c
