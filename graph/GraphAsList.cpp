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
    edges.resize(v);
}

void GraphAsList::readGraphFromFile(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::cout << name;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);

        int size, edgesNumber;
        int u, v, w;

        std::stringstream ss(line);
        ss >> size >> edgesNumber;

        vertices = size;
        edges.clear();

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
    edges.push_back({w, {u, v}});
}

void GraphAsList::display() {
    std::cout << "Graph as list:\n";
    for (auto edge : edges) {
        std::cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << std::endl;
    }
}

