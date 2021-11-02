/******************************************************************************
    AUTOR:
        1.-Lukas Medina Rozas
        2.-Rafael Figueroa Araneda 
    PROFESOR:
        - Fabian Jesus Gonzales Berger
    SECCION: 301
    LINK A VIDEO EN YOUTUBE:
    https://youtu.be/fnT_30wcW-k
        

*******************************************************************************/

#include <iostream>
#include <fstream> //lectura y escritura de archivos
#include <sstream>
#include <vector> //para usar vector 
#include "tens.h"
#include "fecha.h"
#include "run.h"
#include "cola.h"
#include "paciente.h"
#include "heap.h"
#include "stack.h"



using namespace std;

string nombre_archivo = "pacientes_csv.txt";


struct arreglo  {
  string fechaNacimiento;
  string paterno;
  string materno;
  string nombre;
  string rut;
  string genero;

};


vector<string> split(string lineaASeparar, char delimitador) 
{
    vector<string> vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;
    while(getline(linea, parteDelString, delimitador))
    {
      vector_interno.push_back(parteDelString);
    }
    return vector_interno;

}


int mes_correspondiente(string fecha){
    if(fecha=="enero")
        return 1;
    else if(fecha=="febrero")
        return 2;
    else if(fecha=="marzo")
        return 3;
    else if(fecha=="abril")
        return 4;
    else if(fecha=="mayo")
        return 5;
    else if(fecha=="junio")
        return 6;
    else if(fecha=="julio") 
        return 7;
    else if(fecha=="agosto")
        return 8;
    else if(fecha=="septiembre")
        return 9;
    else if(fecha=="octubre")
        return 10;
    else if(fecha=="noviembre")
        return 11;
    else if(fecha=="diciembre")
        return 12;
    return 0;                              
}


void leeProcesa(string nombre_archivo,Cola<Paciente> & colaPaciente,int & total,int & cantidad){
  ifstream archivo;
  archivo.open (nombre_archivo.c_str (), ios::in);
  vector<struct arreglo> arreg;
  int contador=0;
  int j=0;
  if(archivo.is_open()){
    string linea;
    bool primeraLinea = true;
    while(getline(archivo,linea,'\n')){
      struct arreglo aux;
      if(!primeraLinea){
        stringstream ss (linea);
        string temp;
        contador++;
        //con este for separo las columnas para guardarlo en cada nodo
        for(int columna=0;getline(ss,temp,',');columna++){
          if(columna==0){
            aux.rut=temp;
          }
          if(columna==1){
            aux.paterno=temp;
          }
          if(columna==2){
            aux.materno=temp;
          }
          if(columna==3){
            aux.nombre=temp;
          }
          if(columna==4){
            aux.genero=temp;
          }
          if(columna==5){
            aux.fechaNacimiento=temp;
          }
        }
        arreg.push_back(aux);
        //nuevo->sgte=NULL;
      }
      if(primeraLinea){ 
        primeraLinea = false;
        }
    }
    for(vector< struct arreglo>::iterator i=arreg.begin();i!=arreg.end();i++){
      vector<string> vectorSepara = split(i->fechaNacimiento,'-');
      //cout<<i->fechaNacimiento<<endl;
      int mesInt= mes_correspondiente(vectorSepara.at(1));
      int dia = stoi(vectorSepara.at(0));
      int anho = stoi(vectorSepara.at(2));
      //cout<<"validando Fecha: "<<validarFecha(vectorSepara)<<endl;
      Fecha fecha;

      fecha.setDia(dia);
      fecha.setMes(mesInt);
      fecha.setAnho(anho);


      //vector<string> vectorSeparaRun = split(i->rut,'-');

      //cout<<i->rut<<endl;
      //cout<<"validando Run: "<<validadorDeRun(i->rut)<<endl;
      if(validarFecha(vectorSepara)==true&&validadorDeRun(i->rut)==true){

        //Cola<Paciente> colaPaciente;
        //agrego los datos a la cola
        Paciente pac(i->nombre,i->materno,i->paterno,i->rut,fecha);
        colaPaciente.agregar(pac);


        j++;
            
      }
      
      cantidad=j;
    }
    total=contador;
     cout <<"Se han procesado "<< contador << " registros"<<endl;
  }else {
        cout << "Error en la apertura del archivo "+nombre_archivo;
    }
  archivo.close();//cerramos el archivo

}



void ingresarTens(Stack<Tens> & stackTens){
  int cantidadTens;
  cout<<"Ingrese cantidad de tens: ";
  cin>>cantidadTens;
  for(int i=0;i<cantidadTens;i++){
    Tens unTens[cantidadTens];//puedo ingresar los que quiera el usuario (memoria dinamica)
    string nombre,paterno,materno,email,run;
    cout<<"Ingrese run tens sin puntos y con digito verificador: ";
    cin>>run;
    unTens[i].setRun(run);
    cout<<"Ingrese nombre tens: ";
    cin>>nombre;
    unTens[i].setNombre(nombre);
    cout<<"Ingrese apellido materno: ";
    cin>>materno;
    unTens[i].setMaterno(materno);
    cout<<"Ingrese apellido paterno: ";
    cin>>paterno;
    unTens[i].setPaterno(paterno);
    cout<<"Ingrese email: ";
    cin>>email;
    unTens[i].setEmail(email);
    //aqui agrego a la pila 
    stackTens.push(unTens[i]);



    //unTens[i].mostrarTens();
  }
  /*
  while(!stackTens.empty()){
    stackTens.pop(); // el pop  va sacando los datos y lo deja vacio
    cout<<"******************";
  }*/
}


