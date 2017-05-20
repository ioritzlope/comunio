#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>

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
	
	//friend istream& operator>>(istream &in, Usuario &p);

	
};
void ficheroUsuario();
/*

void clear_if_needed(char *str);
//void introducirid(char* fichero, char* str2);
int leerUsuario();
void comprobar();


*/






#endif