//
// Created by Antek on 01.05.2023.
//

#include "GraphAsMatrix.h"
#include "sstream"
#include "fstream"
#include "iostream"
#include "iomanip"

GraphAsMatrix::GraphAsMatrix(int vertices){
    this->vertices = vertices;

}

void GraphAsMatrix::readGraphFromFile() {
    std::ifstream file("G:/projekt_SDiZO_2/files/graph.txt");
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        int edgesNumber;
        int u, v, w;
        std::stringstream ss(line);
        ss >> vertices >> edgesNumber;

        edges = new int * [vertices];
        for(int i=0; i<vertices; ++i) edges[i] = new int[vertices];

        for(int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                edges[i][j] = 0;
            }
        }

        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            edges[u][v] = w;
        }
        file.close();
    }
}

void GraphAsMatrix::addEdge(int u, int v, int w) {

}

void GraphAsMatrix::display() {
    const int fieldWidth = 4; // szerokość pola wyświetlania

// wyświetlanie nagłówków kolumn
    std::cout << std::setw(fieldWidth) << " " << " | ";
    for (int j = 0; j < vertices; j++) {
        std::cout << std::setw(fieldWidth) << j << " ";
    }
    std::cout << std::endl;

// wyświetlanie linii separatora
    std::cout << std::setfill('-') << std::setw(fieldWidth + 1) << "" << "+" << std::setw((fieldWidth + 1) * vertices) << "" << std::setfill(' ') << std::endl;

// wyświetlanie zawartości tablicy
    for (int i = 0; i < vertices; i++) {
        std::cout << std::setw(fieldWidth) << i << " | ";
        for (int j = 0; j < vertices; j++) {
            std::cout << std::setw(fieldWidth) << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
