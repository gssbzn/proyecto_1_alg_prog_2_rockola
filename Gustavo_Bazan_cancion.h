/*
  Name: Gustavo_Bazan_cancion.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase cancion, contendra la informacion relacionada con una cancion, y todos los metodos
               relacionados con esta.
*/

#ifndef __CANCION_H__
#define __CANCION_H__

/************************************ARTISTA***********************************/

class cancion
BEGIN
    private:
        int codigo;
        char titulo[LONG];
       
    public:
        // Constructor por defecto
        cancion();
        // Constructor general
        cancion(int , char* );
        // Constructor de copia
        cancion(const cancion&);   
        
        void set_codigo(int );
        /*
        Da valor al codigo de la cancion.
        Parámetros de entrada y sus roles: le entra un entero(cod) q sera el valor a dar al codigo.
        Valor devuelto: Nada.
        */
        void set_titulo(char* );
        /*
        Da valor al titulo de la cancion.
        Parámetros de entrada y sus roles: le entra una cadena(tit) q sera el valor a dar al titulo.
        Valor devuelto: Nada.
        */
        int get_codigo();
        /*
        Devuelve el codigo de la cancion.
        Valor devuelto: un entero, el codigo de la cancion.
        */
        int get_codigo_art();
        /*
        Devuelve el codigo del artista q interpreta la cancion.
        Valor devuelto: un entero, el codigo del artista.
        */
        int get_codigo_cd();
        /*
        Devuelve el codigo de la posicion q ocupa el album en la rockola.
        Valor devuelto: un entero, la posicion del album.
        */
        int get_pos();
        /*
        Devuelve el codigo de la posicion q ocupa la cancion en el album.
        Valor devuelto: un entero, la posicion de la cancion.
        */
        char* get_titulo();
        /*
        Devuelve el titulo la cancion.
        Valor devuelto: una cadena, el titulo la cancion.
        */
        
        // Sobrecarga del operador de asignación
        cancion& operator= (const cancion&);        
        // operador friend de test de igualdad sobrecargado
        friend int operator== (const cancion&, const cancion&);
        // Sobrecarga del operador de inserción en el flujo de salida
        friend ostream& operator<< (ostream&, const cancion&);
        // Sobrecarga del operador de inserción en el flujo de entrada
        friend istream& operator>> (istream&, cancion&);
              
END;

#endif
