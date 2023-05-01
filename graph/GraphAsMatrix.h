//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_GRAPHASMATRIX_H
#define PROJEKT_SDIZO_2_GRAPHASMATRIX_H


class GraphAsMatrix {
private:
    int vertices; // liczba wierzchołków
    int **edges; // krawędzie grafu
public:
    GraphAsMatrix(int vertices);
    void readGraphFromFile();
    void addEdge(int u, int v, int w);
    void display();

};


#endif //PROJEKT_SDIZO_2_GRAPHASMATRIX_H
