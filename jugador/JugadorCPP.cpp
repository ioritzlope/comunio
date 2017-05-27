#include <stdio.h>
#include "JugadorCPP.h"
#include "jugador.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_LENGTH 50
#define MAX_PUNTOS 9

using namespace std;


Jugador::Jugador()
{
  this->nombre = "";
  this->apellido = "";
  this->puntos = 0;

}
 Jugador::Jugador(string nombre, string apellido, int puntos)
  {
    this->nombre = nombre;
  this->apellido = apellido;
  this->puntos = puntos;

  }
 Jugador::~Jugador()
  {

  }

  string Jugador::getNombre() const
  {
    return nombre;
  }

  string Jugador::getApellido() const
  {
    return apellido;
  }
  int Jugador::getPuntos() const
  {
    return puntos;
  }

  void Jugador::setNombre(string nombre)
  {
    this->nombre = nombre;
  }
  void Jugador::setApellido(string apellido)
  {
    this->apellido = apellido;
  }
  void Jugador::setPuntos(int puntos)
  {
    this->puntos = puntos;
  }

  void Jugador::verPuntosJugador()
  {
    if(leerVerificarJ()==0)
    {
      cout << "primero introduce jugadores" << endl;
    }
    else
    {
      Jugador jugador;
    
    ifstream myfile("Jugadores.txt");
    string line;
    string coma = ", ";
    string blanco =" ";
    vector <Jugador> jugadores;

    while(getline(myfile,line))
    {
      size_t found =line.find(coma);
      

        
        string nombre = line.substr(0, found);
        
        jugador.setNombre(nombre);


       
      
        size_t found2 = line.find(blanco);
      
        
        string apellido = line.substr(found+2, found2+1);
        
        jugador.setApellido(apellido);

      jugadores.push_back(jugador);

    }
    myfile.close();
    for(int i=0; i< jugadores.size();i++)
    {
      string fichero;
      string line2;

      string nombre = jugadores[i].getNombre();

      fichero = nombre + "_.txt";
      
      jugadores[i].setPuntos(leerPuntosJugador(fichero));
       



    }
    for(int i=0; i< jugadores.size();i++)
    {
      for(int j=0;j<jugadores.size();j++)
      {

        if(jugadores[i].getPuntos()>jugadores[j].getPuntos())
        {
          Jugador aux;
          aux = jugadores[i];
          jugadores[i]=jugadores[j];
          jugadores[j]=aux;

        }
      
      }
       
    }

   

    cout << endl<<"Datos de los jugadores ordenados por puntos" << endl;
    for(int i=0; i< jugadores.size();i++)
    {
      cout<<"------------" << endl;
      cout << jugadores[i].getNombre() << " " << jugadores[i].getApellido()<<" " << jugadores[i].getPuntos() << endl;

       
    }

 
  }
 
}
int leerPuntosJugador(string fichero)
  {
    
   ifstream myfile2(fichero.c_str());

   string line2;
   string aux;
   
   vector <int> puntosTotales;
int puntos=0;
    
   while(getline(myfile2,line2))
   {
     puntos = puntos + atoi(line2.c_str());
    
    

   }


   myfile2.close();
   return puntos;
   
  }

  int verificarJugador(string name)
{
  Jugador jugador;
 ifstream myfile("Jugadores.txt");
    string line;
    string coma = ", ";
    string blanco =" ";
    vector <Jugador> jugadores;

    while(getline(myfile,line))
    {
      size_t found =line.find(coma);
      

        
        string nombre = line.substr(0, found);
        
        jugador.setNombre(nombre);


       
      
        size_t found2 = line.find(blanco);
      
        
        string apellido = line.substr(found+2, found2+1);
        
        jugador.setApellido(apellido);

      jugadores.push_back(jugador);

    }
    myfile.close();

    for(int i=0;i<jugadores.size();i++)
    {
      if(jugadores[i].getNombre()==name)
      {
        cout << "Jugador encontrado" << endl;
        return 0;
      }
    }
    return 1;


}

void Jugador::modificarJugador(string nombre)
{
  Jugador jugador;
   ifstream myfile("Jugadores.txt");
    string line;
    string coma = ", ";
    string blanco =" ";
    vector <Jugador> jugadores;

    while(getline(myfile,line))
    {
      size_t found =line.find(coma);
      

        
        string nombre = line.substr(0, found);
        
        jugador.setNombre(nombre);


       
      
        size_t found2 = line.find(blanco);
      
        
        string apellido = line.substr(found+2, found2+1);
        
        jugador.setApellido(apellido);

      jugadores.push_back(jugador);

    }
    
    remove("Jugadores.txt");

    ofstream myfile2("Jugadores.txt");

for(int i=0;i<jugadores.size();i++)
    {
      if(jugadores[i].getNombre()==this->getNombre())
      {
        jugadores[i].setNombre(nombre);
        break;
        
      }
    }


   
   for(int i=0;i<jugadores.size();i++)
    {
     
      myfile2 << jugadores[i].getNombre() << ", " << jugadores[i].getApellido() << endl;

    }

myfile.close();
myfile2.close();
}
void Jugador::eliminarJugador(){
int pos;
char* ayuda1;
char* ayuda2;
char* ayuda4;
char* fichero;
ayuda1=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
ayuda2=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
ayuda4=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
fichero=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
string line;


    Jugador jugador;
    ifstream myfile("Jugadores.txt");
    
     
    string coma = ", ";
    string blanco =" ";
    vector <Jugador> jugadores;

    while(getline(myfile,line))
    {
      size_t found =line.find(coma);
      

        
        string nombre = line.substr(0, found);
        
        jugador.setNombre(nombre);


       
      
        size_t found2 = line.find(blanco);
      
        
        string apellido = line.substr(found+2, found2+1);
        
        jugador.setApellido(apellido);

      jugadores.push_back(jugador);

    }
    
    remove("Jugadores.txt");
    
    sscanf(this->nombre.c_str(), "%s\n",ayuda4);
    sprintf(ayuda4, "%s_.txt", fichero);
    


    ofstream file("Jugadores.txt");
  for(int i=0;i<jugadores.size();i++)
    {
      if(jugadores[i].getNombre()==nombre)
      {
      
        sscanf(this->nombre.c_str(), "%s\n",ayuda1);
        sprintf(ayuda2, "%s_.txt", ayuda1);
        remove(ayuda2);
        jugadores.erase(jugadores.begin()+i);
        
        break;
        
      }
      
    }
    for(int i=0;i<jugadores.size();i++)
    {
     
      file << jugadores[i].getNombre() << ", " << jugadores[i].getApellido() << endl;

    }
remove(fichero);


        file.close();
  myfile.close();
  free(ayuda1);
  free(ayuda4);
  free(ayuda2);
  free(fichero);




}

  istream& operator>>(istream &in, Jugador &p){

  string a;
  

  cout<<"nombre: "<<endl;
  cin>>a;
  
  p.setNombre(a);

  return in;
 }

