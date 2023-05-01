//
// Created by Antek on 29.04.2023.
//

#ifndef PROJEKT_SDIZO_2_GRAPHASLIST_H
#define PROJEKT_SDIZO_2_GRAPHASLIST_H
#include "algorithm"
#include "vector"


class GraphAsList {
private:
    int vertices; // liczba wierzchołków
    std::vector<std::pair<int, std::pair<int, int>>> edges; // krawędzie grafu: waga, {wierzchołek, wierzchołek}
public:
    void readGraphFromFile();
    void addEdge(int u, int v, int w);
    void display();

    explicit GraphAsList(int v);
};


#endif //PROJEKT_SDIZO_2_GRAPHASLIST_H
