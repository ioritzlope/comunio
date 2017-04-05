#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introducirUsuario()
{
printf("\n");

printf("Introduce el id del usuario\n");

int len = 0;
char *str;
char *str2;
int id;
int contra;
//char* nombre=(char*) malloc (sizeof(char)*20);
//char *str3;



do
{
fgets(str, 20, stdin);
len = sscanf(str,"%d",&id);

if(len==0){
	printf("Por favor, el id tiene que ser un numero\n");
}


}while(len==0);


printf("Introduce una contraseña\n");

do
{
fgets(str2, 20, stdin);
len = sscanf(str2,"%d",&contra);

if(len==0){
	printf("Por favor, la contrasena tiene que ser un numero\n");
}


}while(len==0);





printf("Introduce un nombre\n");


//fgets(str3, 20, stdin);
//sscanf(str3,"%s",*nombre);



FILE * file;
int c;

file=fopen("usuario.txt","a");

fprintf(file, "%d\n",id );
fprintf(file, "%d\n",contra);
fprintf(file, "\n");
//fprintf(file, "%d\n",nombre );
fclose(file);



}
void introducirid(){
printf("\n");

printf("Introduce el id del usuario\n");

int len = 0;
char *str;
char *str2;
int id;
int contra;
//char* nombre=(char*) malloc (sizeof(char)*20);
//char *str3;



do
{
fgets(str, 20, stdin);
len = sscanf(str,"%d",&id);

if(len==0){
  printf("Por favor, el id tiene que ser un numero\n");
}


}while(len==0);

FILE * file;
int c;

file=fopen("usuario(id).txt","a");

fprintf(file, "%d\n",id );

fclose(file);


}

void introducircon(){
  int len = 0;
char *str;
char *str2;
int id;
int contra;
printf("Introduce una contraseña\n");

do
{
fgets(str2, 20, stdin);
len = sscanf(str2,"%d",&contra);

if(len==0){
  printf("Por favor, la contrasena tiene que ser un numero\n");
}


}while(len==0);

FILE * file;
int c;

file=fopen("usuario(con).txt","a");


fprintf(file, "%d\n",contra);
fclose(file);
}


void leerUsuario()
{
  char *c;
  char g[20];
  int b;
	//printf("Mete el id\n");
  //fgets(g,10,stdin);
  //sscanf(c,"%d",&b);
	 FILE* f;
  //char c;
  int a;
  
  //abrir fichero para lectura
  f = fopen("usuario(id).txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((a = fgetc(f)) != EOF)
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
  fclose(f);


}
//tiene que comprobar una cadena de caracteres (el fichero usuario(id)) con otra cadena del que le mete el usuario. 
void comprobar()
{
char b[6];
char c[6];

printf("Introduzca el id, recuerda que tienen que contener 5 numeros\n");
  //fgets(b,10,stdin);
    fscanf(stdin, "%s", b);
  fflush(stdin);
  
printf("el id elegido es %s\n",b);


   FILE* f;
  //char c;
  char a;
  int q;
  q=0;
  int num;
  num=0;
  //abrir fichero para lectura
  f = fopen("usuario(id).txt", "r");

  //leer mientras no se llegue al final del fichero EOF
  while ((a = fgetc(f)) != EOF)
    {
      
      if (a != '\n')
      {
         
          c[num]=a;
          num++;     
      //putchar(a);

     
      //printf("\n");

        

    
  }
    else{
//printf("%s\n",c );
    if(strcmp(b, c)==0){
              q=1;
              break;

        }

  }
  
}
    if(q==1){
      printf("correcto\n");

    }
    if(q==0){
      printf("Incorrecto\n" );
    }

clear_if_needed(c);

  //cerrar fichero
  fclose(f);
}
//comprueba un caracter del fichero usuario(id) con otro caracter que le mete el usuario. (esta bien)
void comprobar2()
{
char b[20];
char e;
printf("Introduzca el id\n");
  fgets(b,10,stdin);
  sscanf(b,"%c",&e);
printf("el id elegido es %c\n",e);


   FILE* f;
  //char c;
  char a;
  int q;
  q=0;
  
  //abrir fichero para lectura
  f = fopen("usuario(id).txt", "r");
  printf("los id-es del sistema son:\n");
  //leer mientras no se llegue al final del fichero EOF
  while ((a = fgetc(f)) != EOF)
    {
      if (a != '\n')
      {
   
     
      putchar(a);

     
      printf("\n");

        if(a==e){
              q=1;

        }

    
  }
  
    }
    if(q==1){
      printf("correcto\n");
    }
    else{
      printf("Incorrecto\n" );
    }


  //cerrar fichero
  fclose(f);





}


    




