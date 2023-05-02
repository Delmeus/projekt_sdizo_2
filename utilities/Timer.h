//
// Created by antek on 02.05.2023.
//

#ifndef PROJEKT_SDIZO_2_TIMER_H
#define PROJEKT_SDIZO_2_TIMER_H
#include "chrono"

using namespace std::chrono;

class Timer {
private:
    high_resolution_clock::time_point beginning;
    high_resolution_clock::time_point end;
public:
    void start();
    void stop();
    long mili();
    long micro();
    long nano();
};


#endif //PROJEKT_SDIZO_2_TIMER_H