//solo de prueba para ver si estan en la cola
void mostrarCola(Cola<Paciente> & colaPaciente){
  Cola<Paciente> colaAux;
  while(!colaPaciente.vacio()){
    Paciente p = colaPaciente.extraer();
    
    p.mostrarPaciente();
    
    colaAux.agregar(p);
  }
  while(!colaAux.vacio()){
    colaPaciente.agregar(colaAux.extraer());
  }
}


void mostrarPila(Stack<Tens> c) {
    while (!c.empty()) {
        Tens p = c.pop();
        p.mostrarTens();
    }
}

void mostrarPila(Stack<Paciente> c) {
    while (!c.empty()) {
        Paciente p = c.pop();
        p.mostrarPaciente();
    }
}

//contador de cola en paciente
int contarElementos(Cola<Paciente>  c){
  Cola<Paciente> aux;
  int contar=0;
  while(!c.vacio()){
    //guardar nuestra informacion para no perderla
    aux.agregar(c.extraer());
    contar++;
  }
  //retornar los datos a la cola original
  while(!aux.vacio()){
    c.agregar(aux.extraer());//trasvasijamos nuestra informacion a la variable original
  }
  return contar;
}

//contador de Stack en tens
int contarElementos(Stack<Tens>  c){
  Stack<Tens> aux;
  int contar=0;
  while(!c.empty()){
    //guardar nuestra informacion para no perderla
    aux.push(c.pop());
    contar++;
  }
  //retornar los datos a la cola original
  while(!aux.empty()){
    c.push(aux.pop());//trasvasijamos nuestra informacion a la variable original
  }
  return contar;
}

//contador de heap en paciente
int contarElementos(Heap<Paciente>  c){
  Heap<Paciente> aux;
  int contar=0;
  while(!c.vacio()){
    //guardar nuestra informacion para no perderla
    aux.agregar(c.extraer(),1);
    contar++;
  }
  //retornar los datos a la heap original
  while(!aux.vacio()){
    c.agregar(aux.extraer(),1);//trasvasijamos nuestra informacion a la variable original
  }
  return contar;
}


//solo de prueba
//contador de Stack en paciente
int contarElementos(Stack<Paciente>  c){
  Stack<Paciente> aux;
  int contar=0;
  while(!c.empty()){
    //guardar nuestra informacion para no perderla
    aux.push(c.pop());
    contar++;
  }
  //retornar los datos a la cola original
  while(!aux.empty()){
    c.push(aux.pop());//trasvasijamos nuestra informacion a la variable original
  }
  return contar;
}


void citacionPaciente(Cola<Paciente> colaPaciente,Stack <Paciente> & stackPa,    Heap<Paciente> & heapPa){

  
  while(!colaPaciente.vacio()){
    //extraemos el dato de la colaPaciente y lo dejamos en la variable p
    Paciente p = colaPaciente.extraer();
    // como primer parametro el objeto y ordenamos segun la edad 
    heapPa.agregar(p, p.edad());
  }
  //paso lo del heapPa a un aux para trabajar con el
  Heap<Paciente> heapAux = heapPa;
  //ahora volvemos a dejar los datos que estan ordenados en el heap en la cola original
  while(!heapAux.vacio()){
    Paciente p= heapAux.extraer();
    colaPaciente.agregar(p);
  }
  //ahora los ordeno alrevez para que esten de mayor edad a menor edad en una pila
  while(!colaPaciente.vacio()){
    stackPa.push(colaPaciente.extraer());
  }
  Stack <Paciente> aux = stackPa;
  int cantidadmax;
  int dia=0;
  cout<<"Ingrese cantidad maxima diaria de pacientes que pueden ser vacuandos: ";
  cin>>cantidadmax;
  while(!aux.empty()){
    
    dia++;
    cout<<"Dia "<<dia;
    cout<<"--------------------------------"<<endl;
    for(int i=0;i<cantidadmax&&!aux.empty();i++){
      Paciente p = aux.pop();
      
      cout<<p.getNombre()<<" "<<p.getPaterno()<<" "<<p.getMaterno()<<" "<<p.getRun().getRun()<<" "<<p.edad()<<endl;
      
      
      
    }
  }

}
void menu()
{
  int total=0,cantidad=0,validador_menu=0;
  char opcion_menu;
  Cola<Paciente> c;
  Stack<Tens> stackTens;
  Stack<Paciente> stackPaciente;
  Heap<Paciente> heapPa;

 while(validador_menu==0)
 {
   cout<<"\n\nIngrese su opcion:\n\n";
   cout<<"a) Ingresar Tens en una Pila\n\n";
   cout<<"b) Mostrar Tens\n\n";
   cout<<"c) Cargar Base de datos de pacientes\n\n";
   cout<<"d) Programar una citacion para pacientes\n\n";
   cout<<"e) Salir\n\n"; fflush(stdin);
   cin>> opcion_menu;
   switch(opcion_menu)
   {
      case 'a': {
                cout<<endl;
                ingresarTens(stackTens);
                cout<<"contar elementos de pila tens: "<<contarElementos(stackTens)<<endl;
                break;
                }
      case 'b': {

                cout<<endl;
                mostrarPila(stackTens);
                                        
      break;
                          }

      case 'c': {
                cout<<endl;
                leeProcesa(nombre_archivo,c,total,cantidad);
                cout<<"la cantidad de elementos en la cola paciente son: "<<contarElementos(c)<<endl;

                          
      break;
                          
                          }
      case 'd': {
                citacionPaciente(c,stackPaciente,heapPa);    
                cout<<"\n\nContar elementos del heap paciente: "<<contarElementos(heapPa)<<endl;    
      break;
                         }
      case 'e': { exit(0);
                }
                      


      default: { cout<<"\n\n Opcion no valida,Por favor reintente..\n\n";
      menu();}
   }
   }
   }


int main()
 {
   menu();
 }