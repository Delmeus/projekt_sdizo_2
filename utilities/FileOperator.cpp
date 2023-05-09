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
        //tablica do przechowywania czy wygenerowana
        //zostala krawedz z danym wierzcholkiem
        //aby ulatwic tworzenie grafu pelnego
        bool visited[size];
        for(int i = 0; i < size; i++) visited[i] = false;
        int vertex1, vertex2;
        if (density > 1) density = 1;
        //maksymalna ilosc krawedzi pomnzona przez gestosc
        int edges = floor(floor(size * (size - 1)) / 2 * density);

        //inicjalizacja generatora liczb pseudolosowych
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> e(1, 9);
        std::uniform_int_distribution<> v(0, size - 1);

        file << size << " " << edges << " " << 0 << " " << size - 1 << "";

        //jezeli graf jest pelny to nie losujemy krawedzi
        //tylko po prostu generujemy kazda krawedz
        //i losujemy dla niej wage
        if(edges == (size * (size - 1)) / 2){
            for(int i = 0; i < size; i++){
                for(int j = i + 1; j < size; j++){
                    file << "\n" << i << " " << j << " " << e(gen);
                }
            }
        }

        //kiedy graf nie jest pelny losujemy kazda krawedz i jej wage
        else {
            //tymczasowa tablica do przechowywania jakie
            //krawedzie juz istnieja
            bool exists[size][size];

            //pierwsza krawedz, aby dodawanie kolejnych w petli wykonywalo sie prawidlowo
            vertex1 = 0;
            do {
                vertex2 = v(gen);
            } while (vertex2 == 0);

            file << "\n" << vertex1 << " " << vertex2 << " " << e(gen);
            visited[vertex1] = true;
            visited[vertex2] = true;
            exists[vertex1][vertex2] = true;


            for (int i = 1; i < size - 1; i++) {
                // Losuj krawędź do dodania do drzewa spinajacego
                do {
                    vertex1 = v(gen);
                    vertex2 = v(gen);
                    // powtarzaj, jeśli wylosowano zły wierzchołek
                } while (vertex1 == vertex2 || (visited[vertex1] == visited[vertex2]));

                // Dodaj krawędź do drzewa
                visited[vertex1] = visited[vertex2] = true;
                exists[vertex1][vertex2] = true;
                file << "\n" << vertex1 << " " << vertex2 << " " << e(gen);
            }

            //jesli nie osiagnieto limitu krawedzi
            //wylosuj pozostale
            if (edges - size > 0) {
                for (int i = 0; i < edges - size; i++) {
                    vertex1 = v(gen);
                    vertex2 = v(gen);
                    if (vertex1 == vertex2 || exists[vertex1][vertex2]) i--;
                    else {
                        //wygeneruj krawedz o losowej wadze
                        file << "\n" << vertex1 << " " << vertex2 << " " << e(gen);
                        //odnotuj ze ta krawedz istnieje
                        exists[vertex1][vertex2] = true;
                    }
                }
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
        GraphAsList graph(size);
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

GraphAsMatrix FileOperator::readAsMatrix(std::string s) {
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
        GraphAsMatrix graph(size);


        for(int i = 0; i < edgesNumber; i++){
            std::getline(file, line);
            std::stringstream info(line);
            info >> u >> v >> w;
            if(graph.edges[u][v] > w) {
                graph.edges[u][v] = w;
                graph.edges[v][u] = w;
            } else if(graph.edges[v][u] > w){
                graph.edges[v][u] = w;
                graph.edges[u][v] = w;
            }
            std::cout << "\nzczytane, wartosc: " << graph.edges[u][v];

        }
        graph.display();
        file.close();
        return graph;
    }
    else std::cout << "\nTHERE WAS A PROBLEM WITH OPENING FILE";
    return {0};
}

FileOperator::FileOperator() = default;
