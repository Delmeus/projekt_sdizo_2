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
typedef pair<int, int> pii;

int Prim::forMatrix(GraphAsMatrix &g) {
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
            std::cout << "Edge " << edge_count++ << ": " << a << " - " << b << " | cost = " << min << endl;
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

int Prim::forList(GraphAsList &g) {
//    int n = g.vertices;
//    vector<bool> visited(n, false);
//    vector<int> minCost(n, INT_MAX);
//    vector<int> parent(n, -1);
//    //kolejka do przetrzymywania mst
//    priority_queue<pii, vector<pii>, greater<pii>> pq;
//    //wybieramy wierzcholek startowy
//    pq.emplace(0, 0);
//    minCost[0] = 0;
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//        visited[u] = true;
//        cout << "\nULALALa u = " << u;
//        int iteration = 0;
//        for (const auto& edge : g.edges) {
//            int v = edge.second.second;
//            int weight = edge.first;
//            if (!visited[v] && weight < minCost[v]) {
//                cout << "\nu = " << u << " v = " << v << " w = " << weight;
//                minCost[v] = weight;
//                parent[v] = u;
//                if(iteration > 0) pq.pop();
//                pq.emplace(minCost[v], v);
//                iteration++;
//            }
//        }
//    }
//
//    for (int i = 1; i < n; ++i) {
//        cout << i << " - " << parent[i] << endl;
//    }

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
                    pq.emplace(w, make_pair(v,u));
                }
            }
        }
    }
    
    //zmienna przechowujaca calkowity koszt
    int cost = 0;

    //wyswietlenie mst
    for (int i = 1; i < g.vertices; ++i) {
        cout << i << " - " << parent[i] << " : " << minCost[i] << endl;
        cost += minCost[i];
    }

    return  cost;

}
