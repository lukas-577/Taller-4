#ifndef COLA_H
#define COLA_H

using namespace std;
#include <queue>

template <class Tipo>
class Cola : private std::queue<Tipo> {
public:
    Tipo extraer() {
        Tipo a = queue<Tipo>::front();
        queue<Tipo>::pop();
        return a;
    }

    void agregar(Tipo valor) {
        queue<Tipo>::push(valor);
    }

    bool vacio() {
        return queue<Tipo>::empty();
    }
};
#endif // COLA_H