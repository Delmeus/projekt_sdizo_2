//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "FileCreator.h"
#include "fstream"
#include "random"

void FileCreator::randomizeFile(int size, double density) {

//    std::ofstream file(R"(C:\Users\antek\Desktop\studia\4.sem\projekt_sdizo_2\files\graph.txt)");
//    int vertex1, vertex2;
//    if(density > 1) density = 1;
//    int edges = floor(floor(size * (size -1))/2 * density); //maksymalna ilosc krawedzi pomnzona przez gestosc
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> e(1, 9);
//    std::uniform_int_distribution<> v(0, size - 1);
//    file << size << " " << edges << " " << 0 << " " << size - 1 << "";
//    for (int i = 0; i < edges; i++)
//    {
//        vertex1 = v(gen); // wygeneruj wierzcholek poczatkowy
//        vertex2 = v(gen);
//        if(vertex1 == vertex2){
//            file << "\n" << vertex1 << " " << vertex2 << " " << 0; //jezeli wierzcholek docelowy i zrodlowy sa tymi samymi to ustaw wage krawedzi na 0
//        }
//        else{
//            file << "\n" << vertex1 << " " << vertex2 << " " << e(gen); //wygeneruj krawedz o losowej wadze
//        }
//    }
//    file.close();
    std::ofstream file(R"(C:\Users\antek\Desktop\studia\4.sem\projekt_sdizo_2\files\graph.txt)");
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
