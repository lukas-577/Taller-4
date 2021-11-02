#include <iostream> // esto por el cout
#include <string>
#include "persona.h"
#include "run.h"
using namespace std; // esto por el cout

Persona::Persona(){//contructor por defecto
  this->nombre="";
  this->materno="";
  this->paterno="";
}

Persona::Persona(string _nombre,string _materno,string _paterno,Run _run){//contructor por parametrizado
  this->nombre=_nombre;
  this->materno=_materno;
  this->paterno=_paterno;
  this->run=_run;
}

//setters

void Persona::setRun(Run _run){
  this->run=_run;
}

void Persona::setNombre(string _nombre){
  this->nombre=_nombre;
}

void Persona::setPaterno(string _paterno){
  this->paterno=_paterno;
}

void Persona::setMaterno(string _materno){
  this->materno=_materno;
}

/*
void Persona::setGenero(string genero){
  this->genero=genero;
}
*/


//getters



Run Persona::getRun(){
  return run;
}

string Persona::getNombre(){
  return nombre;
}

string Persona::getMaterno(){
  return materno;
}

string Persona::getPaterno(){
  return paterno;
}

/*
string Persona::getGenero(){
  return genero;
}
*/




//destructor
Persona::~Persona(){
}

//metodo de la clase

void Persona::mostrarPersona(){
  cout<<"run :";
  this->run.ver();
  cout<<"nombre: "<<this->nombre<<endl;
  cout<<"materno: "<<this->materno<<endl;
  cout<<"paterno: "<<this->paterno<<endl;
}
