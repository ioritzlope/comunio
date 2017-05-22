#ifndef _JUGADORCPP_H_
#define _JUGADORCPP_H_


#include <string>
using namespace std;

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

	string getNombre(){return nombre;};
	string getApellido(){return apellido;};
	int getPuntos(){return puntos;};


};


int leerFichero();
void insertarJugador();
void verPuntosJugador(char* str);
void puntuarJugador();
void pasarDatosAFichero(char* nom, char* apellido, int num);
void clear_if_Needed(char *str);

#endif