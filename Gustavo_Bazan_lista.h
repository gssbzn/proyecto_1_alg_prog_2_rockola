/*
  Name: Gustavo_Bazan_lista.h
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Clase lista y la implementacio de todos sus metodos.
*/

#ifndef __LISTA_H__
#define __LISTA_H__

/***********************************Listas*************************************/

template <class P>

class lista
BEGIN
	protected:
		nodo <P>* ptr;
        int ultimo;
		
	public:
		// Constructor por defecto
		lista (void);

		// Destructor
		~lista(void);
		
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
		void insertar(int , P );
		/*
        Inserta el P a en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a insertar. P a, el elemento de tipo P a incertar en la lista.
        Valor devuelto: Nada
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        Condiciones de error tratados dentro de cada acción: se valida para q se pueda incertar cuando la lista es vacia.
        */
		void eliminar(int );
		/*
        Elimina el elemento de tipo P en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a eliminar.
        Valor devuelto: Nada
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        Condiciones de error tratados dentro de cada acción: se valida en caso de eliminar la primera posicion.
        */
		P consultar(int );
		/*
        Devuelve el valor del elemento en la posicion i.
        Parámetros de entrada y sus roles:  entero i, la posicion a consultar.
        Valor devuelto: P
        Precondiciones de los valores de los parámetros: 0<=i<=ultimo (posicion valida).
        */
		int longitud();
		/*
        Devuelve la longitud de la lista (ultimo).
        Valor devuelto: entero
        */
		bool esta(P );
		/*
        Devuelve verdadero si el elemento consultado se encuentra en la lista o falso en caso contrario.
        Parámetros de entrada y sus roles: P a, el elemento a consultar en la lista.
        Valor devuelto: logico
        */
		P primero();
		/*
        Devuelve el valor del elemento en la primera posicion.
        Valor devuelto: P
        */
		void resto();
		/*
        Elimina el elemento en la primera posicion.
        Valor devuelto: Nada
        Condiciones de error tratados dentro de cada acción: se valida q la lista no este vacia, para luego proceder a eliminar.
        */
		void mostrar_lista();
		/*
        Muestra todos los elementos de la lista.
        Valor devuelto: Nada
        */
        void copiar (lista<P> *);
        /*
        Copia el contenido de una lista a la q hace la llamada
        Parámetros de entrada y sus roles: una lista de tipo P, que sera de la cual se tomara la informacion a asignar
        Valor devuelto: Nada
        Condiciones de error tratados dentro de cada acción: Se hace la lista  vacia para asegurar q quien llama la funcion solo obtenga los valores q se le quieren copiar y no concerve anteriores
        */
END;

// Constructor
template <class P> lista<P> :: lista (void){
    ptr=NULL;
	ultimo=0;
}

// Destructor
template <class P> lista<P> :: ~lista (void){
	nodo<P>* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
}

template <class P> void lista<P> :: vacia(){
	nodo<P>* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
	return;
}

template <class P> bool lista<P> :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

template <class P> void lista<P> :: insertar (int pos, P a){
    int i;
    nodo<P>* Act; 
    Act=ptr; 
    i = 0; 
    nodo<P>* Q;
    Q=new(nodo<P>);
    Q->set_elemento(a);
    nodo<P>* Ant=NULL;
    while (i < pos){
        Ant = Act;
        Act = Act->get_ptr();
        i++;
    }
    if (Act == ptr) ptr = Q;
    else Ant->set_ptr(Q);

    Q->set_ptr(Act);
    ultimo++;
}


template <class P> void lista<P> :: eliminar(int pos){
	int i;
	nodo<P>* act=NULL;
    
    nodo<P>* ant=NULL;
    act=ptr;
    for(i=0; i<pos-1; i++){
        ant=act;
        act=act->get_ptr();
    }
    if (act == ptr) ptr = act->get_ptr();
    else ant->set_ptr(act->get_ptr());
    ultimo--;
    delete act;
    
	return;
}

template <class P> P lista<P> :: consultar(int pos){
	int i;
	nodo<P>* act;
	P a;
	
	act=ptr;
	
	for(i=0; i<pos; i++){
        act=act->get_ptr();
	}
    a=act->get_elemento();
    return (a);
}

template <class P> int lista<P> :: longitud(){
	return (ultimo);
}

template <class P> bool lista<P> :: esta(P a){
    int i;
    bool esta=false;
    nodo<P>* act;
	
	act=ptr;
	
    for(i=0; i<ultimo && !esta; i++){
        if(act->get_elemento()==a){
            esta=true;
        }    
        act=act->get_ptr();
	}
	return(esta);
    
}

template <class P> P lista<P> :: primero(){
    return(ptr->get_elemento());
}

template <class P> void lista<P> :: resto(){
	nodo<P>* act;
	
    act=ptr;
	ptr=ptr->get_ptr();
    ultimo--;
    delete act;
	return;
}

template <class P> void lista<P> :: mostrar_lista(){
    P a;
    nodo<P>* act;
    act=ptr;
    for(int i=0; i < ultimo; i++){
        a=act->get_elemento();
        cout << a << endl;
        act=act->get_ptr();
    }
    return;
}

template <class P> void lista<P> :: copiar (lista<P> *a){
    int i;
    vacia();
    for (i=0; i<a->longitud(); i++){       
        insertar(i,a->consultar(i));       
    }    
    return;
}

#endif
