//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include <sstream>
#include <queue>
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
    std::uniform_int_distribution<> weightDist(1, 9);
    std::uniform_int_distribution<> vertexDist(0, size - 1);

    //liczba krawedzi
    int edges = floor(floor(size * (size - 1)) * density);

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
        bool exists[size][size];
        bool visited[size];
        int count = 0, vertex1 = 0, vertex2;

        do {
            vertex2 = vertexDist(gen);
        } while (vertex2 == 0);

        file << vertex1 << " " << vertex2 << " " << weightDist(gen);
        visited[vertex1] = true;
        visited[vertex2] = true;
        //notujemy, ze polaczenie istnieje
        exists[vertex1][vertex2] = true;
        count++;

        for (int i = 1; i < size - 1; i++) {
            // Losuj krawędź do dodania do drzewa spinajacego
            do {
                vertex1 = vertexDist(gen);
                vertex2 = vertexDist(gen);
                // powtarzaj, jeśli wylosowano zły wierzchołek
            } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2]));
            file << "\n" << vertex1 << " " << vertex2 << " " << weightDist(gen);
            count++;

        }

        //jesli nie osiagnieto limitu krawedzi
        //wylosuj pozostale
        if (edges - count > 0) {
            for (int i = 0; i < edges - count; i++) {
                vertex1 = vertexDist(gen);
                vertex2 = vertexDist(gen);
                if (vertex1 == vertex2 || exists[vertex1][vertex2]) i--;
                else {
                    //wygeneruj krawedz o losowej wadze
                    file << "\n" << vertex1 << " " << vertex2 << " " << weightDist(gen);
                    //odnotuj ze ta krawedz istnieje
                    exists[vertex1][vertex2] = true;
                }
            }
        }

        file.close();
    }
}

/*void FileOperator::randomizeDirected(int size, double density) {
    std::ofstream file(R"(G:\projekt_SDiZO_2\files\graphD.txt)");

    if (!file.is_open()) {
        std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> probDist(0.0, 1.0);
    std::uniform_int_distribution<> weightDist(1, 9);

    file << size << " " << 0 << " " << 0 << " " << size - 1 << std::endl;

    // Generowanie losowych krawędzi między wierzchołkami, aż do uzyskania spójnego grafu
    while (!isGraphConnected(size, file)) {
        for (int u = 0; u < size - 1; u++) {
            for (int v = u + 1; v < size; v++) {
                double random = probDist(gen);
                if (random <= density) {
                    int weight = weightDist(gen);
                    file << u << " " << v << " " << weight << std::endl;
                }
            }
        }
    }

    file.close();
}

bool FileOperator::isGraphConnected(int size, std::ofstream& file) {
    std::vector<bool> visited(size, false);
    std::queue<int> queue;
    int startVertex = 0;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        // Przetwarzaj krawędzie wychodzące z bieżącego wierzchołka
        for (int v = 0; v < size; v++) {
            if (v != currentVertex && !visited[v]) {
                int weight = 1;  // Możesz dostosować wagę krawędzi, jeśli jest potrzebne
                file << currentVertex << " " << v << " " << weight << std::endl;

                visited[v] = true;
                queue.push(v);
            }
        }
    }

    // Sprawdź, czy wszystkie wierzchołki zostały odwiedzone
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}*/

FileOperator::FileOperator() = default;
