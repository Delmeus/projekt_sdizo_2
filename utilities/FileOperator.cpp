//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include <sstream>
#include "FileOperator.h"
#include "fstream"
#include "random"

void FileOperator::randomizeFile(int size, double density) {

    std::ofstream file(R"(G:\projekt_SDiZO_2\files\graph.txt)");
    if(file.is_open()) {
        bool visited[size];
        for(int i = 0; i < size; i++) visited[i] = false;
        int vertex1, vertex2;
        if (density > 1) density = 1;
        int edges = floor(floor(size * (size - 1)) / 2 * density); //maksymalna ilosc krawedzi pomnzona przez gestosc
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> e(1, 9);
        std::uniform_int_distribution<> v(0, size - 1);
        file << size << " " << edges << " " << 0 << " " << size - 1 << "";

        //pierwsza krawedz, aby dodawanie kolejnych w petli wykonywalo sie prawidlowo
        vertex1 = 0;
        do {
            vertex2 = v(gen);
        } while (vertex2 == 0);

        file << "\n" << vertex1 << " " << vertex2 << " " << e(gen);
        visited[vertex1] = true;
        visited[vertex2] = true;


        for (int i = 1; i < size - 1; i++) {
            // Losuj krawędź do dodania do drzewa
            do {
                vertex1 = v(gen);
                vertex2 = v(gen);
            } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2])); // powtarzaj, jeśli wylosowano zły wierzchołek
            // Dodaj krawędź do drzewa

            visited[vertex1] = visited[vertex2] = true;
            file << "\n" << vertex1 << " " << vertex2 << " " << e(gen);
        }

        if(edges - size > 0) {
            for (int i = 0; i < edges - size; i++) {
                vertex1 = v(gen);
                vertex2 = v(gen);
                if (vertex1 == vertex2) i--;
                else file << "\n" << vertex1 << " " << vertex2 << " " << e(gen); //wygeneruj krawedz o losowej wadze
            }
        }

        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE\n";
}

GraphAsList FileOperator::readAsList(std::string s) {
    std::string name = R"(G:\projekt_SDiZO_2\files\)" + s;
    std::cout << "\n " << name;
    std::ifstream file(name);
    if(file.is_open()) {
        std::string line;
        std::getline(file, line);
        int size, edgesNumber;
        int u, v, w;
        std::stringstream ss(line);
        ss >> size >> edgesNumber;
        GraphAsList graph = *new GraphAsList(size);
        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        file.close();
        return graph;
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING THE FILE";
    return {0};
}
