#include <iostream> // esto por el cout 
#include "persona.h"
#include "paciente.h"
#include "fecha.h"
#include "fechaActual.h"
#include <sstream>
using namespace std; // esto por el cout

Paciente::Paciente(){//contructor por defecto

}
//contructor parametrizado 
Paciente::Paciente(string _nombre,string _materno,string _paterno,Run _run,Fecha fechaNacimiento):Persona(_nombre,_materno, _paterno,_run){

  this->fechaDeNacimiento=fechaNacimiento;

}

//setters

void Paciente::setFechaDeNacimiento(Fecha _fechaNacimiento){
  this->fechaDeNacimiento=_fechaNacimiento;
}

//getters

Fecha Paciente::getFechaDeNacimiento(){
  return fechaDeNacimiento;
}

//destructor
Paciente::~Paciente(){
}



//metodo de la clase


void Paciente::mostrarPaciente(){
  mostrarPersona();
  cout<<"Fecha nacimiento: ";
  this->fechaDeNacimiento.obtenerFecha();
}

//calcula y devuelve los años cumplidos del paciente.

int Paciente::edad(){
  
  string fecha_hora_a=fechaYHora();
  //Divide la fecha
  vector<string> partes_fecha_hA;
  stringstream linea(fecha_hora_a);
  string parteDelString;
  while(getline(linea,parteDelString,'/'))
  {
    partes_fecha_hA.push_back(parteDelString);
  }
  int fActualdia=atoi(partes_fecha_hA[0].c_str());
  int fActualMes=atoi(partes_fecha_hA[1].c_str());
  int fActualInt=atoi(partes_fecha_hA[2].c_str());
  
  int fechaAnho=fechaDeNacimiento.getAnho();
  int fechaMes=fechaDeNacimiento.getMes();
  int fechaDia=fechaDeNacimiento.getDia();
  int edad=0;
  //int fActualInt=atoi(fActual.c_str());
  int fActualAnho = fActualInt;
  //se le reesta uno por que despues se le va a sumar en el if de la fecha mes y el dia 
  edad=fActualAnho-fechaAnho-1;
  if(fActualMes==fechaMes && fActualdia>=fechaDia)
   {
      edad++;
   }
   else if(fActualMes>fechaMes)
   {
      edad++;
   }

  return edad;
}