//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "Kruskal.h"
#include "../utilities/DisjointSets.h"
#include "vector"

using namespace std;

int Kruskal::forList(GraphAsList &g) {
    std::vector<std::pair<int, std::pair<int,int>>> edges;

    for (int i = 0; i < g.vertices; ++i) {
        for (const auto& edge : g.adjList[i]) {
            int dest = edge.first;
            int weight = edge.second;
            edges.push_back({weight, {i, dest}});
        }
    }

    int mst = 0, edge_count = 0;

    std::sort(edges.begin(), edges.end());

    DisjointSets ds(g.vertices, false);
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;

    for(it = edges.begin(); it != edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.find(u);
        int setV = ds.find(v);

        if(setU != setV){
            std::cout << "Edge\t" << edge_count++ << ":\t" << u << " - " << v << "\t| cost = " << it->first << std::endl;
            mst += it->first;

            ds.merge(setU, setV);
        }
    }

    return mst;

}

int Kruskal::forMatrix(GraphAsMatrix &g) {
    int mst = 0;


    auto ds = new DisjointSets(g.vertices, false);

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
        std::cout << "Edge\t" << edge_count++ << ":\t" << u << " - " << v << "\t| cost = " << min << std::endl;
        mst += min;
    }

    return mst;

}
