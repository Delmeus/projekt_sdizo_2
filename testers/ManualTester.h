//
// Created by antek on 02.05.2023.
//

#ifndef PROJEKT_SDIZO_2_MANUALTESTER_H
#define PROJEKT_SDIZO_2_MANUALTESTER_H


#include "../utilities/Timer.h"
#include "../graph/GraphAsList.h"

class ManualTester {
private:
    Timer timer;
    void testKruskalList(GraphAsList g);
    void testKruskalMatrix();
    void testPrimList(GraphAsList g);
    void testPrimMatrix();
    void testDijkstraList(GraphAsList g);
    void testDijkstraMatrix();
    void testBellmanFordList(GraphAsList g);
    void testBellmanFordMatrix();
    static void waitForResponse();
    static void checkDensity(double &density, int size);
public:
    ManualTester();
    void menu();
};


#endif //PROJEKT_SDIZO_2_MANUALTESTER_H
