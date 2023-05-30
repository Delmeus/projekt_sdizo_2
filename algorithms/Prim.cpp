//
// Created by Antek on 01.05.2023.
//

#include <queue>
#include <set>
#include "Prim.h"
#include "iostream"
#include "../utilities/DisjointSets.h"
#include "random"

using namespace std;

int Prim::forMatrix(GraphAsMatrix &g, bool print) {
    //do przechowywania czy dane wierzcholki
    //znajduja sie juz w MST
    vector<bool> inMST(g.vertices, false);

    //Zaczynamy od pierwszego wierzcholka
    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    while (edge_count < g.vertices - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                if (g.edges[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = g.edges[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            if(print)
                std::cout << "Edge\t" << edge_count++ << ":\t" << a << " - " << b << "\t| cost = " << min << endl;
            else
                edge_count++;
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    return mincost;
}

bool Prim::isValidEdge(int u, int v, vector<bool> inMST)
{
    if ((u == v) || (!inMST[u] && !inMST[v]) || (inMST[u] && inMST[v]))
        return false;

    return true;
}

int Prim::forList(GraphAsList &g, bool print) {
/*
    //wektor w ktorym zapisujemy czy odwiedzilismy dany wierzcholek
    vector<bool> visited(g.vertices, false);

    //wektor do przechowywania najmniejszej wagi dla danego polaczenia
    vector<int> minCost(g.vertices, INT_MAX);

    //wektor do przechowywania rodzica kazdego wierzcholka
    vector<int> parent(g.vertices, -1);

    //kolejka do przechowywania mozliwych krawedzi
    //priority_queue<pii, vector<pii>, greater<>> pq;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    //wybieramy wierzcholek startowy
    pq.emplace(0,make_pair(0,0));

    while(!pq.empty()){
        //czytamy z kolejki wierzcholek o najmniejszej wadze
        int u = pq.top().second.second;
        //zdejmujemy ten element z kolejki
        pq.pop();
        //zaznaczmy ze odwiedzilismy ten wierzcholek
        visited[u] = true;

        for(auto edge : g.edges){
            //jezeli poczatek krawedzi jest rowny naszemu u
            if(edge.second.first == u) {
                //czytamy koniec krawedzi
                int v = edge.second.second;
                //czytamy wage krawedzi
                int w = edge.first;
                //jezeli wierzcholek v nie byl jeszcze odwiedzony
                //i jego koszt jest mniejszy niz wczesniejsze
                if(!visited[v] && w < minCost[v]){
                    //laczymy wierzcholek v z wierzcholkiem u w MST
                    parent[v] = u;
                    //zaznaczamy jaki jest minimalny koszt dla wierzcholka v
                    minCost[v] = w;
                    //umieszczamy krawedz w kolejce
                    pq.emplace(w, make_pair(u,v));
                }
            }
            else if(edge.second.second == u){
                //czytamy poczatek krawedzi
                int v = edge.second.first;
                //czytamy wage krawedzi
                int w = edge.first;
                //jezeli wierzcholek v nie byl jeszcze odwiedzony
                //i jego koszt jest mniejszy niz wczesniejsze
                if(!visited[v] && w < minCost[v]){
                    //laczymy wierzcholek v z wierzcholkiem u w MST
                    parent[v] = u;
                    //zaznaczamy jaki jest minimalny koszt dla wierzcholka v
                    minCost[v] = w;
                    //umieszczamy krawedz w kolejce
                    pq.emplace(w, make_pair(u, v));
                }
            }
        }
    }
    
    //zmienna przechowujaca calkowity koszt
    int cost = 0;

    //wyswietlenie mst
    for (int i = 1; i < g.vertices; ++i) {
        cout << "Edge\t" << i-1 << ":\t" << i << " - " << parent[i] << "\t| cost = " << minCost[i] << endl;
        cost += minCost[i];
    }
*/
    //wektor do przechowywania najmniejszej wagi dla danego polaczenia
    std::vector<int> key(g.vertices, INT_MAX);

    //wektor do przechowywania rodzica kazdego wierzcholka
    std::vector<int> parent(g.vertices, -1);

    //wektor w ktorym zapisujemy czy dany wierzcholek nalezy do mst
    std::vector<bool> included(g.vertices, false);

    //kolejka do przechowywania mozliwych polaczen
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    //std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    int root = 0;
    key[root] = 0;
    pq.emplace(0,make_pair(0,0));

    while (!pq.empty()) {
        int u = pq.top().second.second;
        pq.pop();

        included[u] = true;

        //sprawdzamy wszystkich sasiadow u
        for (const auto& edge : g.adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            //jezeli v jeszcze nie ma w MST i jego waga jest mniejsza niz aktualna, to dodajemy ja do kolejki
            if (!included[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.emplace(key[v],make_pair(u,v));
                //pq.emplace(v, key[v]);
            }
        }
    }
    int cost = 0;

    for (int i = 1; i < g.vertices; ++i) {
        if(print)
            cout << "Edge\t" << i-1 << ":\t" << i << " - " << parent[i] << "\t| cost = " << key[i] << endl;

        cost += key[i];
    }

    return  cost;

}
