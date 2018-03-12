//
// Created by martin on 12/03/18.
//
#ifndef CONCURRENCY_TIMER_H
#define CONCURRENCY_TIMER_H

#include <iostream>
#include <ctime>

using namespace std;

class timer {
    clock_t inicio;
public:

    void iniciar() {
        inicio = clock();
    }

    void end() {
        clock_t fin = clock();
        cout << "Tardo: " << fin - inicio << endl;
    }
};


#endif //CONCURRENCY_TIMER_H
