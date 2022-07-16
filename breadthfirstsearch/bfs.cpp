// Program to practice using the breadth-first search algorithm
// Use of Queue data structure and Graph using adjacency list (list of linked list)

#include "graph.h"
#include <math.h>
#include <queue>
#include <set>

template<typename V>
void BFSAlgo(Graph<V> g, V start){
    map<V, vector<V>> graph = g.graph;
    
    map<V, pair<V, int>> search;

    for(typename map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
        search[it->first] = make_pair(0,INFINITY);
    }
    queue<V>* bfsq = new queue<V>;
    bfsq->push(start);
    search[start].second = 0; 
    V currVertex = start;
    while(!bfsq->empty()){
        currVertex = bfsq->front();
        bfsq->pop();
        for(typename vector<V>::iterator it = graph[currVertex].begin(); it != graph[currVertex].end(); ++it){
            if(search[*it].first == 0){
                bfsq->push(*it);
                search[*it].first = currVertex;
                search[*it].second = search[currVertex].second + 1;
            }
        }
    }

    for(typename map<V, pair<V, int>>::iterator it = search.begin(); it != search.end(); ++it){
        cout << "Vertex: " << it->first << endl;
        cout << "Predecessor: " << (it->second).first << endl;
        cout << "Distance from start vertex: " << (it->second).second << endl;
    }

}

int main(){
    Graph<int> g = exampleGraph();
    BFSAlgo(g, 0);
}
