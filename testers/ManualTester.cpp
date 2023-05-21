//
// Created by antek on 02.05.2023.
//

#include "iostream"
#include "ManualTester.h"
#include "../utilities/FileOperator.h"
#include "../graph/GraphAsList.h"
#include "../graph/GraphAsMatrix.h"
#include "../algorithms/Kruskal.h"
#include "../algorithms/Prim.h"
#include "../algorithms/Dijkstra.h"

using namespace std;

ManualTester::ManualTester() {

}

void ManualTester::menu() {
    int answer, size;
    double density;
    GraphAsList graphListUndirected(0);
    GraphAsMatrix graphMatrixUndirected(0);
    GraphAsList graphListDirected(0);
    GraphAsMatrix graphMatrixDirected(0);

    do{
        cout << "What do you want to do?\n"
                "1. Create new graph\n"
                "2. Load graph from file" << endl;
        cin >> answer;
        if(answer == 1) {
            do {
                cout << "\nSize: ";
                cin >> size;
                cout << "\nDensity: ";
                cin >> density;
                if (size < 1) cout << "\nSize has to be greater than 0 and density has to be between 0 to 1";
            } while (size < 1 || density < 0 || density > 1);
            FileOperator::randomizeUndirected(size, density);
            FileOperator::randomizeDirected(size, density);
            graphListUndirected.readGraph("graphU.txt");
            graphMatrixUndirected.readGraphUndirected("graphU.txt");
            graphMatrixDirected.readGraphDirected("graphD.txt");
        }
        else if(answer == 2){
            std::string name;
            std::cout << "Please insert source file (remember to add .txt extension)\nFilename: ";
            cin >> name;
            std::cout << "\nSearching for file in directory";
            graphListUndirected.readGraph(name);
            graphMatrixUndirected.readGraphUndirected(name);
            waitForResponse();
        }
    }while(answer != 1 && answer != 2);
    system("CLS");


    do {
        cout << endl;
        cout << "\n+-------------------------MENU-------------------------+"
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
        cout << endl;

        switch (answer) {
            case 1: {
                FileOperator::randomizeUndirected(size, density);
                graphListUndirected.readGraph("graphU.txt");
                graphMatrixUndirected.readGraphUndirected("graphU.txt");
                graphMatrixDirected.readGraphDirected("graphD.txt");
                waitForResponse();
                system("CLS");
                break;
            }
            case 2:{
                std::string name;
                system("CLS");
                std::cout << "Please insert source file (remember to add .txt extension)\nFilename: ";
                cin >> name;
                std::cout << "\nSearching for file in directory";
                graphListUndirected.readGraph(name);
                graphMatrixUndirected.readGraphUndirected(name);
                waitForResponse();
                system("CLS");
                break;
            }
            case 3:{
                graphListUndirected.display();
                cout << "Undirected: " << endl;
                graphMatrixUndirected.display();
                cout << "Directed: " << endl;
                graphMatrixDirected.display();
                waitForResponse();
                system("CLS");
                break;
            }
            case 4:{
                if(graphListUndirected.vertices > 0){
                    int cost;
                    timer.start();
                    cost = Kruskal::forList(graphListUndirected);
                    timer.stop();
                    cout << "Cost: " << cost << endl;
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 5:{
                if(graphListUndirected.vertices > 0){
                    int cost;
                    timer.start();
                    cost = Prim::forList(graphListUndirected);
                    timer.stop();
                    cout << "Cost: " << cost << endl;
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 6:{
                if(graphListUndirected.vertices > 0){
                    timer.start();
                    //testDijkstraList(graphListUndirected);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graphfrom file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 7:{
                if(graphListUndirected.vertices > 0){
                    timer.start();
                    //testBellmanFordList(graphListUndirected);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 8:{
                if(graphMatrixUndirected.vertices > 0) {
                    int cost;
                    timer.start();
                    cost =Kruskal::forMatrix(graphMatrixUndirected);
                    timer.stop();
                    cout << "Cost: " << cost << endl;
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 9:{
                if(graphMatrixUndirected.vertices > 0) {
                    int cost;
                    timer.start();
                    cost = Prim::forMatrix(graphMatrixUndirected);
                    timer.stop();
                    cout << "Cost: " << cost << endl;
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 10:{
                if(graphMatrixUndirected.vertices > 0) {
                    auto dijkstra = new Dijkstra();
                    timer.start();
                    dijkstra->forMatrix(graphMatrixDirected, 0);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 11:{
                if(graphMatrixUndirected.vertices > 0) {
                    timer.start();
                    //testBellmanFordMatrix();
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
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
                cout << "\nSuccessfully set size to: " << size << " and density to: " << density;
                waitForResponse();
                system("CLS");
                break;
            }
            case 13:{
                cout << "\nClosing program" << endl;
                break;
            }
            default:{
                cout << "\nWrong answer, try again" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
        }
    }while(answer != 13);
}

void ManualTester::waitForResponse() {
    std::cout << "\n\npress ENTER to continue..." << std::endl;
    std::cin.ignore(10000, '\n');
    getchar();
}

void ManualTester::testKruskalMatrix() {

}
