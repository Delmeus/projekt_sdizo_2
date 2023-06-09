//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_FILEOPERATOR_H
#define PROJEKT_SDIZO_2_FILEOPERATOR_H


#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"

class FileOperator {
public:
    static void randomizeUndirected(int size, double density);
    static void randomizeDirected(int size, double density);
    static GraphAsList readAsList(std::string s);
    static GraphAsMatrix readAsMatrix(std::string s);
    FileOperator();
};


#endif //PROJEKT_SDIZO_2_FILEOPERATOR_H
