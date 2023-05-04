//
// Created by Antek on 01.05.2023.
//

#include <queue>
#include "Prim.h"
#include "iostream"
#include "../utilities/DisjointSets.h"
#include "random"

using namespace std;

int Prim::forMatrix(GraphAsMatrix g) {
    vector<bool> inMST(g.vertices, false);
    inMST[0] = true;
    int count = 0, cost = 0;
    while (count < g.vertices - 1) {
        int min = INT_MAX, u = -1, v = -1;
        for (int i = 0; i < g.vertices; i++) {
            for (int j = 0; j < g.vertices; j++) {
                if (g.edges[i][j] < min && g.edges[i][j] != 0) {
                    if (createsMST(i, j, inMST)) {
                        min = g.edges[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u != -1 && v != -1) {
            cout << "Edge " << count++ << " : (" << u << " , " << v << " ) : cost = " << min << endl;
            cost += min;
            inMST[v] = inMST[u] = true;
        }
    }
    return cost;

}

bool Prim::createsMST(int u, int v, vector<bool> inMST){
    if (u == v)
        return false;
    if (!inMST[u] && !inMST[v])
        return false;
    else if (inMST[u] && inMST[v])
        return false;
    return true;
}

int Prim::minKey(int key[], bool mstSet[], GraphAsMatrix g)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < g.vertices; v++)
        if (!mstSet[v] && key[v] < min && key[v] != 0)
            min = key[v], min_index = v;

    return min_index;
}


void Prim::forList(GraphAsList g) {
//    int n = g.vertices;
//    int cost = 0;
//    vector<bool> mst(n, false);
//    vector<int> parent(n, -1);
//    vector<int> key(n, INT_MAX);
//    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//
//    q.push(make_pair(0, 0));
//    key[0] = 0;
//
//    while (!q.empty()) {
//        int u = q.top().second;
//        q.pop();
//
//        if (mst[u])
//            continue;
//
//        mst[u] = true;
//        cost += key[u];
//
//        for (const auto& v : g[u]) {
//            int node = v.first;
//            int weight = v.second;
//
//            if (!mst[node] && weight < key[node]) {
//                parent[node] = u;
//                key[node] = weight;
//                q.push(make_pair(key[node], node));
//            }
//        }
//    }
//
//    for (int i = 1; i < n; i++) {
//        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
//    }

}
