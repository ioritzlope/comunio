#include <stdio.h>
#include "jugador.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_PUNTOS 9




void leerFichero()
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
    
 }

 else
 {
  printf("No hay ningun jugador guardado en el sistema\n");
  

 }
  //cerrar fichero
  fclose(file);

 
}
int leerVerificarJ()
{
   FILE* file;


   char c;
   

if(file=fopen("Jugadores.txt","r"))
{
  
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
  printf("Introduce el nombre del jugador\n");
  fgets(str,MAX_LENGTH,stdin);
  sscanf(str,"%s",nombre);

  printf("\nDatos introducidos hasta el momento\n");

  printf("%s\n", nombre);
  

   sprintf(fichero, "%s_.txt", nombre);
   if(fopen(fichero, "r"))
   {
    printf("\nEse Jugador ya existe, tiene que introducir uno nuevo que no este en el sistema\n");
    
   }
   else
   {

printf("Ahora introduce apellido del jugador\n");

   fgets(str2,MAX_LENGTH,stdin);
  sscanf(str2,"%[^\n]s",apellido);
  

 printf("\nDatos introducidos hasta el momento\n");
  printf("%s\n", nombre);
   printf("%s\n", apellido);

printf("Introduce los puntos de este jugador\n");

fgets(str3, MAX_LENGTH, stdin);
sscanf(str3,"%i",&numero);
if(numero>MAX_PUNTOS)
{
  numero = MAX_PUNTOS;
  printf("Has superado el limite maximo de puntos\n");
  printf("Se le asignaran 9 puntos al jugador\n");
}

printf("Datos introducidos hasta el momento\n");
  printf("%s\n", nombre);
   printf("%s\n", apellido);
   printf("%i\n", numero);

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


  char * str;
  str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

  char * fichero3;
  fichero3 = (char*)malloc((sizeof(char)*MAX_LENGTH)+5);
char* nombre3 = (char*) malloc (sizeof(char)*MAX_LENGTH)+1;
char* nombre2 = (char*) malloc (sizeof(char)*MAX_LENGTH)+1;
    


  if(! (file = fopen("Jugadores.txt", "r")))
  {
    file = fopen("Jugadores.txt", "w");
     fprintf(file, "%s, %s\n", nom, apellido);
printf("Jugador guardado correctamente%s\n" );
 
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
     

  printf("Asignar este jugador a usuario: SI/NO\n" );

  char* resp = (char*) malloc(sizeof(char)*MAX_LENGTH)+1;
   char* resp2 = (char*) malloc(sizeof(char)*MAX_LENGTH)+1;
  fgets(resp, MAX_LENGTH, stdin);
  int len = sscanf(resp, "%s\n", resp2);
  char decision [3];
  strcpy(decision, "si");


if(strcmp(resp2, decision)!=0)
{
   /*
   printf("Jugador no asignado a ningun usuario\n");
   if(! (file4 = fopen("jugadoresLibres.txt", "r")))
  {
    file4 = fopen("jugadoresLibres.txt", "w");
    fprintf(file4, "%s, %s\n", nom, apellido);
   
     
  }
  else
  {
    file4 = fopen("jugadoresLibres.txt", "a");
    fprintf(file4, "%s, %s\n", nom, apellido);
  }
*/
  printf("Jugador en estado AGENTE LIBRE\n");
     

}
else
{
  printf("A que usuario le quieres asignar?\n");

  //clear_if_Needed(resp2);



  fgets(nombre3,MAX_LENGTH,stdin);
  sscanf(nombre3, "%s\n", nombre2);

  sprintf(fichero3, "%s.txt", nombre2);



  if(!(file3 = fopen(fichero3, "r")))
  {
    printf("Este usuario no existe, a si que este jugador esta en modo AGENTE LIBRE\n");
  }
  else
  {
  file3 = fopen(fichero3, "a");
  fprintf(file3, "%s, %s\n", nom, apellido);
  printf("Asignacion completada satisfactoriamente\n");
 
  }
fclose(file3);
free(fichero);
free(resp);
free(resp2);
free(nombre2);
free(fichero3);
free(str);
free(nombre3);


}
}

void verPuntosJugador(char* str)
{
  if(leerVerificarJ()==0)
  {
    printf("Tendras que introducir jugadores\n");
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
  
 if( leerVerificarJ()==0)
 {
printf("Tendras que intrducir jugadores\n");

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



/*
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

