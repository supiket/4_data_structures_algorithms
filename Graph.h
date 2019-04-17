#ifndef PROJECT4_GRAPH_H
#define PROJECT4_GRAPH_H
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Graph{



public:

    vector<pair<int,int>>* adjList;
    int rows;
    int columns;
    int size;
    Graph(int rows, int columns);
    void edge(int u, int v, int heightDifference);
    int dijkstra(int source, int destination);
    ~Graph() {
        delete adjList;
    }
    int optimalCost(int source, int destination);

};



#endif //PROJECT4_GRAPH_H


