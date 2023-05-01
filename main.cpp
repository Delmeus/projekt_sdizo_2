#include <iostream>
#include "graph/GraphAsList.h"
#include "utilities/FileCreator.h"
#include "graph/GraphAsMatrix.h"

int main() {
    FileCreator::randomizeFile(12,0.5);
    auto graph = new GraphAsList(12);
    graph->readGraphFromFile();
    graph->display();

    std::cout << std::endl;

    auto graphM = new GraphAsMatrix(12);
    graphM->readGraphFromFile();
    graphM->display();
    return 0;
}
