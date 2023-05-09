//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_PRIM_H
#define PROJEKT_SDIZO_2_PRIM_H


#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"

class Prim {
private:
    static bool createsMST(int u, int v, std::vector<bool> inMST);
public:
    static int forList(GraphAsList g);
    static int forMatrix(GraphAsMatrix g);
};


#endif //PROJEKT_SDIZO_2_PRIM_H
