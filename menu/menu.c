#include <stdio.h>
#include <string.h>
#include "menu.h"
#define MAX_LENGTH	10
#define MAX_ASIGNATURAS 5

void clear_if_needed(char *str);


int menu()
{
char str[MAX_LENGTH];
	int len;
	int option;

	do {
		printf("\t1. Introducir nuevo Usuario \n");
		printf("\t2. Introducir nuevo Administrador\n");
		printf("\t3. Introducir nuevo Jugador\n");
		printf("\t4. Ver Puntos por Jugador \n");
		printf("\t5. Ver Usuarios registrados\n");
		printf("\t6. Clasificacion final\n");
		printf("\n");
		printf("Seleccione una opción (q para salir): ");

		fgets(str, MAX_LENGTH, stdin);
		clear_if_needed(str);
		len = sscanf(str, "%i", &option);
		printf("\n");
	} while ((len == 0 && str[0] != 'q') || (len > 0 && (option > 6 || option < 1)));

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
	case 1: printf("Has elegido intrducir un nuevo usuario\n");break;
	case 2: printf("Has elegido intrducir un nuevo administrador\n");break;
	case 3: printf("Has elegido intrducir un nuevo jugador\n");break;
	case 4: printf("puntos jugador\n");break;
	case 5: printf("usuarios registrados\n");break;
	case 6: printf("Clasificacion\n");break;
	

}



}