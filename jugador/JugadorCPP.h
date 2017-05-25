#ifndef _JUGADORCPP_H_
#define _JUGADORCPP_H_


#include <string>
using namespace std;


int leerPuntosJugador(string fichero);
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

	string getNombre() const;
	string getApellido() const;
	int getPuntos() const;
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setPuntos(int puntos);

	void verPuntosJugador();



};

/*
int leerFichero();
void insertarJugador();
void verPuntosJugador(char* str);
void puntuarJugador();
void pasarDatosAFichero(char* nom, char* apellido, int num);
void clear_if_Needed(char *str);
*/

#endif