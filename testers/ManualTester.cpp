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

    do {
        cout << "\nSize: ";
        cin >> size;
        cout << "\nDensity: ";
        cin >> density;
        if(size < 1) cout << "\nSize has to be greater than 0 and density has to be between 0 to 1";
    }while(size < 1 || density < 0 || density > 1);
    system("CLS");

    FileOperator::randomizeFile(size, density);
    //inicjalizacja grafu reprezentowanego jako liste
    //auto graph = new GraphAsList(size);
    //inicjalizacja grafu reprezentowanego jako macierz
    //auto graphM = new GraphAsMatrix(size);
    //graph->readGraphFromFile("graph.txt");
    //graphM->readGraphFromFile("graph.txt");

    //inicjalizacja grafu jako listy sasiedztwa
    //GraphAsList graph = FileOperator::readAsList("graph.txt");
    GraphAsList graph(0);
    //auto graph = new GraphAsList(0);
    graph.readGraphFromFile("graph.txt");
    //inicjalizacja grafu jako macierzy sasiedztwa
    GraphAsMatrix graphM(0);
    //auto graphM= new GraphAsMatrix(0);
    graphM.readGraphFromFile("graph.txt");
    //GraphAsMatrix graphM = FileOperator::readAsMatrix("graph.txt");

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
                FileOperator::randomizeFile(size, density);
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
                graph.readGraphFromFile(name);
                //graph = FileOperator::readAsList("graph.txt");
                graphM.readGraphFromFile(name);
                //FileOperator::readAsMatrix("graph.txt", graphM);
                waitForResponse();
                system("CLS");
                break;
            }
            case 3:{
                graph.display();
                graphM.display();
                waitForResponse();
                system("CLS");
                break;
            }
            case 4:{
                if(graph.vertices > 0){
                    int cost;
                    timer.start();
                    cost = Kruskal::forList(graph);
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
                if(graph.vertices > 0){
                    int cost;
                    timer.start();
                    cost = Prim::forList(graph);
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
                if(graph.vertices > 0){
                    timer.start();
                    //testDijkstraList(graph);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 7:{
                if(graph.vertices > 0){
                    timer.start();
                    //testBellmanFordList(graph);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 8:{
                if(graphM.vertices > 0) {
                    int cost;
                    timer.start();
                    cost =Kruskal::forMatrix(graphM);
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
                if(graphM.vertices > 0) {
                    int cost;
                    timer.start();
                    cost = Prim::forMatrix(graphM);
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
                if(graphM.vertices > 0) {
                    auto dijkstra = new Dijkstra();
                    timer.start();
                    dijkstra->forMatrix(graphM, 0);
                    timer.stop();
                    cout << "\nAlgorithm finished in: |" << timer.mili() << " ms| |" << timer.micro() << " mis|" << endl;
                }
                else cout << "\nGraph does not exist, they might have been a problem with reading graph from file" << endl;
                waitForResponse();
                system("CLS");
                break;
            }
            case 11:{
                if(graphM.vertices > 0) {
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
