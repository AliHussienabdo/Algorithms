#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
// #include "../../Linked_List/List.h"
using namespace std;

// template<typename TYPE>

class Graph{
public:
    Graph(int VNums){ // create a V-vertex graph with no edges

        this->NumVertices = VNums;
        this->graph.resize(NumVertices);
        // for(int i=0; i<this->NumVertices; ++i){
        //     this->graph.push(new List<int>());
        // }
    }
    void addEdge(int V, int W){
        this->graph[V].push_back(W);
        this->graph[W].push_back(V);
        ++NumEdges;
    }
    vector<int> getAdj(int v) { // vertices adjacent to v
        return this->graph[v];
    }
    // string toString() const; // string representation of the graph
    int numberOFVertices() { return NumVertices;}
    int numberOfEdges() { return NumEdges;}
    ~Graph(){
        // destractor
    }
private:
    int NumVertices = 0;   // number of vertices
    int NumEdges = 0; // number of edges
    vector<vector<int>> graph;
};

#endif