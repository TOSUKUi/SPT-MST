STP-MST: SPT-MST.o SPT/Dijkstra.o network_files/Network.o MST/Prim.o
	gcc -Wall -O2  -o SPT-MST SPT-MST.o SPT/Dijkstra.o network_files/Network.o MST/Prim.o

SPT-MST.o:SPT-MST.c
	gcc -c SPT-MST.c

Dijkstra.o:SPT/Dijkstra.c
	gcc -c SPT/Dijkstra.c

Network.o:network_files/Network.c
	gcc -c network_files/Network.c

Prim.o:MST/Prim.c
	gcc -c MST/Prim.c
