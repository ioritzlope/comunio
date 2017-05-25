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
		printf("\t10.Eliminar usuario\n");
		printf("\t11.Ver jugadores que tiene un usuario\n");
		printf("\t12.Ver jugadores registrados con sus puntos\n");
		printf("Seleccione una opción (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%i", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 12 || option < 1)));

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
	
	ventanaInicial();
	break;
	
	case 10:

	cout<<"Has elegido eliminar usuario por nombre"<<endl;

	llamadaeliminarusuario();
	ventanaInicial();
	break;

	case 11:

	cout<<"Has elegido ver los jugadores de cada usuario";
	llamadausuariojugador();
	ventanaInicial();

	break;

	case 12:
	cout << "Has decidido ver la clasificacion de mejores jugadores" << endl;
	llamadaPuntosJugador();
	ventanaInicial();


}



}

void llamadaOrdenarUsuarios()
{
	Usuario u;


u.ordenarUsuario();
	
}
void llamadaModificarUsuario()
{
	Usuario a;
	string nombre;
	char* ayuda1;
	char* ayuda2;
	ayuda1=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
	ayuda2=(char *)malloc((sizeof(char)*MAX_LENGTH)+1);
	char *str2;
	char *fichero;
	str2 =(char*) malloc ((sizeof(char)*MAX_LENGTH)+1);
	fichero=(char*) malloc ((sizeof(char)*MAX_LENGTH)+5);
	vector <string> jugadores;


	if(leerUsuario()==0)
	{
		cout << "Primero debes introducir usuarios" << endl;
	}

	else
	{	
		

		cout << "Que usuario quieres cambiar?" << endl;
		
		cin >> nombre;
		a.setNombre(nombre);


		if(verificarUsuario(nombre)==0)
		{
			
		sscanf(nombre.c_str(), "%s\n",ayuda1);
        sprintf(ayuda2, "%s.txt", ayuda1);

        ifstream ifs(ayuda2);
        string line;

        while(getline(ifs,line))
        {
        	jugadores.push_back(line);
        }
         ifs.close();
         
         

       

		cout << "Como quieres que se llame?" << endl;
		string nuevoNombre;
		cin >>nuevoNombre;

		sscanf(nuevoNombre.c_str(), "%s\n",str2);
        sprintf(fichero, "%s.txt", str2);
        ofstream ofs(fichero);

        for (int i=0;i< jugadores.size();i++)
        {
        	ofs << jugadores[i] << endl;
        }      

		ofs.close();

		a.modificarUsuario(nuevoNombre);



		cout<<"usuario eliminado correctamente"<<endl;
		}
		else
		{
			cout << "usuario no encontrado" << endl;
		}
		
	}
	remove(ayuda2);
}
void llamadaeliminarusuario(){
string nombre;


	Usuario *c=new Usuario("");
if(leerUsuario()==0){

	cout<<"primero introduzca un usuario"<<endl;
}
else{


cout<<"Introduzca el nombre del usuario que quieres eliminar"<<endl;
//cin>>nombre;
cin>>*c;
if(verificarUsuario(c->getNombre())==0){
	cout<<"usuario encontrado"<<endl;
	c->eliminarUsuario();
	cout<<"....Usuario correctamente eliminado"<<endl;

}
else{


	cout<<"usuario no encontrado"<<endl;
}





}




}
void llamadausuariojugador()
{

	Usuario *usu=new Usuario("");

string nombre;
if(leerUsuario()==0){

	cout<<"primero introduzca un usuario"<<endl;
}
else{
	cout<<"¿De que usuario quieres ver?"<<endl;
	//cin>>nombre;
	cin>>*usu;

if(verificarUsuario(usu->getNombre())==0){
	

	usu->usuariojugador();

}
else{
	cout<<"usuario no encontrado"<<endl;
}

}




}

void llamadaPuntosJugador()
{
	Jugador jugador;
	jugador.verPuntosJugador();


}