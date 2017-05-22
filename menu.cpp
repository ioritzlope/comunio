#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include "usuario/usuario.h"
#include "usuario/UsuarioCPP.h"
#include "jugador/jugador.h"
#include "jugador/JugadorCPP.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#define MAX_LENGTH	50

using namespace std;


void ventanaInicial()
{



printf("\nAdelante, elige una opcion\n");
printf("----------------\n");
printf("----------------\n");



int opcion=0;
opcion = menu();
elegirOpcion(opcion);



}
int menu()
{
char str[MAX_LENGTH];
	int len;
	int option;

	do {
		printf("\t1. Registrar Usuario \n");
		printf("\t2. Iniciar sesion usuario\n");
		printf("\t3. Ver usuarios registrados\n");
		printf("\t4. Introducir nuevo Jugador y asignar a usuario\n");
		printf("\t5. Ver Puntos por Jugador\n");
		printf("\t6. Ver Todos los jugadores guardados \n");
		printf("\t7. Puntuar Jugador\n");
		printf("\t8. Ordenar usuarios por nombre\n");
		printf("\t9. Modificar nombre de usuario\n");
		printf("Seleccione una opción (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%i", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 9 || option < 1)));

	return (str[0] == 'q')?0:option;


}

/**
	Esta funcion elimina los caracteres pendientes si es necesario
	Se usa junto con fgets para leer la entrada hasta cierta longitud
*/
void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}

void elegirOpcion(int opcion)
{

switch(opcion)
{
	case 1: 

		printf("Has elegido registrar un nuevo usuario\n");


		
		char *str;
		char *str2;
		char *fichero;

		str =(char*) malloc ((sizeof(char)*MAX_LENGTH)+1);
		str2 =(char*) malloc ((sizeof(char)*MAX_LENGTH)+1);
		fichero=(char*) malloc ((sizeof(char)*MAX_LENGTH)+5);

			printf("Introduce el nombre del usuario a registrar\n");



		fgets(str, MAX_LENGTH, stdin);
		sscanf(str,"%s\n",str2);



		sprintf(fichero, "%s.txt", str2);//para concatenar el nombre del usuario y ".txt"

		printf("Procesando informacion...\n");
  
		introducirid(fichero, str2);

  		free(str);
 		 free(str2);
 		 free(fichero);


		//introducirid();
 		ventanaInicial();
 		break;


	case 2: 

		printf("Has elegido introducir iniciar sesión\n");

		
		comprobar();
		ventanaInicial();
		break;

	case 3: 


		printf("Has elegido ver los usuarios registrados\n");

		leerUsuario();
		ventanaInicial();
		break;
	

	case 4: 
	/*
		char* str4;
  		str4 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

  		char* str5;
  		str5 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  

  		char* str6;
 		 str6 = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);

		printf("Has elegido introducir un nuevo jugador\n");
		printf("Introduze el nombre del jugador\n");
		fgets(str4,MAX_LENGTH,stdin);
		printf("Introduzca el apellido del jugador\n");
		fgets(str5,MAX_LENGTH,stdin);
		printf("Intoduzca los puntos del jugador\n");
		fgets(str6,MAX_LENGTH,stdin);
		*/
		insertarJugador();
		
		ventanaInicial();
		break;
	

	case 5: 

		printf("puntos jugador\n");

		 if(leerFichero()==0)
  		{
   		 printf("Tendras que introducir jugadores\n");
  		}
  		else{

  		char* str;
  		str = (char*)malloc((sizeof(char)*MAX_LENGTH)+1);
  		printf("Introduce el nombre del jugador que quieres ver sus puntos\n");
  		fgets(str, MAX_LENGTH, stdin);

  		verPuntosJugador(str);


  			}

		//verPuntosJugador();
		ventanaInicial();
		break;
	

	case 6: 

		printf("Has elegido la opcion de ver todos los jugadores guardados\n");

		leerFichero();
		ventanaInicial();
		break;
	

	case 7: 

		printf("Has elegido la opcion de puntuar a jugador\n");

		puntuarJugador();
		ventanaInicial();
		break;


	case 8:

		printf("Has elegido ordenar usuarios por nombre\n");
		
		llamadaOrdenarUsuarios();
		ventanaInicial();

		break;
	

	case 9:

	cout << "Has elegido modificar usuario por nombre" << endl;

	llamadaModificarUsuario();
	cout << "usuarios ordenados alfabeticamente y guardados en fichero" << endl;
	ventanaInicial();
	break;


}



}

void llamadaOrdenarUsuarios()
{
	Usuario u("");


u.ordenarUsuario();
	
}
void llamadaModificarUsuario()
{
	Usuario a("");
	
	if(leerUsuario()==0)
	{
		cout << "Primero debes introducir usuarios" << endl;
	}

	else
	{	
		

		cout << "Que usuario quieres cambiar?" << endl;
		string nombre;
		cin >> nombre;
		a.setNombre(nombre);

		if(verificarUsuario(nombre)==0)
		{

		cout << "Como quieres que se llame?" << endl;
		string nuevoNombre;
		cin >>nuevoNombre;



		a.modificarUsuario(nuevoNombre);
		}
		else
		{
			cout << "usuario no encontrado" << endl;
		}
	}
}