/*
  Name: Gustavo_Bazan_cd.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase cd, contendra la informacion relacionada con un cd, y todos los metodos
               relacionados con este.
*/

#ifndef __CD_H__
#define __CD_H__


/***************************************CD*************************************/

class cd
BEGIN
    private:
        int codigo;
        char nombre_art[LONG];
        char titulo_alb[LONG];
        lista<cancion> canciones;
        
    public:
        // Contructor por defecto
        cd();
        
        void set_codigo(int );
        /*
        Da valor al codigo del cd
        Parámetros de entrada y sus roles: le entra un entero(cod) q sera el valor a dar al codigo.
        Valor devuelto: Nada
        */
        void set_artista(char* );
        /*
        Da valor al nombre del artista q interpreta el cd
        Parámetros de entrada y sus roles: le entra una cadena(nom) q sera el valor a dar al nombre.
        Valor devuelto: Nada
        */
        void set_titulo(char* );
        /*
        Da valor al titulo del cd
        Parámetros de entrada y sus roles: le entra una cadena(tit) q sera el valor a dar al titulo.
        Valor devuelto: Nada
        */
        void set_canciones(cancion );
        /*
        Inserta una cancion en la lista de canciones q componen el cd
        Parámetros de entrada y sus roles: le entra una cancion(can) q sera el valor a insertar en canciones.
        Valor devuelto: Nada
        */
        int get_codigo();
        /*
        Devuelve el codigo del cd
        Valor devuelto: un entero, el codigo del cd.
        */
        char* get_artista();
        /*
        Devuelve el nombre del artista q interpreta el cd
        Valor devuelto: una cadena, el nombre de artista.
        */
        char* get_titulo();
        /*
        Devuelve el titulo del cd
        Valor devuelto: una cadena, titulo del cd.
        */
        cancion get_cancion(int );
        /*
        Devuelve la cancion i de la lista de canciones
        Parámetros de entrada y sus roles: le entra un entero (i) q sera el valor de la posicion a consultar en canciones
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        Valor devuelto: cancion
        */
        int get_nro_canc();
        /*
        Devuelve el numero de canciones q compone la lista de canciones
        Valor devuelto: entero
        */
        void mostrar_cd();
        /*
        Muestra por pantalla el contenido de cd
        Valor devuelto: Nada
        */
        void ordenar_canciones();
        /*
        Ordena la lista de canciones segun la posicion(el numero de la cancion) q ocupa cada uno de los elementos 
        Valor devuelto: Nada
        */
        void copiar (cd *); 
        /*
        Copia el contenido de un cd al q hace la llamada
        Parámetros de entrada y sus roles: un cd, que sera del cual se tomara la informacion a asignar
        Valor devuelto: Nada
        Condiciones de error tratados dentro de cada acción: Se hace la lista de canciones vacia para asegurar q quien llama la funcion solo obtenga los valores q se le quieren copiar y no concerve anteriores
        */
        
        // operador friend de test de igualdad sobrecargado
        friend int operator== (const cd&, const cd&);
         
END;

/***********************************Nodo CD************************************/

class nodo_cd
BEGIN
    private:
        cd elem;
        nodo_cd* prox;
	
	public:
        // Constructor por defecto
        nodo_cd(void);
        
        void set_elemento(cd *);
        /*
        Le asigna el contenido de un cd al elemento del nodo(elem).
        Parámetros de entrada y sus roles: un cd, que sera del cual se tomara la informacion a asignar
        Valor devuelto: Nada
        */
        cd* get_elemento();
        /*
        Devuelve el elemento del nodo(un cd).
        Valor devuelto: cd
        */
        void set_ptr(nodo_cd* );
        /*
        Da valor al puntero q almacena la direccion del nodo proximo.
        Parámetros de entrada y sus roles: un ptr nodo_cd (p) q sera el valor a signarle a prox
        Valor devuelto: Nada
        */
	    nodo_cd* get_ptr();
	    /*
        Devuelve el puntero  al proximo nodo.
        Valor devuelto: ptr nodo_cd;
        */
        	    
END;

/***********************************Listas*************************************/

class lista_cd
BEGIN
	protected:
		nodo_cd* ptr;
        int ultimo;
		
	public:
		// Constructor por defecto
		lista_cd (void);

		// Destructor
		~lista_cd(void);
		
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
		void insertar(int , cd* );
		/*
        Inserta el cd a en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a insertar. cd a, el cd a incertar en la lista.
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
		cd* consultar(int );
		/*
        Devuelve el valor del cd en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a consultar.
        Valor devuelto: cd
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        */
		int longitud();
		/*
        Devuelve la longitud de la lista (ultimo).
        Valor devuelto: entero
        */
		bool esta(cd *);
		/*
        Devuelve verdadero si el cd consultado se encuentra en la lista o falso en caso contrario.
        Parámetros de entrada y sus roles: cd a, el cd a consultar en la lista.
        Valor devuelto: logico
        */
		cd* primero( );
		/*
        Devuelve el valor del cd en la primera posicion.
        Valor devuelto: cd
        */
		void resto( );
		/*
        Elimina el cd en la primera posicion.
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

class pila_cd : private lista_cd
BEGIN	
    
    public:
		// Constructor por defecto
		pila_cd ();
		
		// Destructor
		~pila_cd(void);
		
		void vacia();
		/*
        Elimina todos los elementos de la pila para asi hacrla vacia.
        Valor devuelto: Nada
        */
		bool es_vacia();
		/*
        Devuelve verdadero si la pila esta vacia o falso en caso contrario.
        Valor devuelto: logico
        */
		void empilar(cd* );
		/*
        Empila el cd a en la primera posicion.
        Parámetros de entrada y sus roles: cd a, el cd a empilar en la pila.
        Valor devuelto: Nada
        */
		void desempilar();
		/*
        Desempila el cd en la primera posicion.
        Valor devuelto: Nada
        */
		cd* tope();
		/*
        Devuelve el valor del cd en la primera posicion.
        Valor devuelto: cd
        */
	    void mostrar_pila();
	    /*
        Muestra todos los elementos de la pila.
        Valor devuelto: Nada
        */
	
END;

#endif
