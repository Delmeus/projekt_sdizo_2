#include <iostream>
#include "graph/GraphAsList.h"
#include "testers/ManualTester.h"
#include "testers/AutomaticTester.h"

using namespace std;

int main() {

    int answer = 0;
    do {
        cout << "Do you want to test \n1.manually \n2.automatically?" << endl;
        cin >> answer;
    }while(answer < 1 || answer > 2);
    if(answer == 1) {
        ManualTester tester;
        tester.menu();
    }
    else{
        AutomaticTester tester;
        tester.test();
    }
    return 0;

}
