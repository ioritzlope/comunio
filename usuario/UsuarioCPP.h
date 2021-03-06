#ifndef USUARIOCPP_H_
#define USUARIOCPP_H_

#include <string>
#include <iostream>

using namespace std;


class Usuario
{
private:
	string nombre;
	

public:
	Usuario();
	Usuario(string nombre);
	~Usuario();

	string getNombre() const;
	
	void setNombre(string nombre);
	friend ostream& operator<<(ostream &out, const Usuario &p);
	friend istream& operator>>(istream &in,Usuario &p); 
	void ordenarUsuario();
	void modificarUsuario(string nombre);
	void eliminarUsuario();
	void usuariojugador();

	

	
};
	void comprobar();
void ficheroUsuario();
int ficheroUsuarioVacio();
int verificarUsuario(string nombre);
 istream& operator>>(istream &in, Usuario &p);







#endif