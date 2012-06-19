/*
  Name: Gustavo_Bazan_album.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase album.
*/

#ifndef __ALBUM_CPP__
#define __ALBUM_CPP__

#include "Gustavo_Bazan_lib.h"

/*************************************ALBUM************************************/
// Constructor por defecto
album :: album()
BEGIN
	codigo=0;
	strcpy(titulo,"");
END

// Constructor general
album :: album(int cod, char* tit)
BEGIN
    codigo=cod;
	strcpy(titulo,tit);
END

// Constructor de copia
album :: album(const album& c)
BEGIN
	codigo = c.codigo;
	strcpy(titulo,c.titulo);
END

void album :: set_codigo(int cod)
BEGIN
	codigo=cod;
	return;
END

void album :: set_titulo(char* tit)
BEGIN
	strcpy(titulo,tit);
	return;
END

int album :: get_codigo()
BEGIN
	return(codigo);
END

int album :: get_codigo_art()
BEGIN
	return(codigo DIV 1000);
END

int album :: get_pos()
BEGIN
	return(codigo MOD 1000);
END

char* album :: get_titulo()
BEGIN
	return(titulo);
END

// operador miembro de asignación sobrecargado
album& album :: operator= (const album &a){
	codigo = a.codigo;
	strcpy(titulo,a.titulo);
	return (*this);
}

// operador friend de test de igualdad sobrecargado
int operator== (const album &a, const album &b){
	if (a.codigo==b.codigo) return 1;
	else return 0;
}

// operador friend << sobrecargado
ostream& operator << (ostream& co, const album &alb){
	co << alb.codigo;
	co << " ";
	co << alb.titulo;
	return co;
}

// operador friend >> sobrecargado
istream& operator >> (istream& ci, album &alb){
	ci >> alb.codigo;
	ci >> alb.titulo;
	return ci;
}

#endif
