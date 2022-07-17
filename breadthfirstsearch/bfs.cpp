// Program to practice using the breadth-first search algorithm
// Use of Queue data structure and Graph using adjacency list (list of linked list)

#include "graph.h"
// #include <utility>
#include <math.h>
#include <queue>
#include <set>

template<typename V>
void BFSAlgo(Graph<V> g, V &start){
    map<V, vector<V>> graph = g.graph;
    map<V, pair<V*, int>> search;

    for(typename map<V, vector<V>>::iterator it = graph.begin(); it != graph.end(); ++it){
        search[it->first] = make_pair(nullptr,-1);
        cout << &(it->first) << endl;
    }
    queue<V>* bfsq = new queue<V>;
    bfsq->push(start);
    search[start].second = 0; 
    V* currVertex;
    while(!bfsq->empty()){
        currVertex = &(bfsq->front());
        cout << "Ver: " << *currVertex << endl;
        bfsq->pop();

        for(typename vector<V>::iterator it = graph[*currVertex].begin(); it != graph[*currVertex].end(); ++it){
            cout << "AH: " << (search[*it]).first << endl;
            if(search[*it].first == nullptr){
                cout << "In" << endl;
                bfsq->push(*it);
                search[*it].first = currVertex;
                cout << "Ver 1: " << *currVertex << endl;
                search[*it].second = search[*currVertex].second + 1;
            } 
        }
    }

    delete bfsq;

    for(typename map<V, pair<V*, int>>::iterator it = search.begin(); it != search.end(); ++it){
        cout << "Vertex: " << it->first << endl;
        cout << "Predecessor: " << *(it->second).first << endl;
        cout << "Distance from start vertex: " << (it->second).second << endl;
    }

}

int main(){
    Graph<int> g = exampleGraph();
    map<int, vector<int>>::iterator it = g.graph.begin();
    int start = it->first;
    BFSAlgo(g, start);
    // search[1] = make_pair(NULL, 0);
    // search[0] = make_pair(NULL, 0);
}
