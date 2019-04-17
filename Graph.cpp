#include "Graph.h"

Graph::Graph(int rows, int columns) {
    if (rows>0 && columns>0) {
        this->rows = rows;
        this->columns = columns;
        this->size=rows*columns;
        adjList = new vector<pair<int, int>>[size+1];
    }
}

void Graph::edge(int u,int v,int heightDifference) {
    adjList[u].emplace_back(make_pair(v, heightDifference));
    adjList[v].emplace_back(make_pair(u, heightDifference));
}

int Graph::dijkstra(int source, int destination){

    unordered_map<int,int> costMap;

    for(int i=0; i<=size; i++){
        costMap[i] = INT_MAX;
    }

    set<pair<int, int>> distanceSet;

    costMap[source] = 0;
    distanceSet.insert(make_pair(source,0));

    while(!distanceSet.empty()){
        pair<int,int> firstPair = *(distanceSet.begin());
        int node = firstPair.first;
        int nodeCost = firstPair.second;
        distanceSet.erase(distanceSet.begin());

        for (pair<int, int> neighbourPair: adjList[node]){

            if(max(nodeCost, neighbourPair.second) < costMap[neighbourPair.first]){

                int destination = neighbourPair.first;
                auto temp = distanceSet.find(make_pair(destination, costMap[destination]));
                if(temp!=distanceSet.end()){
                    distanceSet.erase(temp);
                }

                costMap[destination] = max(nodeCost, neighbourPair.second);
                distanceSet.insert(make_pair(destination, costMap[destination]));

            }
        }
    }

    return costMap[destination];

}

int Graph::optimalCost(int source, int destination) {
    return dijkstra(source, destination);
}
