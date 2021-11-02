#include <iostream> // esto por el cout
#include <sstream>
#include <vector> //para usar vector 
#include "run.h"
using namespace std; // esto por el cout

Run::Run(){//contructor por defecto
  this->run="00000000-0";

}

Run::Run(string run){
  this->run=run;

}

//setters

void Run::setRun(string run){
  this->run=run;
}

//getters

string Run::getRun(){
  return run;
}

//destructor
Run::~Run(){
}



//metodo de la clase


void Run::ver(){
  cout<<this->run<<endl;
}


bool validadorDeRun(string rut)
{
    // Variable que retornaré al final.
    bool validacion = false;
    
    // Variables necesarias para hacer el split :
    stringstream rutstream(rut);          //
    string item;                          //
    vector<string> items;            //
    // ------------------------------------------

    // Otra forma de hacer el split :-------------------------------//
    while (getline(rutstream, item, '-')) { items.push_back(item); }//
    //--------------------------------------------------------------//
    
    // Validacion para los elementos de número y dígito :
    if (items.size() == 2) {
        
        // Variables necesarias para realizar los cálculos.
        long int numero = stoi(items.at(0));
        int mod11, dv, dv_calculado, contador = 2, suma = 0;

        // Conidición para saber si el rut tiene guión k (díg=0) en lugar de dígito :
        if (items.at(1) == "k" || items.at(1) == "K") {
            dv = 10;
        }
        else if(items.at(1) == "0")
        {
           dv = 11;
        }

        else {
            
            // Verifico que el dígito verificador no sea otra letra aparte de k o K o sea más de un caracter :
            char c = (items.at(1)[0]);
            
            if (isdigit(c) == 0 || items.at(1).length() != 1)
                return false;
            
            // Convierto el string del dígito a entero
            dv = stoi(items.at(1));
        }

        // Cálculo del dígito verificador correcto al número del rut.
        
        // ¡ EL PROBLEMA ERA QUE HABÍA PUESTO 'numero > 10' EN LUGAR DE 'numero > 0' XD !
        
        // Al ir dividiendo el número de 10 en 10 llegaré a un punto que será menor que cero pero el int no almacena decimales.
        while (numero > 0) {
            
            // Obtengo el número de más a la izq en aux.
            int aux = numero % 10;
            
            // Condición del algoritmo :-------//
            if (contador < 8) {                //
                suma = suma + (aux * contador);//
            }                                  //
                                               //
            else {                             // 
                contador = 2;                  //
                suma = suma + (aux * contador);//
            }//--------------------------------//
            
            // Esta división se realiza para acortar el número hacia la izq.
            numero /= 10;
            
            // Le sumo +1 al contador que uso como multiplicador del algoritmo.
            contador++;
        }
        
        // Otra vez, un cálculo del algortimo de dígito verificador.
        mod11 = suma % 11;
        // IDEM
        dv_calculado = 11 - mod11;

        // Sí el dígito cálculado dentro de esta función y almacenado en dv_calculado es igual al del string <=> validacion = true
        if (dv == dv_calculado) {
            validacion = true;
        }
    }
    
    
    return validacion;
}