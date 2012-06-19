/*
  Name: Gustavo_Bazan_cd.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase cd.
*/

#ifndef __CD_CPP__
#define __CD_CPP__

#include "Gustavo_Bazan_lib.h"

/***************************************CD*************************************/
//Contructor por defecto
cd :: cd(){
    codigo=0;
    strcpy(nombre_art,"");
    strcpy(titulo_alb,"");
}

void cd :: set_codigo(int cod){
    codigo=cod;
    return;
}

void cd :: set_artista(char* nom){
    strcpy(nombre_art,nom);
    return;
}

void cd :: set_titulo(char* tit){
    strcpy(titulo_alb,tit);
    return;
}

void cd :: set_canciones(cancion can){
    canciones.insertar(canciones.longitud(), can);
    return;
}

int cd :: get_codigo(){
    return(codigo);
}

char* cd :: get_artista(){
    return(nombre_art);
}

char* cd :: get_titulo(){
    return(titulo_alb);
}

cancion cd :: get_cancion(int pos){
    return(canciones.consultar(pos));
}

int cd :: get_nro_canc(){
    return(canciones.longitud());
}

void cd::mostrar_cd(){
    cout << codigo << endl;
    puts(nombre_art);
    puts(titulo_alb);
    canciones.mostrar_lista();
    return;
}

void cd :: ordenar_canciones(){
    int i, j;
    cancion temp;
    lista<cancion> aux;
    aux.copiar(&canciones);
    
    canciones.vacia();
    
    for (i=0; i<aux.longitud(); i++){
        for(j=0; j<aux.longitud(); j++){
            temp=aux.consultar(j);
            if(temp.get_pos()-1==i){
                canciones.insertar(i,temp);
            }
        }
    }
    return;
}

void cd :: copiar (cd *a){
    int i;
    cancion temp;
    codigo = a->get_codigo();
    strcpy(nombre_art,a->get_artista());
    strcpy(titulo_alb,a->get_titulo());
    canciones.vacia();
	for (i=0; i<a->get_nro_canc(); i++){
        temp=a->get_cancion(i);        
        canciones.insertar(i,temp);
    }
    return;
}

// operador friend de test de igualdad sobrecargado
int operator== (const cd &a, const cd &b){
    if (a.codigo==b.codigo) return 1;
    else return 0;
}

/***********************************Nodo CD************************************/
//Constructor por defecto
nodo_cd :: nodo_cd(void){
    prox=NULL;
};


void nodo_cd :: set_elemento(cd *e){
     elem.copiar(e);
     return;
}

cd* nodo_cd :: get_elemento(){
    return(&elem);
}

void nodo_cd :: set_ptr(nodo_cd* p){
    prox=p;
    return;
}

nodo_cd* nodo_cd :: get_ptr(){
    return(prox);
}

/***********************************Listas*************************************/
//Constructor
lista_cd :: lista_cd (void){
    ptr=NULL;
	ultimo=0;
}

//Destructor
lista_cd :: ~lista_cd (void){
	nodo_cd* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
}

void lista_cd :: vacia(){
	nodo_cd* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
	return;
}

bool lista_cd :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void lista_cd :: insertar (int pos, cd *a){
    int i;
    nodo_cd* Act; 
    Act=ptr; 
    i = 0; 
    nodo_cd* Q;
    Q=new(nodo_cd);
    Q->set_elemento(a);
    nodo_cd* Ant=NULL;
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

void lista_cd :: eliminar(int pos){
	int i;
	nodo_cd* act;
    
    nodo_cd* ant;
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

cd* lista_cd :: consultar(int pos){
	int i;
	nodo_cd* act;
	
	act=ptr;
	
	for(i=0; i<pos; i++){
        act=act->get_ptr();
	}
    return (act->get_elemento());
}

int lista_cd :: longitud(){
	return (ultimo);
}

bool lista_cd :: esta(cd *a){
    int i;
    bool esta=false;
    nodo_cd* act;
	
	act=ptr;
	
    for(i=0; i<ultimo && !esta; i++){
        if(act->get_elemento()==a){
            esta=true;
        }    
        act=act->get_ptr();
	}
	return(esta);
    
}

cd* lista_cd :: primero(){
    return(ptr->get_elemento());
}

void lista_cd :: resto(){
	nodo_cd* act;
	
	if (!es_vacia()){
       act=ptr;
	   ptr=ptr->get_ptr();
       ultimo--;
       delete act;
    }
	return;
}

void lista_cd :: mostrar_lista(){
    nodo_cd* act;
    act=ptr;
    for(int i=0; i < ultimo; i++){
        act->get_elemento()->mostrar_cd(); 
        cout << endl;
        act=act->get_ptr();
    }
    return;
}

/********************************PILAS*******************************/

//Constructor
pila_cd :: pila_cd () : lista_cd(){
    
}

//Destructor
pila_cd :: ~pila_cd (void){
	while(!es_vacia()){
        desempilar();
    }
}

void pila_cd :: vacia(){
	
	while(!es_vacia()){
        desempilar();
    }
	return;
}

bool pila_cd :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void pila_cd :: empilar (cd *e){
	insertar(0, e);
	return;
}

void pila_cd :: desempilar (){
	resto();
	return;
}

cd* pila_cd :: tope(){
    return(primero());
}

void pila_cd :: mostrar_pila(){
    mostrar_lista();
    return;
}

#endif
