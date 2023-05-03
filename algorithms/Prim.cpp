//
// Created by Antek on 01.05.2023.
//

#include "Prim.h"
#include "iostream"

using namespace std;

int Prim::forMatrix(GraphAsMatrix g) {
    int cost = 0;

// Array to store constructed MST
    int parent[g.vertices];

    // Key values used to pick minimum weight edge in cut
    int key[g.vertices];

    // To represent set of vertices included in MST
    bool mstSet[g.vertices];

    // Initialize all keys as INFINITE
    for (int i = 0; i < g.vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < g.vertices - 1; count++) {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet, g);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < g.vertices; v++)

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (g.edges[u][v] && !mstSet[v]
                && g.edges[u][v] < key[v])
                parent[v] = u, key[v] = g.edges[u][v];
    }


    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < g.vertices; i++) {
        cout << parent[i] << " - " << i << " \t" << g.edges[i][parent[i]] << " \n";
        cost += g.edges[i][parent[i]];
    }
    return cost;
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

}
