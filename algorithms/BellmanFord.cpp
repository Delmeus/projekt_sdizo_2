//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "BellmanFord.h"

void BellmanFord::forList(GraphAsList &g, int source) {
    //int numEdges = g.adjList.size();

    std::vector<int> distance(g.vertices, INT_MAX);
    distance[source] = 0;

    //Relaksujemy krawedzie V - 1 razy
    for (int j = 0; j < g.vertices; ++j) {
        for (const auto& edge : g.adjList[j]) {
            int u = j;
            int v = edge.first;
            int weight = edge.second;

            if(distance[u] == INT_MAX)
                break;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }
    
    std::cout << "Vertex \t Distance from " << source << std::endl;
    for(int i = 0; i < g.vertices; i++){
        if(distance[i] != INT_MAX)
            std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
        else
            std::cout << "  " << i << " \t\t" << "-" << std::endl;
    }
}

void BellmanFord::forMatrix(GraphAsMatrix &g) {

}
