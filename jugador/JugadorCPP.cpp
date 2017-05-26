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

/*
int leerFichero()
{
	 FILE* file;


	 char c;
   

if(file=fopen("Jugadores.txt","r"))
{
  printf("\nEstos son los jugadores que estan guardados en los ficheros\n");

	  while ((c = fgetc(file)) != EOF)
    {

      if (c != '\n')
      putchar(c);
    else
    {
      printf("\n");
    }
    }
    return 1;
 }

 else
 {
  printf("No hay ningun jugador guardado en el sistema\n");
  return 0;

 }
  //cerrar fichero
  fclose(file);

 
}

void insertarJugador()
{
  char nombre[MAX_LENGTH];
  char apellido[MAX_LENGTH];
  int numero=0;

  int len=0;
  char* str;
  str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  char* str2;
  str2 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  

  char* str3;
  str3 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

    char* fichero;
  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+6);


  printf("\n");
  cout << "Introduce el nombre del jugador" << endl;
  fgets(str,MAX_LENGTH,stdin);
  sscanf(str,"%s",nombre);
  cout << "Datos introducidos hasta el momento" << endl;
  
  cout << nombre << endl;

   sprintf(fichero, "%s_.txt", nombre);
   if(fopen(fichero, "r"))
   {
    printf("\nEse Jugador ya existe, tiene que introducir uno nuevo que no este en el sistema\n");
    
   }
   else
   {


   cout << endl <<"Ahora introduce el apellido del jugador" << endl;

   fgets(str2,MAX_LENGTH,stdin);
  sscanf(str2,"%[^\n]s",apellido);
  sscanf(str3,"%i",&numero);
  cout << "Datos introducidos hasta el momento" << endl;
  
  cout << nombre << endl;
 
   cout << apellido << endl;

 cout << endl << "Introduce los puntos de este jugador" << endl;


   cin >> numero;
   if(numero>MAX_PUNTOS)
   {
    cout << "Has supero el maximo de puntos asignables posibles que es de 9" << endl;
    cout << "Por lo tanto,tendra 9 puntos" << endl;
    numero = MAX_PUNTOS;
   }
  cout << "Datos introducidos hasta el momento" << endl;
  
   cout << nombre << endl;
 
   cout << apellido << endl;
   cout << numero << endl;

pasarDatosAFichero(nombre,apellido,numero);
}
}

void pasarDatosAFichero(char* nom, char* apellido, int num)
{


  FILE * file;
  FILE * file2;
  FILE * file3;

  char * fichero;
  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+6);

  char * nombre;
  nombre = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

  char * str;
  str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

  char * fichero3;
  fichero3 = (char*)malloc((sizeof(char)*MAX_LENGTH)+5);

    


  if(! (file = fopen("Jugadores.txt", "r")))
  {
    file = fopen("Jugadores.txt", "w");
     fprintf(file, "%s, %s\n", nom, apellido);
printf("Jugador guardado correctamente\n" );
 
  }
  else
  {
    file = fopen("Jugadores.txt", "a");
     fprintf(file, "%s, %s\n", nom, apellido);
printf("Jugador guardado correctamente\n");


  }

 
  fclose(file);


  sprintf(fichero, "%s_.txt", nom);//para concatenar el nombre del jugador y ".txt"

if(! (file2 = fopen(fichero, "r")))
  {
    file2 = fopen(fichero, "w");
    fprintf(file2, "%i\n", num);
     
printf("Asignacion de puntos al jugador satisfactorio\n" );
  
  }
  else
  {
    file2 = fopen(fichero, "a");
    fprintf(file2, "%i\n", num);
  }
fclose(file2);
     

  
clear_if_Needed(str);


  printf("Asignar este jugador a usuario: SI/NO\n" );

 string resp;

cin >> resp;

if(resp =="no")
{
   cout << "Jugador no asignado a ningun usuario";

}
else
{
  cout << "A que usuario le quieres asignar?" << endl;

  clear_if_Needed(str);

  fgets(str,MAX_LENGTH,stdin);
  sscanf(str, "%s\n", nombre);

  sprintf(fichero3, "%s.txt", nombre);



  if(!(file3 = fopen(fichero3, "r")))
  {
    printf("Este usuario no existe, a si que este jugador esta en modo AGENTE LIBRE\n");
  }
  else
  {
  file3 = fopen(fichero3, "a");
  fprintf(file3, "%s, %s\n", nom, apellido);
  printf("Se ha asignado el jugador %s al usuario %s\n", nom, nombre );
 
  }
fclose(file3);
free(fichero);

free(fichero3);
free(str);
free(nombre);


}
}

void verPuntosJugador(char* str)
{
 /* if(leerFichero()==0)
  {
    cout << "Tendras que introducir jugadores" << endl;
  }
  
 // char* str;
  char* fichero;
  char* nombre;
  char c;

  FILE* f;

  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  //str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  nombre = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  
  

//printf("Introduce el nombre del jugador que quieres ver sus puntos\n");

//fgets(str, MAX_LENGTH, stdin);
sscanf(str, "%s\n", nombre);

sprintf(fichero, "%s_.txt", nombre);


if(!(fopen(fichero, "r")))
{
  printf("Lo siento, ese jugador no esta\n");

  

}
else
{
  char* str;
  str = (char* )malloc(sizeof(char)*MAX_LENGTH);
  int num = 0;
  int sum = 0;
  int index = 0;
  f=fopen(fichero, "r");
  printf("\n");
  printf("\nEstos son los puntos que tiene %s\n", nombre);

  while ((c = fgetc(f)) != EOF)
    {

      if (c != '\n')
      {
      putchar(c);
      str[index] = c;
      index++;
        

    }
    else
    {

      sscanf(str, "%i\n", &num);
      sum +=num;
      printf("\n");
      index=0;

    }

    }



    printf("\n%s tiene en total %i puntos \n",nombre, sum );
 
  //cerrar fichero
  fclose(f);

}

free(fichero);
free(str);
free(nombre);







}

void puntuarJugador()
{
  
 if( leerFichero()==0)
 {

  cout << "Tendras que intrducir jugadores" << endl;

 }
 else
 {

  char* str;
  char* str2;
  char* nombre;
  char* fichero;

  FILE* file;
   int num = 0;
   int len=0;

  str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  str2 = (char*)malloc((sizeof(char)*MAX_LENGTH));
  nombre =(char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+6);



printf("\n");
printf("Elige el jugador para ver sus puntos\n");
printf("Para eso introduce el Nombre de ese jugador\n");

fgets(str, MAX_LENGTH, stdin);
sscanf(str, "%s\n", nombre);

sprintf(fichero, "%s_.txt", nombre);

if(!(fopen(fichero, "r")))
{
  printf("El jugador que has introducido no esta\n");
}

else
{
 
  printf("Cuantos puntos le quieres dar a este jugador\n");

  fgets(str2, MAX_LENGTH, stdin);
  len = sscanf(str2, "%i\n", &num);

  if(len==0)
  {
    printf("No has introducido un numero. Error\n");
  }
  else
  {

    if(num > MAX_PUNTOS)
    {
      num = MAX_PUNTOS;
      printf("Has pasado los puntos maximos, se establera el maximo permitido de 9 puntos\n");
    }

  file = fopen(fichero, "a");
  fprintf(file, "%i\n", num);


  printf("Puntos guardados correctamente\n");
    
 
  //cerrar fichero
  fclose(file);
  free(str2);
  free(str);
  free(fichero);
  free(nombre);
}

}




}

}



/**
  Esta funcion elimina los caracteres pendientes si es necesario
  Se usa junto con fgets para leer la entrada hasta cierta longitud

void clear_if_Needed(char *str)
{
  if (str[strlen(str) - 1] != '\n')
  {
    int c;    
      while ( (c = getchar()) != EOF && c != '\n');
    }
}

*/
