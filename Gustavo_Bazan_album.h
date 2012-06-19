/*
  Name: Gustavo_Bazan_album.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase album, contendra la informacion relacionada con un album, y todos los metodos
               relacionados con este.
*/

#ifndef __ALBUM_H__
#define __ALBUM_H__

/*************************************ALBUM************************************/

class album
BEGIN
	private:
		int codigo;
		char titulo[LONG];
	
	public:
		// Constructor por defecto
		album();
		// Constructor general
		album(int , char* );
		//Constructor de copia
		album(const album&);   
		
		void set_codigo(int );
		/*
		Da valor al codigo del album
        Parámetros de entrada y sus roles: le entra un entero(cod) q sera el valor a dar al codigo
		Valor devuelto: Nada
		*/
		void set_titulo(char* );
		/*
		Da valor al titulo del album
		Parámetros de entrada y sus roles: le entra una cadena(tit) q sera el valor a dar al titulo
		Valor devuelto: Nada
		*/
		int get_codigo();
		/*
		Devuelve el codigo del album
		Valor devuelto: un entero, el codigo del album.
		*/
		int get_codigo_art();
		/*
		Devuelve el codigo del artista q interpreta el album
		Valor devuelto: un entero, el codigo del artista.
		*/
		int get_pos();
		/*
		Devuelve el codigo de la posicion q ocupa el album en la rockola
		Valor devuelto: un entero, la posicion del album.
		*/
		char* get_titulo();
		/*
		Devuelve el titulo del album
		Valor devuelto: una cadena, el titulo del album.
		*/
		
		// Sobrecarga del operador de asignación
		album& operator= (const album&);        
		// operador friend de test de igualdad sobrecargado
		friend int operator== (const album&, const album&);
		// Sobrecarga del operador de inserción en el flujo de salida
		friend ostream& operator<< (ostream&, const album&);
		// Sobrecarga del operador de inserción en el flujo de entrada
		friend istream& operator>> (istream&, album&);
		
END;

#endif
