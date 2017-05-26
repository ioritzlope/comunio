#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#ifdef __cplusplus
extern "C"{
	#endif

void leerFichero();
int leerVerificarJ();
void insertarJugador();
void verPuntosJugador(char* str);
void puntuarJugador();
void pasarDatosAFichero(char* nom, char* apellido, int num);
void clear_if_Needed(char *str);
#ifdef __cplusplus
}
#endif

#endif