//
// Created by Antek on 29.04.2023.
//

#ifndef PROJEKT_SDIZO_2_GRAPHASLIST_H
#define PROJEKT_SDIZO_2_GRAPHASLIST_H
#include "algorithm"
#include "vector"
#include <string>
#include "list"

using namespace std;

class GraphAsList {
public:
    int vertices; // liczba wierzchołków
    std::vector<std::pair<int, std::pair<int,int>>> edges;

    vector<list<pair<int, int>>> adjList;


    void readGraphUndirected(std::string s);
    void readGraphDirected(std::string s);
    void addEdge(int u, int v, int w);
    void display();

    GraphAsList(int numVertices) : vertices(numVertices), adjList(numVertices) {}
};


#endif //PROJEKT_SDIZO_2_GRAPHASLIST_H
