//
// Created by Antek on 01.05.2023.
//

#include <iostream>
#include "Kruskal.h"
#include "../utilities/DisjointSets.h"
#include "vector"

int Kruskal::forList(GraphAsList g) {
    int mst = 0;

    std::sort(g.edges.begin(), g.edges.end());

    auto ds = new DisjointSets(g.vertices, false);
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;

    for(it = g.edges.begin(); it != g.edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds->find(u);
        int setV = ds->find(v);

        if(setU != setV){
            std::cout << u << " - " << v << " | cost: " << it->first << std::endl;

            mst += it->first;

            ds->merge(setU, setV);
        }
    }

    return mst;
}

int Kruskal::forMatrix(GraphAsMatrix g) {
    int mst = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    auto ds = new DisjointSets(g.vertices, false);

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < g.vertices - 1) {
        int min = INT_MAX, u = - 1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                if (ds->find(i) != ds->find(j) && g.edges[i][j] < min && g.edges[i][j] > 0) {
                    min = g.edges[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ds->merge(u, v);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, u, v, min);
        mst += min;
    }

    return mst;

}
