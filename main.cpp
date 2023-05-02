#include <iostream>
#include "graph/GraphAsList.h"
#include "utilities/FileCreator.h"
#include "graph/GraphAsMatrix.h"
#include "algorithms/Kruskal.h"
#include "testers/ManualTester.h"

int main() {

    auto tester = new ManualTester();
    tester->menu();
    return 0;

}
