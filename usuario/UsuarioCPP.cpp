#include "UsuarioCPP.h"
#include "usuario.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX_LENGTH 20

using namespace std;

void Usuario::setNombre(string nombre)
{
  this->nombre = nombre;
}
void ficheroUsuario()
{

    string line;
    ifstream myfile("usuario.txt");
    

    while(getline(myfile,line)){


      cout<<line<<endl;
    }

      
  myfile.close();

   
   

}

int ficheroUsuarioVacio()
{

      string line;
      string escrito;
       ifstream myfile("usuario.txt");
        
     
       while(getline(myfile,line))
       {
        
        escrito = line;

      
      
       }
       if(escrito == "")
       {
        
        return 1;
       }

      
  
myfile.close();
return 0;
}
void Usuario::ordenarUsuario(){

if(leerVerificar()==1)
{


    string line;
    ifstream myfile("usuario.txt");
    vector <string> usuarios;

    while(getline(myfile,line)){

      usuarios.push_back(line);
      
    }
    remove("usuario.txt");
    ofstream file("usuario.txt");

    sort(usuarios.begin(),usuarios.end());

    for(int i=0;i<usuarios.size();i++)
    {
      
      file << usuarios[i] << endl;
    }
      
  myfile.close();

}

}
int verificarUsuario(string nombre)
{
  
string line;
ifstream myfile("usuario.txt");
vector <string> usuarios;

while(getline(myfile,line))
{

  if(line == nombre)
  {
    cout << "usuario verificado" << endl;
    return 0;
    break;
  }
}
return 1;


}
void Usuario::modificarUsuario(string nombre)
{


    string line;
    ifstream myfile("usuario.txt");
    vector <Usuario> usuarios;

    while(getline(myfile,line))
    {
      Usuario u;
      u.setNombre(line);

      usuarios.push_back(u);
      
    }

    remove("usuario.txt");

    ofstream file("usuario.txt");

    for(int i=0;i<usuarios.size();i++)
    {
      if(usuarios[i].getNombre()==this->getNombre())
      {

        
        usuarios[i].setNombre(nombre);
        break;
      }
      
    }

      for(int i=0;i<usuarios.size();i++)
    {
      cout << usuarios[i].getNombre() << endl;
      file << usuarios[i] << endl;
    }

    

      file.close();
  myfile.close();

}
void Usuario::eliminarUsuario(){
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


    
    ifstream myfile("usuario.txt");
    vector <Usuario> usuarios;

    while(getline(myfile,line))
    {
      Usuario u;
      u.setNombre(line);

      usuarios.push_back(u);
      
    }
    remove("usuario.txt");
    sscanf(this->nombre.c_str(), "%s\n",ayuda4);
    sprintf(ayuda4, "%s.txt", fichero);
    


    ofstream file("usuario.txt");
  for(int i=0;i<usuarios.size();i++)
    {
      if(usuarios[i].getNombre()==nombre)
      {
      
        sscanf(this->nombre.c_str(), "%s\n",ayuda1);
        sprintf(ayuda2, "%s.txt", ayuda1);
        remove(ayuda2);
        usuarios.erase(usuarios.begin()+i);
        
        break;
        
      }
      
    }
    for(int i=0;i<usuarios.size();i++){
       file << usuarios[i] << endl;


    }
remove(fichero);


        file.close();
  myfile.close();
  free(ayuda1);
  free(ayuda4);
  free(ayuda2);
  free(fichero);




}
void Usuario ::usuariojugador()
{
  char* str2 = (char*) malloc (sizeof(char)*MAX_LENGTH)+1;
   char* fichero = (char*) malloc (sizeof(char)*MAX_LENGTH)+1;

	sscanf(this->nombre.c_str(), "%s\n",str2);
        sprintf(fichero, "%s.txt", str2);

      string line;
      string escrito;
       ifstream myfile(fichero);
        
     
       while(getline(myfile,line))
       {
        
        escrito = line;

       cout << line << endl;
      
       }
       if(escrito == "")
       {
        cout << "Este usuario no tiene jugadores" << endl;
       }

      
	
myfile.close();
free(str2);
free(fichero);
	




}
void comprobar()
{
  

if(leerVerificar()==0)
{
 printf("Primero debers introducir un usuario para iniciar sesion\n"); 

}
else
{

cout << "Introduce tu id para iniciar sesion" << endl;
leerUsuario();
string nombre;
cin >> nombre;

string fichero = nombre +".txt";



if(!(fopen(fichero.c_str(), "r")))
{
  printf("El usuario que has introducido no existe\n");
}
else
{
 
  cout << "Bienvenido " << nombre << "!" << endl << endl;

  
  }
 }

}


Usuario::Usuario()
{

  this->nombre = "Nombre";
}

Usuario::Usuario(string nombre)
{

  this->nombre = nombre;
}
Usuario::~Usuario()
{

}


  string Usuario::getNombre() const
  {
    return this->nombre;

  }
  ostream& operator<<(ostream &out, const Usuario &p){

    out<<p.nombre;
    return out;


  }
  
 istream& operator>>(istream &in, Usuario &p){

 	string a;
 	

 	cout<<"nombre: "<<endl;
 	cin>>a;
 	
 	p.setNombre(a);

 	return in;
 }








