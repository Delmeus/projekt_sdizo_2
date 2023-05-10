//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "Kruskal.h"
#include "../utilities/DisjointSets.h"
#include "vector"

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool edgeCompare(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int Kruskal::forList(GraphAsList &g) {
//    int mst = 0;
//
//    g.display();
//    std::sort(g.edges.begin(), g.edges.end());
//    for(int i = 0; i < g.vertices; i++)
//        std::sort(g.edges[i].begin(), g.edges[i].end());
//    g.display();
//
//    DisjointSets ds(g.vertices, false);
//

//    for(it = g.edges.begin(); it != g.edges.end(); it++){
//        int u = it->second.first;
//        int v = it->second.second;
//
//        int setU = ds->find(u);
//        int setV = ds->find(v);
//
//        if(setU != setV){
//            std::cout << u << " - " << v << "\t | cost: " << it->first << std::endl;
//
//            mst += it->first;
//
//            ds->merge(setU, setV);
//        }
//    }

    DisjointSets ds(g.vertices, false);

    // Tworzenie listy krawędzi z listy sąsiedztwa grafu
    std::vector<Edge> edges;
    //PROBLEM JEST TUTAJ
    for (int u = 0; u < g.vertices; u++) {
        for (int i = 0; i < g.edges[u].size(); i += 2) {
            int v = g.edges[u][i];
            int w = g.edges[u][i + 1];
            edges.emplace_back(u, v, w);
        }
    }

    for(auto e : edges){
        int u = e.u;
        int v = e.v;
        cout << " hehe";
        int setU = ds.find(u);
        int setV = ds.find(v);
        std::cout << "tu jestem";
        if(setU != setV){
            std::cout << u << " - " << v << "\t | cost: " << std::endl;
        }
    }

//    // Sortowanie krawędzi niemalejąco
//    std::sort(edges.begin(), edges.end(), edgeCompare);
//
//    // Przetwarzanie krawędzi
//    for (auto e : edges) {
//        e.u = ds.find(e.u);
//        e.v = ds.find(e.v);
//        if (e.u != e.v) {
//            ds.merge(e.u, e.v);
//            std::cout << e.u << " - " << e.v << "\t | cost: " << std::endl;
//        }
//    }
    return 0;

}

int Kruskal::forMatrix(GraphAsMatrix &g) {
    int mst = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    auto ds = new DisjointSets(g.vertices, false);

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < g.vertices - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                if (ds->find(i) != ds->find(j) && g.edges[i][j] < min) {
                    min = g.edges[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ds->merge(u, v);
        std::cout << "Edge " << edge_count++ << ": (" << u << ", " << v << ")\t| cost = " << min << std::endl;
        mst += min;
    }

    return mst;

}
