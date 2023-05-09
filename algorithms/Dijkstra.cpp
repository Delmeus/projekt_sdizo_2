//
// Created by Antek on 01.05.2023.
//

#include "Dijkstra.h"
#include "iostream"

void Dijkstra::forList(GraphAsList g) {

}

void Dijkstra::forMatrix(GraphAsMatrix g, int beginning) {
    int distance[g.vertices];

    bool pathSet[g.vertices];

    for(int i = 0; i < g.vertices; i++){
        distance[i] = INT_MAX, pathSet[i] = false;
    }

    distance[beginning] = 0;

    for(int count = 0; count < g.vertices - 1; count++){
        int u = minDistance(distance, pathSet, g);

        pathSet[u] = true;

        for(int v = 0; v < g.vertices; v++){
            if(!pathSet[v] && g.edges[u][v] && distance[u] != INT_MAX
               && distance[u] + g.edges[u][v] < distance[v]){
                distance[v] = distance[u] + g.edges[u][v];
            }
        }
    }

    std::cout << "Vertex \t Distance from " << beginning << std::endl;
    for(int i = 0; i < g.vertices; i++){
        std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
    }

}

int Dijkstra::minDistance(int *distance, bool *pathSet, GraphAsMatrix g) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < g.vertices; v++){
        if(pathSet[v] == false && distance[v] <= min){
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}