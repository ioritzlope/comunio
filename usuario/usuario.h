#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct 
{
	unsigned int id;
	unsigned int contra; 
	char* nombre;


	
}Usuario;
void clear_if_needed(char *str);

//void introducirUsuario();
void introducirid();


void leerUsuario();

void comprobar();
void comprobar2();









#endif