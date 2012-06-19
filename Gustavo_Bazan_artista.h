/*
  Name: Gustavo_Bazan_artista.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase artista, contendra la informacion relacionada con un artista, y todos los metodos
               relacionados con este.
*/

#ifndef __ARTISTA_H__
#define __ARTISTA_H__

/************************************ARTISTA***********************************/

class artista
BEGIN
	private:
		int codigo;
		char nombre[LONG];
	
	public:
		// Constructor por defecto
		artista();
		// Constructor general
		artista(int , char* );
		// Constructor de copia
		artista(const artista&);   
		
		void set_codigo(int );
		/*
		Da valor al codigo del artista
		Parámetros de entrada y sus roles: le entra un entero(cod) q sera el valor a dar al codigo
		Valor devuelto: Nada
		*/
		void set_nombre(char* );
		/*
		Da valor al nombre del artista
		Parámetros de entrada y sus roles: le entra una cadena(nom) q sera el valor a dar al nombre
		Valor devuelto: Nada
		*/
		int get_codigo();
		/*
		Devuelve el codigo del artista
		Valor devuelto: un entero, el codigo del artista.
		*/
		char* get_nombre();
		/*
		Devuelve el nombre del artista
		Valor devuelto: una cadena, el nombre del artista.
		*/
		
		// Sobrecarga del operador de asignación
		artista& operator= (const artista&);        
		// operador friend de test de igualdad sobrecargado
		friend int operator== (const artista&, const artista&);
		// Sobrecarga del operador de inserción en el flujo de salida
		friend ostream& operator<< (ostream&, const artista&);
		// Sobrecarga del operador de inserción en el flujo de entrada
		friend istream& operator>> (istream&, artista&);
              
END;

#endif
