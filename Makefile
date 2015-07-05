STP: Main_Dijkstra.o SPT/Dijkstra.o network_files/Network.o
	gcc -Wall -O0 -g -o SPT_DIJKSTRA Main_Dijkstra.o SPT/Dijkstra.o network_files/Network.o

Main_Dijkstra.o:Main_Dijkstra.c
	gcc -c Main_Dijkstra.c

Dijkstra.o:SPT/Dijkstra.c
	gcc -c SPT/Dijkstra.c

Network.o:network_files/Network.c
	gcc -c network_files/Network.c
