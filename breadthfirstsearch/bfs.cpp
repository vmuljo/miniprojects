// Program to practice using the breadth-first search algorithm
// Use of Queue data structure and Graph using adjacency list (list of linked list)

#include "graph.h"
// #include <utility>
#include <math.h>
#include <queue>
#include <set>

template<typename V>
void BFSAlgo(Graph<V> g, V &start){
    unordered_map<V, vector<V>> graph = g.graph;
    unordered_map<V, pair<bool, int>> search;
    unordered_map<V, V> pred; // Predecessor

    // Sets each vertex to false and depth of -1 to indicate not visited yet and start of search
    for(typename unordered_map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
        search[it->first] = make_pair(false,-1);
    }
    queue<V>* bfsq = new queue<V>;
    bfsq->push(start);
    search[start] = make_pair(true, 0); //sets first vertex to true to indicate visited vertex
    pred[start] = NULL;
    V currVertex;
    while(!bfsq->empty()){
        currVertex = bfsq->front();
        bfsq->pop();
        for(typename vector<V>::iterator it = graph[currVertex].begin(); it != graph[currVertex].end(); ++it){
            if(search[*it].first == false){ //want to check if in list or not
                bfsq->push(*it); // Adds each adj vertex to queue
                search[*it].first = true; //Sets as true to indicate the node has been visited
                search[*it].second = search[currVertex].second + 1;
                pred[*it] = currVertex;
            } 
        }
    }

    delete bfsq;

    for(typename unordered_map<V, pair<bool, int>>::iterator it = search.begin(); it != search.end(); ++it){
        cout << "Vertex: " << it->first << endl;
        cout << "Predecessor: " << pred[it->first] << endl;
        cout << "Distance from start vertex: " << (it->second).second << endl;
    }

}

int main(){
    Graph<int> g = exampleGraph();
    // vector<int> t = g.getAdjVertex(0);
    unordered_map<int, vector<int>> test = g.graph;
    // g.removeVertex(2);
    unordered_map<int, vector<int>>::iterator it = g.graph.begin();
    int start = it->first;
    BFSAlgo(g, start);
}
