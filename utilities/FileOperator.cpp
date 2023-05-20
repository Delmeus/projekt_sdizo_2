//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include <sstream>
#include "FileOperator.h"
#include "fstream"
#include "random"

struct Edge {
    int source;
    int target;
    int weight;
};

//funkcja do losowania grafu nieskierowanego pelnego
void FileOperator::randomizeUndirected(int size, double density) {

    std::ofstream file(R"(G:\projekt_SDiZO_2\files\graphU.txt)");

    int edges = floor(floor(size * (size - 1)) / 2 * density);

    if(file.is_open()) {
        if (edges > size * (size - 1) / 2) {
            std::cout << "Nieprawidłowa liczba krawędzi." << std::endl;
            return;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> weightDist(1, 9);
        std::uniform_int_distribution<> vertexDist(0, size - 1);

        std::vector<Edge> graph;
        std::vector<std::vector<bool>> adjacencyMatrix(size, std::vector<bool>(size, false));

        // Generowanie krawedzi
        int generatedEdges = 0;
        while (generatedEdges < edges) {
            int source = vertexDist(gen);
            int target = vertexDist(gen);
            if (source != target && !adjacencyMatrix[source][target]) {
                graph.push_back({source, target, weightDist(gen)});
                adjacencyMatrix[source][target] = adjacencyMatrix[target][source] = true;
                generatedEdges++;
            }
        }

        //Zapisz graf do pliku
        file << size << " " << edges << " " << 0 << " " << size - 1 << std::endl;
        for (const auto& edge : graph) {
            file << edge.source << " " << edge.target << " " << edge.weight << std::endl;
        }

        file.close();
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE\n";
}

void FileOperator::randomizeDirected(int size, double density) {
    std::ofstream file(R"(G:\projekt_SDiZO_2\files\graphD.txt)");

    if (!file.is_open()) {
        std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDist(0, 9);

    //maksymalna liczba krawedzi
    int edges = size * (size - 1);

    file << size << " " << edges << " " << 0 << " " << size - 1 << std::endl;

    for (int u = 0; u < size; u++) {
        for (int v = 0; v < size; v++) {
            if (u != v) {
                //Sprawdzenie czy generujemy kolejna krawedzi
                double random = static_cast<double>(rand()) / RAND_MAX;
                if (random <= density) {
                    int weight = weightDist(gen);
                    file << u << " " << v << " " << weight << std::endl;
                }
            }
        }
    }

    file.close();
}

FileOperator::FileOperator() = default;
