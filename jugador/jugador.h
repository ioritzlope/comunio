#ifndef _JUGADOR_H_
#define _JUGADOR_H_

/*
#include <string>


class Jugador
{
private:
	string nombre;
	string apellido;
	int puntos;

public:
	Jugador();
	Jugador(string nombre, string apellido, int puntos);
	~Jugador();

	getNombre(){return nombre;};
	getApellido(){return apellido;};
	getPuntos(){return puntos;};


};
*/

int leerFichero();
void insertarJugador(char* str, char* str2, char* str3);
void verPuntosJugador(char* str);
void puntuarJugador();
void pasarDatosAFichero(char* nom, char* apellido, int num);
void clear_if_Needed(char *str);

#endif