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
    if(vertexExists(vert) == graph.end()){ // Checks if vertex does not exist within graph
        graph[vert];
        return;
    }
    else{cout << "Vertex already exists. No duplicates may be made." << endl;}
}

// Adds edge (connects 2 vertices)
template<typename V>
void Graph<V>::addEdge(V v1, V v2){
    if((vertexExists(v1) != graph.end()) && (vertexExists(v2) != graph.end())){ // Checks if both vertices are valid
        if(edgeExists(v1, v2) != graph[v1].end()){ // Checks if an edge already established between vertices
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
void Graph<V>::removeEdge(V v1, V v2){ //iterator to whatever is v1 and v2 is vert specified in remove
    // cout << "Gets in removeEdge" << endl;
    typename vector<V>::iterator edge_v1 = edgeExists(v1, v2);
    typename vector<V>::iterator edge_v2 = edgeExists(v2, v1);
    cout << *edge_v1 << ", " << *edge_v2 << endl;
    if(edge_v1 != graph[v1].end()){ // makes sure the iterator edge_v1 is not at the end. If not at end, implies the edge exists as well so no need to check v2
        graph[v1].erase(edge_v2);
        graph[v2].erase(edge_v1);
    }
    else cout << "Invalid vertices" << endl;
}

// Removes vertex from graph after removing adjacent vertices edge connections to vertex
template<typename V>
void Graph<V>::removeVertex(V vert){
    if(vertexExists(vert) != graph.end()){
        typename vector<V>::iterator vert_in_edge;
        // Loops through each vertex in the list and checks if there exists an edge with vertex. Remove edge if so.
        for(typename unordered_map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
            vert_in_edge = edgeExists(vert, it->first);
            if(vert_in_edge != graph[vert].end()){ //checks if key at iterator (vertex) exists in the list of vertices in vert
                graph[it->first].erase(vert_in_edge);
            }
        }
        graph.erase(vertexExists(vert)); //Removes a vertex completely
    }
    else cout << "Invalid vertex" << endl;
}

// Check if edge exists between two vertices
template <typename V>
typename vector<V>::iterator Graph<V>::edgeExists(V v1, V v2){
    if((vertexExists(v1) != graph.end()) && (vertexExists(v2) != graph.end())){
        for(typename vector<V>::iterator it = graph[v2].begin(); it != graph[v2].end(); ++it){
            if(*it == v1){
                return it;
            }
        }
        return graph[v1].end();
    }
    // else
    if(vertexExists(v1) == graph.end()) cout << "Invalid first vertex" << endl;
    if(vertexExists(v2) == graph.end()) cout << "Invalid second vertex" << endl;
    return graph[v1].end();
}

// Checks if vertex already exists in graph
template<typename V>
typename unordered_map<V, vector<V>>::iterator Graph<V>::vertexExists(V vert){
    typename unordered_map<V, vector<V>>::iterator it = graph.find(vert);
    if(graph.find(vert) == graph.end()) return graph.end(); //if vertex is not found while iterating thru map, vert does not exist
    return it; //Else, vertex does exist and return true.
}
// Gets the list of edges from the vertex
template<typename V>
vector<V> Graph<V>::getAdjVertex(V vert){
    if(vertexExists(vert) != graph.end()){
        return graph[vert];
    }
    else cout << "Invalid vertex" << endl;
}

template<typename V>
unordered_map<V, vector<V>>& Graph<V>::getGraph(){
    return graph;
}

// Prints entire graph with vertices and edges
template<typename V>
void Graph<V>::printGraph(){
    for(typename unordered_map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
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

    // test.printGraph();
    return test;
}

void print(string p){
    cout << p << endl;
}

int main(){
    Graph<int> g = exampleGraph();
    unordered_map<int, vector<int>> gg = g.getGraph();
    g.printGraph();

    // vector<int> adj2 = g.getAdjVertex(2);
    // print("Printing adj2: ");
    // for(vector<int>::iterator it = adj2.begin(); it != adj2.end(); ++it){
    //     cout << *it << " ";
    // }
    // print("Printing adj2 using function class: ");
    // g.printAdjVertices(2);
    unordered_map<int, vector<int>>::iterator vert2 = g.vertexExists(82);
    // vector<int>::iterator edge02 = g.edgeExists(8, 15);
    
    if(vert2 == g.graph.end()) cout << "tuff" << endl;
    else cout << "hm " << vert2->first << endl;
    
    // cout << vert2->first << endl;
    
    cout << "Deleted Vertex 2"<< endl;
    g.removeVertex(8);
    g.printGraph();
}