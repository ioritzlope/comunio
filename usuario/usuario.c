#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10

/*
void introducirUsuario()
{
printf("\n");

printf("Introduce el id del usuario\n");

int len = 0;
char *str;

char *str2;


//str2=(char*) malloc (sizeof(char)*20);
//char *str3;



do
{
fgets(str, 20, stdin);
len = sscanf(str,"%s",&id);

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
*/
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

//void introducircon(){
//  int len = 0;
//char *str;
//char *str2;
//int id;
//int contra;
//printf("Introduce una contraseña\n");

//do
//{
//fgets(str2, 20, stdin);
//len = sscanf(str2,"%d",&contra);

//if(len==0){
//  printf("Por favor, la contrasena tiene que ser un numero\n");
//}


//}while(len==0);

//FILE * file;
//int c;
//
//file=fopen("usuario(con).txt","a");


//fprintf(file, "%d\n",contra);
//fclose(file);
//}


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
  /*
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
              printf("correcto\n");
    
              

        }
       else{

        printf("incorrecto\n");
       
       } 
       
        printf("%s\n", c);

 
 }  

}
//clear_if_needed(c);

  //cerrar fichero
  fclose(f);

  */


char* idUsuario;
char* str;
char* nombreFichero;

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
}



free(idUsuario);
free(str);
free(nombreFichero);





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


    




