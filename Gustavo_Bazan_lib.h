/*
  Name: Gustavo_Bazan_lib.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: La empresa “Aparatos Musicales C.A.” desea desarrollar un prototipo de Rockola para
               distribuirla entre sus clientes. La Rockola es un aparato del tipo Vending Machine que tiene la
               finalidad de ejecutar canciones sobre pedido; es decir, cuando una persona accede a la
               Rockola, le indica mediante algún mecanismo de interacción cuales canciones quiere oír y en
               que orden. Para activar el mecanismo de selección de canciones la persona debe primero
               depositar en una ranura la cantidad total de dinero (o fichas) que sea requerido según las
               especificaciones que generalmente se encuentran adosadas al aparato.
*/

#ifndef __GUSTAVO_BAZAN_LIB_H__
#define __GUSTAVO_BAZAN_LIB_H__

/* Declaracion de Librerias */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

//Constantes
#define BEGIN {
#define END }

#define DIV /
#define MOD %

#define LONG 30

/* Declaracion de Librerias */
#include "Gustavo_Bazan_nodo.h"
#include "Gustavo_Bazan_lista.h"
#include "Gustavo_Bazan_artista.h"
#include "Gustavo_Bazan_album.h"
#include "Gustavo_Bazan_cancion.h"
#include "Gustavo_Bazan_cd.h"
#include "Gustavo_Bazan_rockola.h"
#include "Gustavo_Bazan_usuario.h"

//Declaracion de Protipos

int compararcadenas(char *, char *); //compara cadenas caracter a caracter con tolower
void carga_artistas(lista<artista>* ); //Carga del archivo de entrada artistas.in
void carga_albumes(lista<album>* ); //Carga del archivo de entrada albumes.in
void carga_canciones(lista<cancion>* ); //Carga del archivo de entrada canciones.in
bool verificar_canciones(usuario* , lista<cancion>* ); //Verifica q los codigos introducidos por el usuario sean validos
int monto(int , int ); //Determina el monto de la solisitud hecha por un usuario
int crearlog(usuario* , int , lista<cancion>* , ofstream* ); //crea el archivo de salida log.out
void carga_rockola(cola_us* , cola_us*, lista<cancion>* ); //Carga del archivo de entrada rockola.in
bool por_tomar(bool tomado[], int ); //Determina si quedan canciones por reproducir en la lista del usuario
int procesar_usuarios(rockola* , cola_us* , int* , ofstream* , int ); //Toma una cola de usuarios y procesa todas las solicitudes hechas por estos

#endif
