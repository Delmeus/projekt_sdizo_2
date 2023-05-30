//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "BellmanFord.h"

void BellmanFord::forList(GraphAsList &g, int source, bool print) {
    std::vector<int> distance(g.vertices, INT_MAX);
    distance[source] = 0;

    //Relaksujemy krawedzie V - 1 razy
    for (int i = 0; i < g.vertices - 1; ++i) {
        for (int u = 0; u < g.vertices; ++u) {
            for (const auto& edge : g.adjList[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    //sprawdzamy czy nie ma ujemnych cykli
    for (int i = 0; i < g.vertices; ++i) {
        for (const auto &edge: g.adjList[i]) {
            int u = i;
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                std::cout << "Graph contains negative-weight cycle!" << std::endl;
                return;
            }
        }
    }

    if(print) {
        std::cout << "Vertex \t Distance from " << source << std::endl;
        for (int i = 0; i < g.vertices; i++) {
            if (distance[i] != INT_MAX)
                std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
            else
                std::cout << "  " << i << " \t\t" << "-" << std::endl;
        }
    }
}

void BellmanFord::forMatrix(GraphAsMatrix &g, int source, bool print) {
    std::vector<int> distance(g.vertices, INT_MAX);
    distance[source] = 0;

    //Relaksujemy krawedzie V - 1 razy
    for (int i = 1; i < g.vertices; ++i) {
        for (int u = 0; u < g.vertices; ++u) {
            for (int v = 0; v < g.vertices; ++v) {
                if (distance[u] != INT_MAX && g.edges[u][v] != INT_MAX &&
                    distance[u] + g.edges[u][v] < distance[v]) {
                    distance[v] = distance[u] + g.edges[u][v];
                }
            }
        }
    }

    for (int u = 0; u < g.vertices; ++u) {
        for (int v = 0; v < g.vertices; ++v) {
            if (distance[u] != INT_MAX && g.edges[u][v] != INT_MAX &&
            distance[u] + g.edges[u][v] < distance[v]) {
                std::cout << "Graph contains negative-weight cycle" << std::endl;
                return;
            }
        }
    }

    if(print) {
        std::cout << "Vertex \t Distance from " << source << std::endl;
        for (int i = 0; i < g.vertices; ++i) {
            if (distance[i] != INT_MAX)
                std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
            else
                std::cout << "  " << i << " \t\t" << "-" << std::endl;
        }
    }
}
