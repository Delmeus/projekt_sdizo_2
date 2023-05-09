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
    if (u == v || (!inMST[u] && !inMST[v]) || (inMST[u] && inMST[v]))
        return false;
    return true;
}

int Prim::forList(GraphAsList g) {
//    int n = g.vertices;
//    int cost = 0;
//    vector<bool> mst(n, false);
//    vector<int> parent(n, -1);
//    vector<int> key(n, INT_MAX);
//    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
//
//    q.emplace(0, 0);
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
//
//        std::vector<std::pair<int, std::pair<int, int>>>::iterator v;
//
//        for (v = g.edges.begin(); v != g.edges.end(); v++) {
//            int node = v->second.second;
//            int weight = v->first;
//
//            if (!mst[node] && weight < key[node]) {
//                parent[node] = u;
//                key[node] = weight;
//                q.emplace(key[node], node);
//            }
//        }
//    }
//
//    for (int i = 1; i < n; i++) {
//        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
//        cost += key[i];
//    }
//
//    return cost;
    int n = g.vertices;
    int cost = 0;
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    q.emplace(0, 0);
    key[0] = 0;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (mst[u])
            continue;

        mst[u] = true;

//        for (auto& [v, w] : g.adj[u]) {  // zmiana w tej linii
//            if (!mst[v] && w < key[v]) {
//                parent[v] = u;
//                key[v] = w;
//                q.emplace(key[v], v);
//            }
//        }
    }

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
        cost += key[i];
    }

    return cost;

}
