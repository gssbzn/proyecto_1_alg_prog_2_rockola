/*
  Name: Gustavo_Bazan_rockola.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase rockola, contendra la informacion relacionada con una rockola, y todos los metodos
               relacionados con esta.
*/

#ifndef __ROCKOLA_H__
#define __ROCKOLA_H__

#include "Gustavo_Bazan_usuario.h"

/************************************ROCKOLA***********************************/

class rockola
BEGIN
     private:
         pila_cd cds;
         pila_cd temp;
         
     public:
         void set_data(lista<artista>* , lista<album>* , lista<cancion>* );
         /*
         Genera la pila de cds de los cuales dispone la maquina
         Parámetros de entrada y sus roles: lista de artistas, albumes y canciones de nde e obtienen los datos de los cds q componen la rockola.
         Valor devuelto: Nada
         */
         void mostrar_data();
         /*
         Muestra la imformacion de los cds almacenados en el dispositivo principal de la rockola
         Valor devuelto: Nada
         */
         void reproducir(int , ofstream* );
         /*
         Reproduce la cancion deseada
         Parámetros de entrada y sus roles: el codigo de la cancion a reproducir, el flujo de datos al archivo de salida(reporte.out).
         */
         
END;

#endif
