#include <iostream> // esto por el string
using namespace std; // esto por el string
#ifndef RUN_H
#define RUN_H

class Run
{
  public:
  Run();//constructor vacio o constructor por defecto
  Run(string run);
  virtual ~Run(); //destructor

  //setters and getters

  void setRun(string run);
  string getRun();

  //metodo propio de la clase

  void ver();



private:
  //atributos
  string run;

};

bool validadorDeRun(string);

#endif // RUN_H