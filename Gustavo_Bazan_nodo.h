/*
  Name: Gustavo_Bazan_nodo.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase nodo y la implementacion de todos sus metodos.
*/

#ifndef __NODO_H__
#define __NODO_H__

/***********************************NODO***************************************/

template <class T>

class nodo
BEGIN
    private:
        T elem;
        nodo<T>* prox;
	
	public:
        //Constructor por defecto
        nodo(void);
                
        void set_elemento(T );
        /*
        Le asigna el contenido del elemento del tipo T al elemento del nodo(elem).
        Parámetros de entrada y sus roles: un e de tipo T, que sera del cual se tomara la informacion a asignar
        Valor devuelto: Nada
        */
        T get_elemento();
        /*
        Devuelve el elemento del nodo.
        Valor devuelto: T
        */
        void set_ptr(nodo* );
        /*
        Da valor al puntero q almacena la direccion del nodo proximo.
        Parámetros de entrada y sus roles: un ptr nodo(p) q sera el valor a signarle a prox
        Valor devuelto: Nada
        */
	    nodo* get_ptr();
	    /*
        Devuelve el puntero  al proximo nodo.
        Valor devuelto: ptr nodo;
        */
        
END;

template <class T> nodo<T> :: nodo(void){
    prox=NULL;
};


template <class T> void nodo<T> :: set_elemento(T e){
     elem=e;
     return;
}

template <class T> T nodo<T> :: get_elemento(){
    return(elem);
}

template <class T> void nodo<T> :: set_ptr(nodo<T>* p){
    prox=p;
    return;
}

template <class T> nodo<T>* nodo<T> :: get_ptr(){
    return(prox);
}

#endif
