#include "graph.h"

using graphType = map<int, vector<int>>;
// This basically creates the graph class
// To add a vertex, simply create a new key with a pushback on the vector with the value being the last node. This connects the two vertices and sets it as the edge
// template<typename V>
// struct vertex{
//     //Each vertex should have a value, predecessor, and depth in terms of BFS
// };
// For BFS, we could create some data structure to store the predecessor to a vertex and the depth value
// Want to be able to search using value?
// For my implementation of the graph, I do not want vertices of the same value so I will therefore use a map for O(logn) lookup
// ALternatively I could use an array or something to store node IDs and use a vector so lookup can be O(1)

// Default constructor
template<typename V>
Graph<V>::Graph(){}

template<typename V>
Graph<V>::Graph(V vert){
    graph[vert]; //Adds a vertex to the graph with an empty vector
}

// Destructor
template<typename V>
Graph<V>::~Graph(){}

// Adds vertex to map with empty edge list
template<typename V>
void Graph<V>::addVertex(V vert){
    if(!vertexExists(vert)){
        graph[vert];
        return;
    }
    else{cout << "Vertex already exists. No duplicates may be made." << endl;}
}

// Adds edge (connects 2 vertices)
template<typename V>
void Graph<V>::addEdge(V v1, V v2){
    if(vertexExists(v1) && vertexExists(v2)){
        if(edgeExists(v1, v2)){
            cout << "Edge already exists" << endl;
        }
        else{
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
    }
    else cout << "Invalid vertices" << endl;
}

// Removes edge from 2 vertices
template<typename V>
void Graph<V>::removeEdge(V v1, V v2){
    if(edgeExists(v1, v2)){
        graph[v1].erase(v2);
        graph[v2].erase(v1);
    }
    else cout << "Invalid vertices" << endl;
}

// Removes vertex from graph after removing edges
template<typename V>
void Graph<V>::removeVertex(V vert){
    if(vertexExists(vert)){
        for(graphType::iterator it = graph.begin(); it != graph.end(); ++it){
            if(edgeExists(*it, vert)){
                removeEdge(*it, vert);
            }
        }
        graph.erase(vert); //Removes a vertex completely
    }
    else cout << "Invalid vertex" << endl;
}

// Gets the list of edges from the vertex
template<typename V>
vector<V> Graph<V>::getAdjVertex(V vert){
    if(vertexExists(vert)){
        return graph[vert];
    }
    else cout << "Invalid vertex" << endl;
}

template<typename V>
bool Graph<V>::edgeExists(V v1, V v2){
    if(vertexExists(v1) && vertexExists(v2)){
        for(vector<V>::iterator it = graph[v1].begin(); it != graph[v1].end(); ++it){
            if(*it == v2){
                return true;
            }
        }
        return false;
    }
    // else
    if(!vertexExists(v1)) cout << "Invalid first vertex" << endl;
    if(!vertexExists(v2)) cout << "Invalid second vertex" << endl;
    return false;
}

template<typename V>
bool Graph<V>::vertexExists(V vert){
    if(graph.find(vert) == graph.end()) return false; //if vertex is not found while iterating thru map, vert does not exist
    return true; //Else, vertex does exist and return true.
}


int main(){
    // graph test;
    Graph<int> test;
    test.addVertex(1);
    test.addEdge()
    
    test[1].push_back(10);
    test[2].push_back(11);

    for(int i = 0; i<10; i++){
        test[1].push_back(i);
    }

    for(graph::iterator it = test.begin(); it != test.end(); ++it){
        cout << "Vertex node: " << it->first << endl;
        cout << "List of edges: " << endl;
        for(vector<int>::iterator itt = (it->second).begin(); itt != (it->second).end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
}