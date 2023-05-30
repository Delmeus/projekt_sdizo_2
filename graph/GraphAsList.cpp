//
// Created by Antek on 29.04.2023.
//

#include <iostream>
#include "GraphAsList.h"
#include "fstream"
#include <sstream>
#include <limits>


void GraphAsList::readGraphUndirected(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);

        int size, edgesNumber;
        int u, v, w;

        std::stringstream ss(line);
        ss >> size >> edgesNumber;

        //edges.clear();
        for(int i = 0; i < vertices; i++){
            adjList[i].clear();
        }
        adjList.clear();
        vertices = size;
        adjList.resize(size);

        for(int i = 0; i < edgesNumber; i++){
                std::getline(file, line);
                std::stringstream info(line);
                info >> u >> v >> w;
                //addEdge(u, v, w);
                adjList[u].emplace_back(v,w);
                adjList[v].emplace_back(u,w);
            }
        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING THE FILE";
}

void GraphAsList::readGraphDirected(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);

        int size, edgesNumber;
        int u, v, w;

        std::stringstream ss(line);
        ss >> size >> edgesNumber;

        //edges.clear();
        for(int i = 0; i < vertices; i++){
            adjList[i].clear();
        }
        adjList.clear();
        vertices = size;
        adjList.resize(size);

        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            printf("iteration: %d, u: %d, v: %d, w: %d\n",i, u, v, w);
            adjList[u].emplace_back(v,w);
        }
        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING THE FILE";
}

void GraphAsList::addEdge(int u, int v, int w) {
//    edges.push_back({w, {u, v}});
    adjList[u].emplace_back(v,w);
    adjList[v].emplace_back(u,w);
}

void GraphAsList::display() {
    cout << "Graph as list:" << endl;
//    for (auto edge : edges) {
//        std::cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << std::endl;
//    }
    for (int i = 0; i < adjList.size(); ++i) {
        std::cout << "List " << i << ": ";
        for (const auto& vertex : adjList[i]) {
            int dest = vertex.first;
            int weight = vertex.second;
            std::cout << "(" << dest << ", " << weight << ") ";
        }
        std::cout << std::endl;
    }
}


