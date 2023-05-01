//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_PRIM_H
#define PROJEKT_SDIZO_2_PRIM_H


#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"

class Prim {
public:
    void forList(GraphAsList g);
    void forMatrix(GraphAsMatrix g);
};


#endif //PROJEKT_SDIZO_2_PRIM_H
