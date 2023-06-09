//
// Created by Antek on 01.05.2023.
//

#include "GraphAsMatrix.h"
#include "sstream"
#include "fstream"
#include "iostream"
#include "iomanip"

GraphAsMatrix::GraphAsMatrix(int v){
    vertices = v;
    edges = new int * [vertices];
    for(int i = 0; i < vertices; ++i) edges[i] = new int[vertices];

    for(int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            edges[i][j] = INT_MAX;
        }
    }
}

GraphAsMatrix::~GraphAsMatrix() {
    if(vertices > 0) {
        for (int i = 0; i < vertices; i++) {
            delete[] edges[i];
            edges[i] = nullptr;
        }
        delete[] edges;
        edges = nullptr;
    }
}

void GraphAsMatrix::readGraphUndirected(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        int edgesNumber;
        int u, v, w;
        std::stringstream ss(line);

        if (edges != nullptr && vertices > 0) {
            for(int i = 0; i < vertices; i++) {
                delete[] edges[i];
                edges[i] = nullptr;
            }
            delete[] edges;
            edges = nullptr;
        }

        ss >> vertices >> edgesNumber;
        edges = new int * [vertices];
        for(int i = 0; i < vertices; ++i) edges[i] = new int[vertices];

        for(int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                edges[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            if(edges[u][v] > w) {
                edges[u][v] = w;
                edges[v][u] = w;
            }
            if(edges[v][u] > w){
                edges[u][v] = w;
                edges[v][u] = w;
            }
        }
        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE";
}


void GraphAsMatrix::readGraphDirected(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        int edgesNumber;
        int u, v, w;
        std::stringstream ss(line);

        if (edges != nullptr && vertices > 0) {
            for(int i = 0; i < vertices; i++) {
                delete[] edges[i];
                edges[i] = nullptr;
            }
            delete[] edges;
            edges = nullptr;
        }

        ss >> vertices >> edgesNumber;
        edges = new int * [vertices];
        for(int i = 0; i < vertices; ++i) edges[i] = new int[vertices];

        for(int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                edges[i][j] = INT_MAX;
            }
        }

        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            if(edges[u][v] > w) {
                edges[u][v] = w;

            }
        }
        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE";
}

void GraphAsMatrix::display() const{
    // szerokość pola wyświetlania
    const int fieldWidth = 4;
    std::cout << "Graph as matrix" << std::endl;

    // wyswietlanie naglowkow kolumn
    std::cout << std::setw(fieldWidth) << " " << " | ";
    for (int j = 0; j < vertices; j++) {
        std::cout << std::setw(fieldWidth) << j << " ";
    }
    std::cout << std::endl;

    // wyswietlanie linii separatora
    std::cout << std::setfill('-') << std::setw(fieldWidth + 1) << "" << "+" << std::setw((fieldWidth + 1) * vertices) << "" << std::setfill(' ') << std::endl;

    // wyswietlanie zawartosci tablicy
    for (int i = 0; i < vertices; i++) {
        std::cout << std::setw(fieldWidth) << i << " | ";
        for (int j = 0; j < vertices; j++) {
            if(edges[i][j] == INT_MAX )
                std::cout << std::setw(fieldWidth) << "-" << " ";
            else
                std::cout << std::setw(fieldWidth) << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
