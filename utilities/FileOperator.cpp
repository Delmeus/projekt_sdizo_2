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

    std::cout << "Undirected graph" << std::endl
    << "For size " << size << " and density "<< density
    << " we get " << edges << " edges" << std::endl;;

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

        //jezeli graf jest pelny do generujemy kolejno krawedzie
        //z losowymi wagami aby usprawnic szybkosc generowania
        if (edges == size * (size - 1))
            for (int u = 0; u < size; u++)
                for (int v = u + 1; v < size; v++)
                    file << u << " " << v << " " << weightDist(gen) << std::endl;

        else {
            //do przechowywania powstalego grafu
            std::vector<Edge> graph;
            //do stwierdzenia jakie krawedzie juz istnieja
            std::vector<std::vector<bool>> adjacencyMatrix(size, std::vector<bool>(size, false));
            std::vector<bool> visited(size, false);
            int vertex1 = 0, vertex2;
            //bool visited[size];

            do {
                vertex2 = vertexDist(gen);
            } while (vertex2 == 0);

            graph.push_back({vertex1, vertex2, weightDist(gen)});
            visited[vertex1] = true;
            visited[vertex2] = true;


            //generujemy drzewo spinajace
            for (int i = 1; i < size - 1; i++) {
                do {
                    vertex1 = vertexDist(gen);
                    vertex2 = vertexDist(gen);
                } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2]));
                visited[vertex1] = true;
                visited[vertex2] = true;
                graph.push_back({vertex1, vertex2, weightDist(gen)});
            }

            //jezeli gestosc jest wieksza od 0.5 to latwiej
            // bedzie wygenerowac gdzie krawedzi nie bedzie
            if (density > 0.5 && graph.size() < size - 1) {
                int shadowEdges = 0;
                while (shadowEdges < size * (size - 1)/2 - edges) {
                    int source = vertexDist(gen);
                    int target = vertexDist(gen);
                    if (source != target && !adjacencyMatrix[source][target]) {
                        adjacencyMatrix[source][target] = adjacencyMatrix[target][source] = false;
                        shadowEdges++;
                    }
                }

                int generatedEdges = size - 1;
                for(int u = 0; u < size; u++){
                    for(int v = u + 1; v < size; v++){
                        if(!adjacencyMatrix[u][v] && !adjacencyMatrix[v][u]){
                            graph.push_back({u, v, weightDist(gen)});
                            generatedEdges++;
                        }
                    }
                }
            }
            //jezeli gestosc jest mniejsza niz 0.5 to
            // latwiej bedzie wygenerowac gdzie sa krawedzie
            else if (graph.size() <= size - 1) {
                int generatedEdges = size - 1;
                while (generatedEdges < edges) {
                    int source = vertexDist(gen);
                    int target = vertexDist(gen);
                    if (source != target && !adjacencyMatrix[source][target]) {
                        graph.push_back({source, target, weightDist(gen)});
                        adjacencyMatrix[source][target] = adjacencyMatrix[target][source] = true;
                        generatedEdges++;
                    }
                }
            }

            //Zapisz graf do pliku
            file << size << " " << edges << " " << 0 << " " << size - 1 << std::endl;
            for (const auto &edge: graph) {
                file << edge.source << " " << edge.target << " " << edge.weight << std::endl;
            }
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

    std::cout << "Directed graph" << std::endl
    << "For size " << size << " and density " << density 
    << " we get " << edges << " edges" << std::endl;

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
                    file << u << " " << v << " " << weightDist(gen) << std::endl;
                }
            }
        }
    }

    else {
        //do przechowywania powstalego grafu
        std::vector<Edge> graph;
        //do stwierdzenia jakie krawedzie juz istnieja
        std::vector<std::vector<bool>> adjacencyMatrix(size, std::vector<bool>(size, false));
        std::vector<bool> visited(size, false);
        int vertex1 = 0, vertex2;
        //bool visited[size];

        do {
            vertex2 = vertexDist(gen);
        } while (vertex2 == 0);

        graph.push_back({vertex1, vertex2, weightDist(gen)});
        visited[vertex1] = true;
        visited[vertex2] = true;
        
        //generujemy drzewo spinajace
        for (int i = 1; i < size - 1; i++) {
            do {
                vertex1 = vertexDist(gen);
                vertex2 = vertexDist(gen);
            } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2]));
            visited[vertex1] = true;
            visited[vertex2] = true;
            graph.push_back({vertex1, vertex2, weightDist(gen)});
        }

        //jezeli gestosc jest wieksza od 0.5 to latwiej
        // bedzie wygenerowac gdzie krawedzi nie bedzie
        if (density > 0.5 && graph.size() < size - 1) {
            int shadowEdges = 0;
            while (shadowEdges < size * (size - 1) - edges) {
                int source = vertexDist(gen);
                int target = vertexDist(gen);
                if (source != target && !adjacencyMatrix[source][target]) {
                    adjacencyMatrix[source][target] = false;
                    shadowEdges++;
                }
            }

            int generatedEdges = size - 1;
            for(int u = 0; u < size; u++){
                for(int v = u + 1; v < size; v++){
                    if(!adjacencyMatrix[u][v]){
                        graph.push_back({u, v, weightDist(gen)});
                        generatedEdges++;
                    }
                }
            }
        }
            //jezeli gestosc jest mniejsza niz 0.5 to
            // latwiej bedzie wygenerowac gdzie sa krawedzie
        else if (graph.size() <= size - 1) {
            int generatedEdges = size - 1;
            while (generatedEdges < edges) {
                int source = vertexDist(gen);
                int target = vertexDist(gen);
                if (source != target && !adjacencyMatrix[source][target]) {
                    graph.push_back({source, target, weightDist(gen)});
                    adjacencyMatrix[source][target] = true;
                    generatedEdges++;
                }
            }
        }

        //Zapisz graf do pliku
        for (const auto &edge: graph) {
            file << edge.source << " " << edge.target << " " << edge.weight << std::endl;
        }
    }
    file.close();
}

FileOperator::FileOperator() = default;
