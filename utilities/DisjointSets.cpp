//
// Created by antek on 02.05.2023.
//

#include "DisjointSets.h"

DisjointSets::DisjointSets(int n) {
    this->n = n;
    parent = new int[n];
    rank = new int[n];

    for(int i = 0; i < n; i++){
        rank[i] = 0;
        parent[i] = i;
    }
}

int DisjointSets::find(int u) {
    if(u != parent[u]) u = find(parent[u]);
    return u;
}

void DisjointSets::merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(rank[x] > rank[y]){
        parent[y] = x;
    }
    else{
        parent[x] = y;
    }

    if(rank[x] == rank[y]) y++;
}
