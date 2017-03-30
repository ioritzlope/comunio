

#include <stdio.h>
#include "menu/menu.h"
#include "jugador/jugador.h"

int main(void)
{


	printf("Proyecto nuevo en C\n");

	int i = 0;
	i = menu();

	

	 elegirOpcion(i);
	  leerFichero();
	
	return 0;
}