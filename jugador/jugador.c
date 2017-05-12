#include <stdio.h>
#include "jugador.h"
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 20


void leerFichero()
{
	 FILE* file;


	 char c;
   printf("\nEstos son los jugadores que estan guardados en los ficheros\n");

	 file=fopen("Jugadores.txt","r");

	  while ((c = fgetc(file)) != EOF)
    {

      if (c != '\n')
      putchar(c);
    else
    {
      printf("\n");
    }
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
  int tamanoStr=0;

  char* str3;
  str3 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

    char* fichero;
  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+6);


  printf("\n");
  printf("Introduce el nombre del jugador\n");
  fgets(str,MAX_LENGTH,stdin);
  sscanf(str,"%s",nombre);
  printf("El nombre que has metido es\n");
  tamanoStr=strlen(nombre);
   printf(nombre);

   sprintf(fichero, "%s_.txt", nombre);
   if(fopen(fichero, "r"))
   {
    printf("\nEse Jugador ya existe, tiene que introducir uno nuevo que no este en el sistema\n");
    
   }
   else
   {


   printf("\n\nAhora introduce el apellido del jugador\n");
   fgets(str2,MAX_LENGTH,stdin);
  sscanf(str2,"%s",apellido);
  printf("El apellido que has metido es\n");
 
   printf(apellido);

   printf("\n\nIntroduce los puntos de este jugador\n");

   scanf("%i", &numero);
   printf("Los puntos introducidos son  %d\n", numero);

pasarDatosAFichero(nombre,apellido,numero);
}
}

void pasarDatosAFichero(char* nom, char* apellido, int num)
{

  printf("\nHA llegado a ficheros\n");

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

  printf("guardado y creado fichero por primera vez\n");
  }
  else
  {
    file = fopen("Jugadores.txt", "a");
     fprintf(file, "%s, %s\n", nom, apellido);

  printf("guardado\n");

  }

 
  fclose(file);


  sprintf(fichero, "%s_.txt", nom);//para concatenar el nombre del jugador y ".txt"

if(! (file2 = fopen(fichero, "r")))
  {
    file2 = fopen(fichero, "w");
    fprintf(file2, "%i\n", num);
     

  printf("\n creado fichero por primera vez\n");
  }
  else
  {
    file2 = fopen(fichero, "a");
    fprintf(file2, "%i\n", num);
  }
fclose(file2);
     

  printf("\nguardado\n");
clear_if_Needed(str);
  printf("\n");
  printf("A que usuario le quieres asignar este jugador?\n");//aqui me da error



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

void verPuntosJugador()
{
  char* str;
  char* fichero;
  char* nombre;
  char c;

  FILE* f;

  fichero = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  nombre = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  
  leerFichero();

printf("Introduce el nombre del jugador que quieres ver sus puntos\n");

fgets(str, MAX_LENGTH, stdin);
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


leerFichero();
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



/**
  Esta funcion elimina los caracteres pendientes si es necesario
  Se usa junto con fgets para leer la entrada hasta cierta longitud
*/
void clear_if_Needed(char *str)
{
  if (str[strlen(str) - 1] != '\n')
  {
    int c;    
      while ( (c = getchar()) != EOF && c != '\n');
    }
}


