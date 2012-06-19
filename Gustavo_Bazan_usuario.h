/*
  Name: Gustavo_Bazan_usuario.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase usuario, contendra la informacion relacionada con un usuario, y todos los metodos
               relacionados con este.
*/

#ifndef __USUARIO_H__
#define __USUARIO_H__

/************************************USUARIO***********************************/

class usuario 
BEGIN
     private:
         int dinero;
         lista<int> canciones;
         char modo_reproduccion[LONG];        
             
     public:
         // Constructor por defecto
         usuario();
         
         void set_dinero(int );
         /*
         Da valor al dinero introdusido por el ususario
         Parámetros de entrada y sus roles: le entra un entero(din) q sera el valor a dar al dinero.
         Valor devuelto: Nada
         */
         int get_dinero();
         /*
         Devuelve el dinero del usuario
         Valor devuelto: un entero, el dinero del usuario.
         */
         void set_cancion(int , int );
         /*
         Inserta una cancion en la lista de canciones
         Parámetros de entrada y sus roles: le entra un entero(pos) q es a posicion a inertar el codigo, entero(cd) q sera el valor a insertar en canciones.
         Precondiciones de los valores de los parámetros: 0<=pos<=get_nro_canc() (posicion valida).
         Valor devuelto: Nada
         */
         void eliminar_cancion(int );
         /*
         Elimina una cancion en la lista de canciones
         Parámetros de entrada y sus roles: le entra un entero(pos) q es a posicion a eliminar.
         Precondiciones de los valores de los parámetros: 0<=pos<=get_nro_canc() (posicion valida).
         Valor devuelto: Nada
         */
         int get_cancion(int );
         /*
         Devuelve la cancion i de la lista de canciones
         Parámetros de entrada y sus roles: le entra un entero (pos) q sera el valor de la posicion a consultar en canciones
         Precondiciones de los valores de los parámetros: 0<=pos<=get_nro_canc() (posicion valida).
         Valor devuelto: entero
         */
         void set_modo_reproduccion(char* );
         /*
         Da valor al modo de reproduccion introdusido por el ususario
         Parámetros de entrada y sus roles: le entra una cadena(modo) q sera el valor a dar al modo_reproduccion.
         Valor devuelto: Nada
         */
         char* get_modo_reproduccion();
         /*
         Devuelve el modo de reproducion seleccionado por el usuario
         Valor devuelto: string(modo_reproduccion);
         */
         int get_nro_canc();
         /*
         Devuelve el numero de canciones q compone la lista de canciones
         Valor devuelto: entero
         */
         void mostrar_data();
         /*
         Muestra por pantalla el contenido de usuario
         Valor devuelto: Nada
         */
         void copiar (usuario *);
         /*
         Copia el contenido de un usuario al q hace la llamada
         Parámetros de entrada y sus roles: un usuario, que sera del cual se tomara la informacion a asignar
         Valor devuelto: Nada
         Condiciones de error tratados dentro de cada acción: Se hace la lista de canciones vacia para asegurar q quien llama la funcion solo obtenga los valores q se le quieren copiar y no concerve anteriores
         */
        
END;

/***********************************Nodo CD************************************/

class nodo_us
BEGIN
    private:
        usuario elem;
        nodo_us* prox;
	
	public:
        // Constructor por defecto
        nodo_us(void);
        
        void set_elemento(usuario *);
        /*
        Le asigna el contenido de un usuario al elemento del nodo(elem).
        Parámetros de entrada y sus roles: un usuario, que sera del cual se tomara la informacion a asignar
        Valor devuelto: Nada
        */
        usuario* get_elemento();
        /*
        Devuelve el elemento del nodo(un usuario).
        Valor devuelto: cd
        */
        void set_ptr(nodo_us* );
        /*
        Da valor al puntero q almacena la direccion del nodo proximo.
        Parámetros de entrada y sus roles: un ptr nodo_us (p) q sera el valor a signarle a prox
        Valor devuelto: Nada
        */
	    nodo_us* get_ptr();
	    /*
        Devuelve el puntero  al proximo nodo.
        Valor devuelto: ptr nodo_us;
        */
        	    
END;

/***********************************Listas*************************************/

class lista_us
BEGIN
	protected:
		nodo_us* ptr;
        int ultimo;
		
	public:
		// Constructor por defecto
		lista_us (void);

		// Destructor
		~lista_us(void);
		
		void vacia();
		/*
        Elimina todos los elementos de la lista para asi hacerla vacia.
        Valor devuelto: Nada
        */
		bool es_vacia();
		/*
        Devuelve verdadero si la lista esta vacia o falso en caso contrario.
        Valor devuelto: logico
        */
		void insertar(int , usuario* );
		/*
        Inserta el usuario a en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a insertar. usuario a, el usuario a insertar en la lista.
        Valor devuelto: Nada
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        Condiciones de error tratados dentro de cada acción: se valida para q se pueda incertar cuando la lista es vacia.
        */
		void eliminar(int );
		/*
        Elimina el cd en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a eliminar.
        Valor devuelto: Nada
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        Condiciones de error tratados dentro de cada acción: se valida en caso de eliminar la primera posicion.
        */
		usuario* consultar(int );
		/*
        Devuelve el valor del usuario en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a consultar.
        Valor devuelto: usuario
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        */
		int longitud();
		/*
        Devuelve la longitud de la lista (ultimo).
        Valor devuelto: entero
        */
		bool esta(usuario *);
		/*
        Devuelve verdadero si el usuario consultado se encuentra en la lista o falso en caso contrario.
        Parámetros de entrada y sus roles: usuario a, el usuario a consultar en la lista.
        Valor devuelto: logico
        */
		usuario* primero( );
		/*
        Devuelve el valor del usuario en la primera posicion.
        Valor devuelto: usuario
        */
		void resto( );
		/*
        Elimina el usuario en la primera posicion.
        Valor devuelto: Nada
        Condiciones de error tratados dentro de cada acción: se valida q la lista no este vacia, para luego proceder a eliminar.
        */
		void mostrar_lista();
		/*
        Muestra todos los elementos de la lista.
        Valor devuelto: Nada
        */
END;    

/*************************************Pilas************************************/

class cola_us : private lista_us
BEGIN	
    
    public:
		// Constructor por defecto
		cola_us ();
		
		// Destructor
		~cola_us(void);
		
		void vacia();
		/*
        Elimina todos los elementos de la cola para asi hacerla vacia.
        Valor devuelto: Nada
        */
		bool es_vacia();
		/*
        Devuelve verdadero si la cola esta vacia o falso en caso contrario.
        Valor devuelto: logico
        */
		void encolar(usuario* );
		/*
        Encola el usuario en la ultima posicion.
        Parámetros de entrada y sus roles: usuario e, el elemento a encolar.
        Valor devuelto: Nada
        */
		void desencolar();
		/*
        Desencola el elemento en la primera posicion.
        Valor devuelto: Nada
        */
		usuario* frente();
		/*
        Devuelve el valor del elemento en la primera posicion.
        Valor devuelto: usuario.
        */
		void mostrar_cola();
		/*
        Muestra todos los elementos de la cola.
        Valor devuelto: Nada
        */
         
END;

#endif
