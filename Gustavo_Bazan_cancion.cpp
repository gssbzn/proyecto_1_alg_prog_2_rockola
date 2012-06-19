/*
  Name: Gustavo_Bazan_cancion.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase cancion.
*/

#ifndef __CANCION_CPP__
#define __CANCION_CPP__

#include "Gustavo_Bazan_lib.h"

/*************************************ALBUM************************************/
// Constructor por defecto
cancion :: cancion()
BEGIN
    codigo=0;
    strcpy(titulo,"");
END

// Constructor general
cancion :: cancion(int cod, char* tit)
BEGIN
    codigo=cod;
    strcpy(titulo,tit);
END

// Constructor de copia
cancion :: cancion(const cancion& c)
BEGIN
    codigo = c.codigo;
    strcpy(titulo,c.titulo);
END

void cancion :: set_codigo(int cod)
BEGIN
    codigo=cod;
    return;
END

void cancion :: set_titulo(char* tit)
BEGIN
    strcpy(titulo,tit);
    return;
END

int cancion :: get_codigo()
BEGIN
    return(codigo);
END

int cancion :: get_codigo_art()
BEGIN
    return(codigo DIV 100000);
END

int cancion :: get_codigo_cd()
BEGIN
    return((codigo DIV 100)MOD 1000);
END

int cancion :: get_pos()
BEGIN
    return(codigo MOD 100);
END
char* cancion :: get_titulo()
BEGIN
    return(titulo);
END

// operador miembro de asignación sobrecargado
cancion& cancion :: operator= (const cancion &a){
    codigo = a.codigo;
    strcpy(titulo,a.titulo);
    return (*this);
}

// operador friend de test de igualdad sobrecargado
int operator== (const cancion &a, const cancion &b){
    if (a.codigo==b.codigo) return 1;
    else return 0;
}

// operador friend << sobrecargado
ostream& operator << (ostream& co, const cancion &can){
    co << can.codigo;
    co << " ";
    co << can.titulo;
    return co;
}

// operador friend >> sobrecargado
istream& operator >> (istream& ci, cancion &can){
    ci >> can.codigo;
    ci >> can.titulo;
    return ci;
}

#endif
