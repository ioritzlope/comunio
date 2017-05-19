#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>

using namespace std;


class Usuario
{
private:
	string nombre;
	string apellido;
	int puntos;

public:
	Usuario();
	Usuario(string nombre, string apellido, int puntos);
	~Usuario();

	string getNombre() const;
	string getApellido() const;
	int getPuntos() const;

	//void ordenarUsuarios();
	friend istream& operator>>(istream &in, Usuario &p);

	
};
/*

void clear_if_needed(char *str);
//void introducirid(char* fichero, char* str2);
int leerUsuario();
void comprobar();


*/






#endif