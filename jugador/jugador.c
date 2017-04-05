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


  printf("\n");
  printf("Introduce el nombre del jugador\n");
  fgets(str,MAX_LENGTH,stdin);
  sscanf(str,"%s",nombre);
  printf("El nombre que has metido es\n");
  tamanoStr=strlen(nombre);
   printf(nombre);


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

void pasarDatosAFichero(char* nom, char* apellido, int num)
{

  printf("\nHA llegado a ficheros\n");

  FILE * file;

  if(! (file = fopen("Jugadores.txt", "r")))
  {
    file = fopen("Jugadores.txt", "w");
     fprintf(file, "%s, %s, %i\n", nom, apellido, num);

  printf("guardado\n");
  }
  else
  {
    file = fopen("Jugadores.txt", "a");
     fprintf(file, "%s, %s, %i\n", nom, apellido, num);

  printf("guardado\n");

  }

 
  fclose(file);





}