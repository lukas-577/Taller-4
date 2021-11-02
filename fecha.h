#include <iostream> // esto por el string
#include <vector> //para trabajar con vectores
using namespace std; // esto por el string
#ifndef FECHA_H
#define FECHA_H

class Fecha
{
  public:
  Fecha();//constructor vacio o constructor por defecto
  Fecha(int anho,int mes, int dia);
  Fecha(string);
  virtual ~Fecha(); //destructor

  //setters and getters

  void setAnho(int anho);
  int getAnho();

  void setMes(int mes);
  int getMes();

  void setDia(int dia);
  int getDia();


  //metodo propio de la clase
  //bool validarFecha();

  void obtenerFecha();

  int fechaObtIntMes();

  void separaStringFecha();


private:
  //atributos
  int anho;
  int mes;
  int dia;



};

bool validarFecha(vector<string>);

#endif // FECHA_H