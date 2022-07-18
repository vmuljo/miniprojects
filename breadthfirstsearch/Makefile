all: bfs

bfs: bfs.cpp bin/graph.o
	g++ -g -Wall bfs.cpp bin/graph.o -o bfs

bin/graph.o: graph.h graph.cpp
	g++ -g -Wall -c graph.cpp graph.h -o bin/graph.o

# bin/graph: graph.cpp graph.h
# 	g++ -g -Wall graph.cpp -o bin/graph