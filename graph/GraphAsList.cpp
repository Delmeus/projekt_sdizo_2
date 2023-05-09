//
// Created by Antek on 29.04.2023.
//

#include <iostream>
#include "GraphAsList.h"
#include "fstream"
#include <sstream>
#include <limits>

GraphAsList::GraphAsList(int v) {
    vertices = v;
    edges.resize(v, std::vector<int>(v, std::numeric_limits<int>::max()));
}

void GraphAsList::readGraphFromFile(std::string s) {

}

void GraphAsList::addEdge(int u, int v, int w) {
    edges[u][v] = w;
}

void GraphAsList::display() {
    std::cout << "Graph as list:\n";
    for (int u = 0; u < vertices; u++)
        for(int v = 0; v < vertices; v++)
            if(edges[u][v] != INT_MAX)
                std::cout << u << " - " << v << " | weight = " << edges[u][v] << std::endl;
}

