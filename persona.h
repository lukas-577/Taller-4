#include <iostream> // esto por el string
#include "run.h"
using namespace std; // esto por el string
#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
  public:
  Persona();//constructor vacio o constructor por defecto
  Persona(string,string,string,Run);
  virtual ~Persona(); //destructor

  //setters and getters

  void setRun(Run);
  Run getRun();

  void setNombre(string nombre);
  string getNombre();

  void setMaterno(string materno);
  string getMaterno();

  void setPaterno(string paterno);
  string getPaterno();

/*
  void setGenero(string genero);
  string getGenero();
*/
  //metodo de la clase
  void mostrarPersona();

private:
  //atributos
  Run run;
  string nombre;
  string materno;
  string paterno;
  //string genero;
};

#endif // PERSONA_H