#include <iostream> // esto por el cout
#include <sstream>
#include <vector> //para usar vector 
#include "fechaActual.h"
using namespace std; // esto por el cout

//solo para tener la funcion separada y usarla en las clases correspondientes.

const string fechaYHora() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);

    return buf;
}
