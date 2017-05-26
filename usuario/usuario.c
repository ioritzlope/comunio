#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20




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

 printf("Usuario guardado correctamente\n"); 
  }
  else
  {
    file = fopen("usuario.txt", "a");
     fprintf(file, "%s\n", str2);

 printf("Usuario guardado correctamente\n"); 
  }





if(! (file2 = fopen(fichero, "r")))
  {
    file2 = fopen(fichero, "w");
     

  
  }
  
   fclose(file2);
fclose(file);
}



 


}

int jugadoresLibres()
{
  FILE* file;


   char c;
   

if(file=fopen("jugadoresLibres.txt","r"))
{
  printf("\nEstos son los jugadores que estan libres\n");

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
  printf("No hay ningun jugador libre en el sistema\n");
  return 0;

 }
  //cerrar fichero
  fclose(file);


}



void leerUsuario()
{
  
  
	
	 FILE* f;
  char c;
 
  
  //abrir fichero para lectura

if(f = fopen("usuario.txt", "r"))
 {

 printf("Estos son los usuarios guardados en el sistema\n"); 
  
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

    
  } 

  else
  {
   printf("Todavia no hay ningun usuario registrado\n"); 
   
  }

  //cerrar fichero
  fclose(f);


}
int leerVerificar()
{
  
  
  
   FILE* f;
  char c;
 
  
  //abrir fichero para lectura

if(f = fopen("usuario.txt", "r"))
 {
  return 1;
  
 
  } 

  else
  {
   printf("Todavia no hay ningun usuario registrado\n"); 
    return 0;
  }

  //cerrar fichero
  fclose(f);


}
//tiene que comprobar una cadena de caracteres (el fichero usuario(id)) con otra cadena del que le mete el usuario. 

