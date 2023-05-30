//
// Created by Antek on 01.05.2023.
//

#include "Dijkstra.h"
#include "iostream"
#include <queue>
#include <set>

using namespace std;

void Dijkstra::forList(GraphAsList &g, int source, bool print) {
    //dystans do kazdego wierzcholka
    vector<int> distance(g.vertices, INT_MAX);
    //czy odwiedzono dany wierzcholek
    vector<bool> visited(g.vertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    distance[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        //wybieramy wierzcholek o najmniejszej odleglosci
        int u = pq.top().second;
        pq.pop();

        //jezeli wierzcholek odwiedzony to pomijamy
        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        //przegldamy sasiadow u
        for (const auto& edge : g.adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (v == u)
                   continue;

            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
                // Jeżeli znaleziono krotsza sciezke aktualizujemy wartosc
                distance[v] = distance[u] + weight;
                pq.emplace(distance[v], v );
            }

        }
    }

    if(print) {
        std::cout << "Vertex \t Distance from " << source << std::endl;
        for (int i = 0; i < g.vertices; i++) {
            if (distance[i] != INT_MAX)
                std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
            else
                std::cout << "  " << i << " \t\t" << "-" << std::endl;
        }
    }
}

void Dijkstra::forMatrix(GraphAsMatrix &g, int source, bool print) {
    std::vector<int> distance(g.vertices, INT_MAX);
    std::vector<bool> visited(g.vertices, false);
    distance[source] = 0;

    for (int count = 0; count < g.vertices - 1; count++) {
        int minDistance = INT_MAX;
        int minVertex = -1;

        for (int v = 0; v < g.vertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                minVertex = v;
            }
        }

        visited[minVertex] = true;

        for (int v = 0; v < g.vertices; v++) {
            if (!visited[v] && g.edges[minVertex][v] != INT_MAX && distance[minVertex] != INT_MAX &&
                distance[minVertex] + g.edges[minVertex][v] < distance[v]) {
                distance[v] = distance[minVertex] + g.edges[minVertex][v];
            }
        }
    }

    if(print) {
        std::cout << "Vertex \t Distance from " << source << std::endl;
        for (int i = 0; i < g.vertices; i++) {
            if (distance[i] != INT_MAX)
                std::cout << "  " << i << " \t\t" << distance[i] << std::endl;
            else
                std::cout << "  " << i << " \t\t" << "-" << std::endl;
        }
    }

}

