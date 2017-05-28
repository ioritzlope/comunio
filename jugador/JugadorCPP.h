#ifndef _JUGADORCPP_H_
#define _JUGADORCPP_H_


#include <string>
using namespace std;


int leerPuntosJugador(string fichero);
int comprobarFicheroVacio();
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
	void modificarJugador(string nombre);
	void eliminarJugador();



};
 istream& operator>>(istream &in, Jugador &p);
 int verificarJugador(string nombre);




#endif