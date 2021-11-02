#include <iostream> // esto por el cout
#include <vector> //para trabajar con vectores
#include <algorithm>
#include <cctype>
#include <string>
#include "fecha.h"
using namespace std; // esto por el cout

struct arreglo  {
  string fechaNacimiento;
  string paterno;
  string materno;
  string nombre;
  string rut;
  string genero;

};


Fecha::Fecha(){//contructor por defecto
  this->anho=1900;
  this->mes=01;
  this->dia=01;
}

Fecha::Fecha(int anho,int mes,int dia){
  this->anho=anho;
  this->mes=mes;
  this->dia=dia;
}

//setters

void Fecha::setAnho(int anho){
  this->anho=anho;
}

void Fecha::setMes(int mes){
  this->mes=mes;
}

void Fecha::setDia(int dia){
  this->dia=dia;
}



//getters

int Fecha::getAnho(){
  return anho;
}

int Fecha::getMes(){
  return mes;
}

int Fecha::getDia(){
  return dia;
}


//destructor
Fecha::~Fecha(){
}

//metodo de la clase

void Fecha::obtenerFecha(){
  cout<<this->dia<<"/"<<this->mes<<"/"<<this->anho<<endl;
}



string arregloMes [12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre", "diciembre"};

int arregloDia [12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool validarFecha(vector<string> vectorSepara)
{
    bool existeMes = false, existeDia = false; 
    int i=0;
    
    struct arreglo aux;
    transform(aux.fechaNacimiento.begin(), aux.fechaNacimiento.end(), aux.fechaNacimiento.begin(),
    [](unsigned char c){ return tolower(c); });
    
    for(int j=0; j < 12; j++)
    {
        if (vectorSepara.at(1) == arregloMes[j])
        {
            existeMes = true;
            break;
        }
    }
    if (stoi(vectorSepara.at(0)) <= arregloDia[i] && stoi(vectorSepara.at(0)) > 0 && i != 1)
        existeDia = true;
    
    else
    {   //recordar en este if cambie el || por &&
        if(stoi(vectorSepara.at(2))%400 == 0 && (stoi(vectorSepara.at(2))%4 == 0 && stoi(vectorSepara.at(2))%100 != 0) && (stoi(vectorSepara.at(0)) <= 29 && stoi(vectorSepara.at(0)) > 0))
        {
            existeDia = true;
        }
    }

    return (existeMes && existeDia);
}