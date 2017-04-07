#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10


void introducirid()
{
printf("\n");

printf("Introduce el id del usuario\n");

int len = 0;
char *str;
char *str2;
char *fichero;
int id;
int contra;
char c;
str =(char*) malloc ((sizeof(char)*MAX_LENGTH)+1);
str2 =(char*) malloc ((sizeof(char)*MAX_LENGTH)+1);
fichero=(char*) malloc ((sizeof(char)*MAX_LENGTH)+5);
//char *str3;




fgets(str, MAX_LENGTH, stdin);
len = sscanf(str,"%s\n",str2);


FILE * file;
FILE *file2;
sprintf(fichero, "%s.txt", str2);//para concatenar el nombre del usuario y ".txt"

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

  printf("\nguardado y creado fichero por primera vez\n");
  }
  else
  {
    file = fopen("usuario.txt", "a");
     fprintf(file, "%s\n", str2);

  printf("\nguardado\n");
  }





if(! (file2 = fopen(fichero, "r")))
  {
    file2 = fopen(fichero, "w");
     

  printf("\n creado fichero por primera vez\n");
  }
  
   fclose(file2);
fclose(file);
}



  free(str);
  free(str2);
  free(fichero);


}




void leerUsuario()
{
  
  
	
	 FILE* f;
  char c;
  printf("estos son los usuarios guardados\n");
  
  //abrir fichero para lectura
  f = fopen("usuario.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((c = fgetc(f)) != EOF)
    {
      if (c != '\n')
      {
	 
     
      putchar(c);

     
      

    
  }
  else{

      printf("\n");
  }
  
    }


  //cerrar fichero
  fclose(f);


}
//tiene que comprobar una cadena de caracteres (el fichero usuario(id)) con otra cadena del que le mete el usuario. 
void comprobar()
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


    




