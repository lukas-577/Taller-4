#include <iostream> // esto por el string
#include "persona.h"
#include "fecha.h"
#include "run.h"
using namespace std; // esto por el string
#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente: public Persona
{
  public:
  Paciente();//constructor vacio o constructor por defecto
  Paciente(string,string,string,Run,Fecha);
  virtual ~Paciente(); //destructor

  //setters and getters

  void setFechaDeNacimiento(Fecha);
  Fecha getFechaDeNacimiento();

  //metodo de la clase
  void mostrarPaciente();

  //calcula y devuelve los años cumplidos del paciente.
  int edad();


private:
  //atributos
  Fecha fechaDeNacimiento;
  //int estado;




};

#endif // PACIENTE_H