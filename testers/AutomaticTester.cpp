//
// Created by antek on 02.05.2023.
//

#include <fstream>
#include <iostream>
#include "AutomaticTester.h"
#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"
#include "../utilities/FileOperator.h"
#include "../utilities/Timer.h"
#include "../algorithms/Kruskal.h"
#include "../algorithms/Prim.h"
#include "../algorithms/Dijkstra.h"
#include "../algorithms/BellmanFord.h"

using namespace std;

void AutomaticTester::test() {
    std::ofstream file(R"(G:\projekt_SDiZO_2\files\results.csv)");
    if(!file.is_open()){
        std::cout << "Couldn't open the file, ending test" << std::endl;
        return;
    }
    /*
     * 0 Kruskal list
     * 1 Kruskal matrix
     * 2 Prim list
     * 3 Prim matrix
     * 4 Dijkstra list
     * 5 Dijkstra matrix
     * 6 BellmanFord list
     * 7 BellmanFord matrix
     */
    long results[8];
    Timer timer;
    GraphAsList graphListUndirected(0);
    GraphAsMatrix graphMatrixUndirected(0);
    GraphAsList graphListDirected(0);
    GraphAsMatrix graphMatrixDirected(0);
    for(int size = 20; size <= 100; size += 20) {
        double density = 0.25;
        do{
            for(int i = 0; i < 7 ; i++)
                results[i] = 0;
            for (int i = 0; i < 15; i++) {
                FileOperator::randomizeUndirected(size, density);
                FileOperator::randomizeDirected(size, density);
                graphListUndirected.readGraphUndirected("graphU.txt");
                graphMatrixUndirected.readGraphUndirected("graphU.txt");
                graphListDirected.readGraphDirected("graphD.txt");
                graphMatrixDirected.readGraphDirected("graphD.txt");

                timer.start();
                Kruskal::forList(graphListUndirected, false);
                timer.stop();
                results[0] += timer.nano();

                timer.start();
                Kruskal::forMatrix(graphMatrixUndirected, false);
                timer.stop();
                results[1] += timer.nano();

                timer.start();
                Prim::forList(graphListUndirected, false);
                timer.stop();
                results[2] += timer.nano();

                timer.start();
                Prim::forMatrix(graphMatrixUndirected, false);
                timer.stop();
                results[3] += timer.nano();

                timer.start();
                Dijkstra::forList(graphListDirected, 0, false);
                timer.stop();
                results[4] += timer.nano();

                timer.start();
                Dijkstra::forMatrix(graphMatrixDirected, 0, false);
                timer.stop();
                results[5] += timer.nano();

                timer.start();
                BellmanFord::forList(graphListDirected, 0, false);
                timer.stop();
                results[6] += timer.nano();

                timer.start();
                BellmanFord::forMatrix(graphMatrixDirected, 0,false);
                timer.stop();
                results[7] += timer.nano();

            }

            file << "rozmiar" << ";" << "gestosc" << endl;
            file << size << ";" << density << endl;
            file << "algorytm"      << ";" << "struktura"<< ";"<< "ms"               << ";" << "micros"        << ";" << "ns"       << endl;
            file << "Kruskal"       << ";" << "lista"   << ";" << results[0]/1000000 << ";" << results[0]/1000 << ";" << results[0] << endl;
            file << "Kruskal"       << ";" << "macierz" << ";" << results[1]/1000000 << ";" << results[1]/1000 << ";" << results[1] << endl;
            file << "Prim"          << ";" << "lista"   << ";" << results[2]/1000000 << ";" << results[2]/1000 << ";" << results[2] << endl;
            file << "Prim"          << ";" << "macierz" << ";" << results[3]/1000000 << ";" << results[3]/1000 << ";" << results[3] << endl;
            file << "Dijkstra"      << ";" << "lista"   << ";" << results[4]/1000000 << ";" << results[4]/1000 << ";" << results[4] << endl;
            file << "Dijkstra"      << ";" << "macierz" << ";" << results[5]/1000000 << ";" << results[5]/1000 << ";" << results[5] << endl;
            file << "Bellman-Ford"  << ";" << "lista"   << ";" << results[6]/1000000 << ";" << results[6]/1000 << ";" << results[6] << endl;
            file << "Bellman-Ford"  << ";" << "macierz" << ";" << results[7]/1000000 << ";" << results[7]/1000 << ";" << results[7] << endl;
            density += 0.25;
            if(density == 1) density = 0.99;
        }while(density < 1);
    }

    file.close();
}
