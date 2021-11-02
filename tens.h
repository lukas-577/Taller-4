#include <iostream> // esto por el string
#include "persona.h"
#include "run.h"
using namespace std; // esto por el string
#ifndef TENS_H
#define TENS_H

class Tens: public Persona
{
  public:
  Tens();//constructor vacio o constructor por defecto
  //hereda los string de la clase persona, el ultimo es de la clase hija(Tens)
  Tens(string,string,string,Run,string);
  virtual ~Tens(); //destructor

  //setters and getters
  void setEmail(string email);
  string getEmail();
  //metodo de la clase
  void mostrarTens();

private:
  //atributos
  string email;

};

#endif // TENS_H