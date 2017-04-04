#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>


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

void introducirnom(){

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
  f = fopen("usuario.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((a = fgetc(f)) != EOF)
    {
      if (a != '\n')
      {
	 
     
      putchar(a);

     
      printf("\n");

    
  }
  
    }


  //cerrar fichero
  fclose(f);


}

void comprobar(){

  //sscanf(c,"%d",&b);
   FILE* file;
   int a[20];
   char *b;
   int h;
  //char c;
  //int a;
   int f;
   f=0;
  
  //abrir fichero para lectura
  file = fopen("usuario.txt", "r");
  
  //leer mientras no se llegue al final del fichero EOF
  while ((h = fgetc(file)) != EOF)
    {
      

    a[f]=h;
     
      

    
  }
  
    


  //cerrar fichero
 
  int e;
  int q;
  printf("Introduzca el id\n");
  fgets(b,10,stdin);
  sscanf(b,"%d",&e);
  int tam;
  tam=0;
while (a[tam]!='\0') 
tam++;
  if(a[tam]==e){
    q=0;
  }
  

if(q==0){


  printf("Incorrecto\n");

}
else{
  printf("correcto\n");
}
 fclose(file);
}

    




