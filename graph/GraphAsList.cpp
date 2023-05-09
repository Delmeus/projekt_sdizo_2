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
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::cout << "\nlista" << name;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        int size, edgesNumber;
        int u, v, w;
        std::stringstream ss(line);
        ss >> size >> edgesNumber;
        std::cout << "\njestem przed zmianami pol";
        vertices = size;
        edges.resize(vertices, std::vector<int>(vertices, std::numeric_limits<int>::max()));
        std::cout << "\njestem po zmianach pol";
        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            addEdge(u, v, w);
        }
        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING THE FILE";
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

