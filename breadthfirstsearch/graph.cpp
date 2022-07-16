#include "graph.h"

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
        for(typename map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
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

// Check if edge exists between two vertices
template <typename V>
bool Graph<V>::edgeExists(V v1, V v2){
    if(vertexExists(v1) && vertexExists(v2)){
        for(typename vector<V>::iterator it = graph[v1].begin(); it != graph[v1].end(); ++it){
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

// Checks if vertex already exists in graph
template<typename V>
bool Graph<V>::vertexExists(V vert){
    if(graph.find(vert) == graph.end()) return false; //if vertex is not found while iterating thru map, vert does not exist
    return true; //Else, vertex does exist and return true.
}

template<typename V>
map<V, vector<V>> Graph<V>::getGraph(){return graph;}

// Prints entire graph with vertices and edges
template<typename V>
void Graph<V>::printGraph(){
    for(typename map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
        cout << "Vertex node: " << it->first << endl;
        cout << "List of adjacent vertices: " << endl;
        for(typename vector<V>::iterator itt = (it->second).begin(); itt != (it->second).end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
}

// Prints list of adjacent vertices associated with a vertex
template<typename V>
void Graph<V>::printAdjVertices(V vert){
    cout << "Vertex: " << vert << endl;
    cout << "List of adjacent vertices: ";
    for(typename vector<V>::iterator it = graph[vert].begin(); it != graph[vert].end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

Graph<int> exampleGraph(){
    // graph test;
    Graph<int> test(0);
    // test.addVertex(1); //Should result in error as vertex already exists
    // test.addVertex(2);

    for(int i = 1; i<8; i++){
        test.addVertex(i);
    }

    test.addEdge(0,2);
    test.addEdge(0,4);
    test.addEdge(1,2);
    test.addEdge(1,7);
    test.addEdge(2,1); // Should print edge exists already
    test.addEdge(2,3);
    test.addEdge(2,4);
    test.addEdge(2,0); //alr
    test.addEdge(2,6);
    test.addEdge(3,2); // Should print edge exists alr
    test.addEdge(3,5);
    test.addEdge(4,0); //edge alr
    test.addEdge(4,2); //alr
    test.addEdge(4,5);
    test.addEdge(5,4); //edge alr
    test.addEdge(5,3); //alr
    test.addEdge(5,6);
    test.addEdge(6,5); //alr
    test.addEdge(6,7);
    test.addEdge(6,2); //alr
    test.addEdge(7,1); //alr
    test.addEdge(7,6); //alr

    test.printGraph();
    return test;
}

// int main(){
//     Graph<int> g = exampleGraph();
//     map<int, vector<int>> gg = g.getGraph();
//     cout << gg[0].front() << endl;
// }