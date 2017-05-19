#include "Usuario+.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Usuario::Usuario()
{

  this->nombre = "Nombre";
  this->apellido = "Apellido";
  this->puntos = 0;
}

Usuario::Usuario(string nombre, string apellido, int puntos)
{

  this->nombre = "Nombre";
  this->apellido = "Apellido";
  this->puntos = 0;
}


  string Usuario::getNombre() const
  {
    return this->apellido;

  }
  string Usuario::getApellido() const
  {
    return this->apellido;

  }
  int Usuario::getPuntos() const
  {
    return this->puntos;

  }
/*
  void Usuario::ordenarUsuarios()
  {

    /*
    vector<Usuario> usuarios;
    //leer fichero
  char c;
  ifstream ifs("usuarios.txt");
  string file_hdr;
  getline(ifs, file_hdr);

  cout << file_hdr << endl;

  while (!ifs.eof())
  {
    Usuario p
    string p;
    ifs >> p;

    usuarios.pushBack(p)
    cout << p << endl;
  }


  ifs.close();









  }

*/
  istream& operator>>(istream &in, Usuario &p)
{
  string nombre;
  in >> nombre; //para quitar los parentesis y las comas
  return in;  
}



/*
#include "usuario.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10

using namespace std;


void introducirid(char* fichero, char* str2)
{
  FILE* file2;
  FILE* file;



if((file2 = fopen(fichero, "r")))
{
  printf("Ese usuario ya existe en el sistema\n");
}

else
{

  if(! (file = fopen("usuario.txt", "r")))
  {
    file = fopen("usuario.txt", "w");
     fprintf(file, "%s\n", str2);

  cout << "Usuario guardado correctamente" << endl;
  }
  else
  {
    file = fopen("usuario.txt", "a");
     fprintf(file, "%s\n", str2);

 cout << "Usuario guardado correctamente" << endl;
  }





if(! (file2 = fopen(fichero, "r")))
  {
    file2 = fopen(fichero, "w");
     

  
  }
  
   fclose(file2);
fclose(file);
}



 


}




int leerUsuario()
{
  
  
	
	 FILE* f;
  char c;
 
  
  //abrir fichero para lectura

if(f = fopen("usuario.txt", "r"))
 {
  cout << "Estos son los usuarios guardados en el sistema" << endl;
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF)
    {
      if (c != '\n')
        {
	 
     
        putchar(c);

       }
       else
       {

         printf("\n");
       }
  
    }

    return 1;
  } 

  else
  {
    cout << "Todavia no hay ningun usuario registrado" << endl;
    return 0;
  }

  //cerrar fichero
  fclose(f);


}
//tiene que comprobar una cadena de caracteres (el fichero usuario(id)) con otra cadena del que le mete el usuario. 
void comprobar()
{
  

if(leerUsuario()==0)
{
  cout << "Primero debers introducir un usuario para iniciar sesion" << endl;

}
else
{
char* idUsuario;
char* str;
char* nombreFichero;
FILE* file;
int a;
idUsuario = (char *)malloc((sizeof(char)*MAX_LENGTH)+1);
str = (char *)malloc((sizeof(char)*MAX_LENGTH)+1);
nombreFichero = (char *)malloc((sizeof(char)*MAX_LENGTH)+1);
printf("Introduce el id del usuario que quieres buscar\n");
fgets(str, MAX_LENGTH, stdin);
sscanf(str, "%s\n",idUsuario);
sprintf(nombreFichero, "%s.txt", idUsuario);



if(!(fopen(nombreFichero, "r")))
{
  printf("El usuario que has introducido no existe\n");
}
else
{
  printf("Bienvenido %s\n", idUsuario);
  printf("\n");
  printf("Estos son los jugadores que tienes\n");
  file = fopen(nombreFichero, "r");
   while ((a = fgetc(file)) != EOF)
    {
      if (a != '\n')
      {
   
     
      putchar(a);

     
      

    
  }
  else{

      printf("\n");
  }
  
    }


  //cerrar fichero
  fclose(file);


}



free(idUsuario);
free(str);
free(nombreFichero);




}
}


    




*/