// Program to practice using the breadth-first search algorithm
// Use of Queue data structure and Graph using unordered map (hash-table) for O(1) lookup.

#include "graph.h"
#include <math.h>
#include <queue>

// BFS Algorithm function
template<typename V>
void BFSAlgo(Graph<V> g, V &start){
    unordered_map<V, vector<V>> graph = g.graph;
    unordered_map<V, pair<bool, int>> search;
    unordered_map<V, V> pred; // Predecessor

    // Sets each vertex to false and depth of -1 to indicate not visited yet and start of search
    for(typename unordered_map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
        search[it->first] = make_pair(false,-1);
    }
    
    queue<V>* bfsq = new queue<V>; // Initializes queue for BFS
    bfsq->push(start); 
    search[start] = make_pair(true, 0); //sets first vertex to true to indicate visited vertex with distance of 0
    pred[start] = NULL; // No predecessor at start vertex
    V currVertex; // Initializes current vertex in the search

    // While the BFS queue is not empty (should never be empty until the last vertex is completed)
    while(!bfsq->empty()){
        // Sets the first value in the BFS queue as the current vertex to search and remove from queue
        currVertex = bfsq->front(); 
        bfsq->pop();

        // Iterates through each adjacent vertex in the vertex's list of edges
        for(typename vector<V>::iterator it = graph[currVertex].begin(); it != graph[currVertex].end(); ++it){
            if(search[*it].first == false){ //want to check if the vertex has not been marked (marked/true indicates a visited vertex already)
                bfsq->push(*it); // Adds each adj vertex to queue
                search[*it] = make_pair(true, search[currVertex].second + 1); //Sets as true to indicate the node has been visited and increase depth by 1 to indicate distance from start vertex
                pred[*it] = currVertex; // Stores predecessor vertex
            } 
        }
    }

    delete bfsq; // Deallocates bfsq queue from heap

    // Iterates through each vertex to print its predecessor and distance from start vertex
    for(typename unordered_map<V, pair<bool, int>>::iterator it = search.begin(); it != search.end(); ++it){
        cout << "Vertex: " << it->first << endl;
        cout << "Predecessor: " << pred[it->first] << endl;
        cout << "Distance from start vertex: " << (it->second).second << endl;
    }

}

int main(){
    Graph<int> g = exampleGraph();
    unordered_map<int, vector<int>> test = g.graph;
    unordered_map<int, vector<int>>::iterator itt = g.graph.find(0);
    int start = itt->first;
    BFSAlgo(g, start);
}
