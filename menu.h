#ifndef _MENU_H_
#define _MENU_H_

#ifdef __cplusplus
extern "C"{
	#endif

void clear_if_needed(char *str);
int menu();
void ventanaInicial();
void elegirOpcion(int opcion);
void llamadaOrdenarUsuarios();
void llamadaModificarUsuario();
void llamadaeliminarusuario();
void llamadausuariojugador();
void llamadaPuntosJugador();
#ifdef __cplusplus

}

#endif

#endif

