//
// Created by antek on 02.05.2023.
//

#ifndef PROJEKT_SDIZO_2_DISJOINTSETS_H
#define PROJEKT_SDIZO_2_DISJOINTSETS_H


class DisjointSets {
public:
    int *parent, *rank;
    int n;

    DisjointSets(int n, bool prim);

    int find(int u);
    void merge(int x, int y);

};


#endif //PROJEKT_SDIZO_2_DISJOINTSETS_H
