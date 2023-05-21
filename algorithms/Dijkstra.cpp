//
// Created by Antek on 01.05.2023.
//

#include "Dijkstra.h"
#include "iostream"
#include <queue>
#include <set>

using namespace std;

void Dijkstra::forList(GraphAsList g) {

}

void Dijkstra::forMatrix(GraphAsMatrix &g, int beginning) {
    std::vector<int> distance(g.vertices, INT_MAX);  // Inicjalizacja odległości dla wszystkich wierzchołków jako nieskończoność
    std::vector<bool> visited(g.vertices, false);    // Tablica odwiedzin wierzchołków
    distance[beginning] = 0;                      // Odległość od startowego wierzchołka do samego siebie wynosi 0

    for (int count = 0; count < g.vertices - 1; count++) {
        int minDistance = INT_MAX;
        int minVertex = -1;

        // Znajdowanie wierzchołka o najmniejszej odległości spośród tych, które nie zostały jeszcze odwiedzone
        for (int v = 0; v < g.vertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minVertex = v;
            }
        }

        // Oznaczanie znalezionego wierzchołka jako odwiedzony
        visited[minVertex] = true;

        // Aktualizowanie odległości dla sąsiadów wybranego wierzchołka
        for (int v = 0; v < g.vertices; v++) {
            if (!visited[v] && g.edges[minVertex][v] != INT_MAX && distance[minVertex] != INT_MAX &&
                distance[minVertex] + g.edges[minVertex][v] < distance[v]) {
                distance[v] = distance[minVertex] + g.edges[minVertex][v];
            }
        }
    }

    // Wyświetlanie wyników
//    std::cout << "Shortest distances from vertex " << beginning << ":" << std::endl;
//    for (int v = 0; v < g.vertices; v++) {
//        std::cout << "Vertex " << v << ": " << distance[v] << std::endl;
//    }


//    for(int i = 0; i < g.vertices; i++){
//        distance[i] = INT_MAX, pathSet[i] = false;
//    }
//
//    distance[beginning] = 0;
//
//    for(int count = 0; count < g.vertices - 1; count++){
//        int u = minDistance(distance, pathSet, g);
//
//        pathSet[u] = true;
//
//        for(int v = 0; v < g.vertices; v++){
//            if(!pathSet[v] && g.edges[u][v] && distance[u] != INT_MAX
//               && distance[u] + g.edges[u][v] < distance[v]){
//                distance[v] = distance[u] + g.edges[u][v];
//            }
//        }
//    }

    std::cout << "Vertex \t Distance from " << beginning << std::endl;
    for(int i = 0; i < g.vertices; i++){
        std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
    }

}

int Dijkstra::minDistance(int *distance, bool *pathSet, GraphAsMatrix &g) {
    int min = INT_MAX, min_index;

    for(int v = 0; v < g.vertices; v++){
        if(pathSet[v] == false && distance[v] <= min){
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}