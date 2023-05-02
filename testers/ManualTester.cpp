//
// Created by antek on 02.05.2023.
//

#include "iostream"
#include "ManualTester.h"
#include "../utilities/FileCreator.h"
#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"
#include "../algorithms/Kruskal.h"

using namespace std;

ManualTester::ManualTester() {

}

void ManualTester::menu() {
    int answer, size;
    double density;
    do {
        cout << "\nSize: ";
        cin >> size;
        cout << "\nDensity: ";
        cin >> density;
        if(size < 1) cout << "\nSize has to be greater than 0 and density has to be between 0 to 1";
    }while(size < 1 || density < 0 || density > 1);
    system("CLS");
    FileCreator::randomizeFile(size, density);
    auto graph = new GraphAsList(size);
    auto graphM = new GraphAsMatrix(size);
    graph->readGraphFromFile();
    graphM->readGraphFromFile();
    do {
        cout << endl;
        cout << "\n+------------------------------------------------------+"
             << "\n| 1.  Generate random file                             |"
             << "\n| 2.  Load graph from file                             |"
             << "\n| 3.  Display graph                                    |"
             << "\n| 4.  Test Kruskal's    algorithm for   list           |"
             << "\n| 5.  Test Prim's       algorithm for   list           |"
             << "\n| 6.  Test Dijkstra's   algorithm for   list           |"
             << "\n| 7.  Test Bellman-Ford algorithm for   list           |"
             << "\n| 8.  Test Kruskal's    algorithm for matrix           |"
             << "\n| 9.  Test Prim's       algorithm for matrix           |"
             << "\n| 10. Test Dijkstra's   algorithm for matrix           |"
             << "\n| 11. Test Bellman-Ford algorithm for matrix           |"
             << "\n| 12. Change size and density                          |"
             << "\n| 13. Exit program                                     |"
             << "\n+------------------------------------------------------+"
             << "\nAnswer: ";
        cin >> answer;
        switch (answer) {
            case 1: {
                FileCreator::randomizeFile(size, density);
                break;
            }
            case 2:{
                delete graph;
                graph = new GraphAsList(size);
                delete graphM;
                graphM = new GraphAsMatrix(size);
                graph->readGraphFromFile();
                graphM->readGraphFromFile();
                break;
            }
            case 3:{
                graph->display();
                graphM->display();
                break;
            }
            case 4:{
                int cost;
                timer.start();
                cost = Kruskal::forList(*graph);
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                cout << "Cost: " << cost << endl;
                break;
            }
            case 5:{
                timer.start();
                testPrimList(*graph);
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 6:{
                timer.start();
                testDijkstraList(*graph);
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 7:{
                timer.start();
                testBellmanFordList(*graph);
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 8:{
                int cost;
                timer.start();
                cost = Kruskal::forMatrix(*graphM);
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                cout << "Cost: " << cost << endl;
                break;
            }
            case 9:{
                timer.start();
                testPrimMatrix();
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 10:{
                timer.start();
                testDijkstraMatrix();
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 11:{
                timer.start();
                testBellmanFordMatrix();
                timer.stop();
                cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| " << timer.micro() << " mis|" << endl;
                break;
            }
            case 12:{
                do {
                    cout << "\nNew size: ";
                    cin >> size;
                    cout << "\nNew density: ";
                    cin >> density;
                    if(size < 1) cout << "\nSize has to be greater than 0 and density has to be between 0 to 1" << endl;
                }while(size < 1 || !(density > 0 && density <= 1));
                system("CLS");
                break;
            }
            case 13:{
                cout << "\nClosing program" << endl;
                break;
            }
            default:{
                cout << "\nWrong answer, try again" << endl;
                break;
            }
        }
    }while(answer != 13);
}


void ManualTester::testKruskalMatrix() {

}

void ManualTester::testPrimList(GraphAsList g) {

}

void ManualTester::testPrimMatrix() {

}

void ManualTester::testDijkstraList(GraphAsList g) {

}

void ManualTester::testDijkstraMatrix() {

}

void ManualTester::testBellmanFordList(GraphAsList g) {

}

void ManualTester::testBellmanFordMatrix() {

}
