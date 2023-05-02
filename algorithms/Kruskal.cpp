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

    auto ds = new DisjointSets(g.vertices);
    std::vector<std::pair<int, std::pair<int, int>>>::iterator it;

    for(it = g.edges.begin(); it != g.edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds->find(u);
        int setV = ds->find(v);

        if(setU != setV){
            std::cout << u << " - " << v << std::endl;

            mst += it->first;

            ds->merge(setU, setV);
        }
    }

    return mst;
}

void Kruskal::forMatrix(GraphAsMatrix g) {

}
