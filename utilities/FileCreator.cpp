//
// Created by Antek on 01.05.2023.
//

#include "FileCreator.h"
#include "fstream"
#include "random"

void FileCreator::randomizeFile(int size, double density) {

    std::ofstream file("G:/projekt_SDiZO_2/files/graph.txt");
    int vertex1, vertex2;
    int edges = floor(size * density);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> e(1, 9);
    std::uniform_int_distribution<> v(0, size - 1);
    file << size << " " << edges << " " << 0 << " " << size - 1 << "";
    for (int i = 0; i < edges; i++)
    {
        vertex1 = v(gen); // wygeneruj wierzcholek poczatkowy
        vertex2 = v(gen);
        if(vertex1 == vertex2){
            file << "\n" << vertex1 << " " << vertex2 << " " << 0; //jezeli wierzcholek docelowy i zrodlowy sa tymi samymi to ustaw wage krawedzi na 0
        }
        else{
            file << "\n" << vertex1 << " " << vertex2 << " " << e(gen); //wygeneruj krawedz o losowej wadze
        }
    }
    file.close();
}
