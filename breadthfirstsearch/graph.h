#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename V>
class Graph{
    public:
        Graph<V>();
        Graph<V>(V);
        ~Graph<V>();
        void addVertex(V);
        void addEdge(V, V); //(vertex 1, vertex 2) so the two vertices are connected
        void removeVertex(V);
        void removeEdge(V, V); //(Vertex 1, vertex 2) so the edge between the two vertices are removed. To do this, find the first vertex and erase
        V getVertex(V);
        bool edgeExists(V, V); //Check if edge exists between two vertices. Just check one since the code should already add to both
    private:
        map<V, vector<V>> graph;
};

#endif