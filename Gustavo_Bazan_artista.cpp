/*
  Name: Gustavo_Bazan_artista.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase artista.
*/

#ifndef __ARTISTA_CPP__
#define __ARTISTA_CPP__

#include "Gustavo_Bazan_lib.h"

/************************************ARTISTA***********************************/
// Constructor por defecto
artista :: artista()
BEGIN
	codigo=0;
	strcpy(nombre,"");
END

// Constructor general
artista :: artista(int cod, char* nom)
BEGIN
	codigo=cod;
	strcpy(nombre,nom);
END

// Constructor de copia
artista :: artista(const artista& c)
BEGIN
	codigo = c.codigo;
	strcpy(nombre,c.nombre);
END

void artista :: set_codigo(int cod)
BEGIN
	codigo=cod;
	return;
END

void artista :: set_nombre(char* nom)
BEGIN
	strcpy(nombre,nom);
	return;
END

int artista :: get_codigo()
BEGIN
	return(codigo);
END

char* artista :: get_nombre()
BEGIN
	return(nombre);
END

// operador miembro de asignación sobrecargado
artista& artista :: operator= (const artista &a){
	codigo = a.codigo;
	strcpy(nombre,a.nombre);
	return (*this);
}

// operador friend de test de igualdad sobrecargado
int operator== (const artista &a, const artista &b){
	if (a.codigo==b.codigo) return 1;
	else return 0;
}

// operador friend << sobrecargado
ostream& operator << (ostream& co, const artista &art){
	co << art.codigo;
	co << " ";
	co << art.nombre;
	return co;
}

// operador friend >> sobrecargado
istream& operator >> (istream& ci, artista &art){
	ci >> art.codigo;
	ci >> art.nombre;
	return ci;
}

#endif
