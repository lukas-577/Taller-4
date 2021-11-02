#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <queue>
using namespace std;


#include <queue>
template <class T> class Heap {
public:
    Heap() {};
    virtual ~Heap() {};

    void agregar(T dato, int prioridad) {
        ParPrioridadDato par;
        par.first = prioridad;
        par.second= dato;
        h2.push(par);
    };

    T extraer(){
        ParPrioridadDato par = h2.top();
        h2.pop();
        return par.second;
    }

    bool vacio() {
        return h2.empty();
    }

private:
    typedef std::pair<int, T> ParPrioridadDato; // Prioridad, orden

    class ComparePrioridad {
        public:
            bool operator() (ParPrioridadDato a, ParPrioridadDato b) {
                return a.first > b.first;
            }
    };
    std::priority_queue<ParPrioridadDato, std::vector<ParPrioridadDato>, ComparePrioridad> h2;
};

#endif // HEAP_H_INCLUDED