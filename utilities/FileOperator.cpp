//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include <sstream>
#include <queue>
#include "FileOperator.h"
#include "fstream"
#include "random"
#include "vector"

struct Edge {
    int source;
    int target;
    int weight;
};

//funkcja do losowania grafu nieskierowanego pelnego
void FileOperator::randomizeUndirected(int size, double density) {

    std::ofstream file(R"(G:\projekt_SDiZO_2\files\graphU.txt)");

    int edges = floor(floor(size * (size - 1)) / 2 * density);

    if(edges < size - 1){
        edges = size - 1;
        std::cout << std::endl
                  << "Density was to small to fit a connected graph, expanded number of edges to "
                  << edges << std::endl;
    }

    if(file.is_open()) {

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

    int edges = floor(floor(size * (size - 1)) * density);

    if(edges < size - 1){
        edges = size - 1;
        std::cout << std::endl
        << "Density was to small to fit a connected graph, expanded number of edges to "
        << edges << std::endl;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> probDist(0.0, 1.0);
    std::uniform_int_distribution<> weightDist(1, 9);
    std::uniform_int_distribution<> vertexDist(0, size - 1);

    file << size << " " << edges << " " << 0 << " " << size - 1 << std::endl;

    //jezeli graf jest pelny do generujemy kolejno krawedzie
    //z losowymi wagami aby usprawnic szybkosc generowania
    if (edges == size * (size - 1)) {
        for (int u = 0; u < size; u++) {
            for (int v = 0; v < size; v++) {
                if (u != v) {
                    file << u << " " << v << " " << weightDist(gen);
                }
            }
        }
    }

    else {

        int connected[size];
        bool visited[size];
        int vertex1 = 0, vertex2;

        do {
            vertex2 = vertexDist(gen);
        } while (vertex2 == 0);

        file << vertex1 << " " << vertex2 << " " << weightDist(gen);
        visited[vertex1] = true;
        visited[vertex2] = true;
        connected[vertex1] = vertex2;

        //generujemy drzewo spinajace
        for (int i = 1; i < size - 1; i++) {
            do {
                vertex1 = vertexDist(gen);
                vertex2 = vertexDist(gen);
            } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2]));
            connected[vertex1] = vertex2;
            visited[vertex1] = true;
            visited[vertex2] = true;
            file << "\n" << vertex1 << " " << vertex2 << " " << weightDist(gen);
        }
        
        //jesli brakuje krawedzi do generujemy dodatkowe
        if(edges > size - 1) {
            int count = size - 1;
            for (int u = 0; u < size - 1 && count < edges; u++) {
                for (int v = u + 1; v < size && count < edges; v++) {
                    double random = probDist(gen);
                    if (random <= density) {
                        if (connected[u] != v) {
                            int weight = weightDist(gen);
                            count++;
                            file << u << " " << v << " " << weight << std::endl;
                        } else v--;
                    }
                }
            }
        }
    }
    file.close();
}

FileOperator::FileOperator() = default;
