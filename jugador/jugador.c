#include <stdio.h>
#include "jugador.h"


void leerFichero()
{
	 FILE* file;


	 char c;

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