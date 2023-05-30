//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_DIJKSTRA_H
#define PROJEKT_SDIZO_2_DIJKSTRA_H


#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"

class Dijkstra {
private:
    int minDistance(int distance[], bool pathSet[], GraphAsMatrix &g);
public:
    static void forList(GraphAsList &g, int source, bool print);
    static void forMatrix(GraphAsMatrix &g, int source, bool print);
};



#endif //PROJEKT_SDIZO_2_DIJKSTRA_H
