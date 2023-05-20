//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_GRAPHASMATRIX_H
#define PROJEKT_SDIZO_2_GRAPHASMATRIX_H


#include <string>

class GraphAsMatrix {
private:
public:
    int **edges; // krawędzie grafu
    int vertices; // liczba wierzchołków
    GraphAsMatrix(int v);
    void readGraphUndirected(std::string s);
    void readGraphDirected(std::string s);
    void addEdge(int u, int v, int w);
    void display() const;

    virtual ~GraphAsMatrix();

};


#endif //PROJEKT_SDIZO_2_GRAPHASMATRIX_H
