//
// Created by Antek on 01.05.2023.
//

#ifndef PROJEKT_SDIZO_2_FILEOPERATOR_H
#define PROJEKT_SDIZO_2_FILEOPERATOR_H


#include "../graph/GraphAsList.h"

class FileOperator {
public:
    static void randomizeFile(int size, double density);
    static GraphAsList readAsList(std::string s);
};


#endif //PROJEKT_SDIZO_2_FILEOPERATOR_H
