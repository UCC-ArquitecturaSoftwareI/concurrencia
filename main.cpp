#include <iostream>
#include <thread>
#include <vector>
#include <ctime>
#include <mutex>

#include "timer.h"
#include "msg_queue.h"

using namespace std;

mutex pantalla;

typedef struct {
    int inicio;
    int fin;
} par;

msg_queue<par> sms;


void tarea();


bool esPrimo(unsigned int num) {
    for (unsigned int i = 2; i <= (num / 2); i++)
        if (num % i == 0)
            return false;

    return true;
}

#define CANT_HILOS 8
#define INTERVALO 500

int main() {
    thread *h[CANT_HILOS];
    timer tiempo;
    par dato;
    unsigned int inicio = 2;
    unsigned int fin = 300000;
    unsigned int intervalo = (fin - inicio) / CANT_HILOS;

    for (int j = 0; j < CANT_HILOS; j++) {
        h[j] = new thread(tarea);
    }
    for (int i = 2; i <= fin; i = i + INTERVALO) {
        dato.inicio = i;
        dato.fin = i + INTERVALO - 1;
        sms.enqueue(dato);
    }

    tiempo.iniciar();
    for (auto &actual : h)
        actual->join();
    tiempo.end();

    return 0;
}

void tarea() {
    par dato;

    dato = sms.dequeue();

    for (int i = dato.inicio; i < dato.fin; i++)
        if (esPrimo(i)) {
            pantalla.lock();
            std::cout << i << std::endl;
            pantalla.unlock();
        }
}