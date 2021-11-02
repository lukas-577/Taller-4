#include <iostream> // esto por el cout 
#include "tens.h"
#include "persona.h"
using namespace std; // esto por el cout

Tens::Tens(){//contructor por defecto

}
//contructor parametrizado 
Tens::Tens(string _nombre,string _materno,string _paterno,Run _run,string _email):Persona(_nombre,_materno, _paterno,_run){
  this->email=_email;

}

//setters

void Tens::setEmail(string email){
  this->email=email;
}

//getters

string Tens::getEmail(){
  return email;
}

//destructor
Tens::~Tens(){
}



//metodo de la clase


void Tens::mostrarTens(){
  mostrarPersona();
  cout<<"email: "<<this->email<<endl;
}