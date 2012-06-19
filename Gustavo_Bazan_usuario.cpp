/*
  Name: Gustavo_Bazan_usuario.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase usuario.
*/

#ifndef __USUARIO_CPP__
#define __USUARIO_CPP__

#include "Gustavo_Bazan_lib.h"

/************************************USUARIO***********************************/

usuario :: usuario()
BEGIN
     dinero = 0;
     strcpy(modo_reproduccion,"");
END

void usuario :: set_dinero(int din)
BEGIN
     dinero = din;
     return;
END

int usuario :: get_dinero()
BEGIN
     return(dinero);
END

void usuario :: set_cancion(int pos, int cd)
BEGIN
     canciones.insertar(pos, cd);
     return;
END 

void usuario :: eliminar_cancion(int pos)
BEGIN
     canciones.eliminar(pos);
END

int usuario :: get_cancion(int pos)
BEGIN
     return(canciones.consultar(pos));
END
    
void usuario :: set_modo_reproduccion(char* modo)
BEGIN
     strcpy(modo_reproduccion,modo);
     return;
END

char* usuario :: get_modo_reproduccion()
BEGIN
     return(modo_reproduccion);
END

int usuario :: get_nro_canc()
BEGIN
     return(canciones.longitud());
END

void usuario :: mostrar_data()
BEGIN
     cout<<dinero<<endl;
     canciones.mostrar_lista();
     cout<<modo_reproduccion<<endl;
     return;
END

void usuario :: copiar (usuario *a)
BEGIN
    int i, temp;
    dinero = a->get_dinero();
    
    canciones.vacia();
	for (i=0; i<a->get_nro_canc(); i++){
        temp=a->get_cancion(i);        
        canciones.insertar(i,temp);
    }
    strcpy(modo_reproduccion,a->get_modo_reproduccion());
    return;
END

/*********************************Nodo Usuario*********************************/

//Constructor por defecto
nodo_us :: nodo_us(void){
    prox=NULL;
};


void nodo_us :: set_elemento(usuario *e){
     elem.copiar(e);
     return;
}

usuario* nodo_us :: get_elemento(){
    return(&elem);
}

void nodo_us :: set_ptr(nodo_us* p){
    prox=p;
    return;
}

nodo_us* nodo_us :: get_ptr(){
    return(prox);
}

/***********************************Listas*************************************/
//Constructor
lista_us :: lista_us (void){
    ptr=NULL;
	ultimo=0;
}

//Destructor
lista_us :: ~lista_us (void){
	nodo_us* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
}

void lista_us :: vacia(){
	nodo_us* aux;
	
	while(!es_vacia()){
        aux=ptr;
        ptr=ptr->get_ptr();
        ultimo--;
        delete aux;
    }
	return;
}

bool lista_us :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void lista_us :: insertar (int pos, usuario *a){
    int i;
    nodo_us* Act=NULL; 
    Act=ptr; 
    i = 0; 
    nodo_us* Q;
    Q=new(nodo_us);
    Q->set_elemento(a);
    nodo_us* Ant=NULL;
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

void lista_us :: eliminar(int pos){
	int i;
	nodo_us* act;
    
    nodo_us* ant;
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

usuario* lista_us :: consultar(int pos){
	int i;
	nodo_us* act;
	
	act=ptr;
	
	for(i=0; i<pos; i++){
        act=act->get_ptr();
	}
    return (act->get_elemento());
}

int lista_us :: longitud(){
	return (ultimo);
}

bool lista_us :: esta(usuario *a){
    int i;
    bool esta=false;
    nodo_us* act;
	
	act=ptr;
	
    for(i=0; i<ultimo && !esta; i++){
        if(act->get_elemento()==a){
            esta=true;
        }    
        act=act->get_ptr();
	}
	return(esta);
    
}

usuario* lista_us :: primero(){
    return(ptr->get_elemento());
}

void lista_us :: resto(){
	nodo_us* act;
	
	if (!es_vacia()){
       act=ptr;
	   ptr=ptr->get_ptr();
       ultimo--;
       delete act;
    }
	return;
}

void lista_us :: mostrar_lista(){
    nodo_us* act;
    act=ptr;
    for(int i=0; i < ultimo; i++){
        act->get_elemento()->mostrar_data(); 
        cout << endl;
        act=act->get_ptr();
    }
    return;
}

/*************************************COLAS************************************/

// Constructor
cola_us :: cola_us () : lista_us(){
}

// Destructor
cola_us :: ~cola_us (void){

	while(!es_vacia()){
        desencolar();
    }
}

void cola_us :: vacia(){
	
	while(!es_vacia()){
        desencolar();
    }
	return;
}

bool cola_us :: es_vacia(){
	if (ultimo == 0) return(true);
	else return(false);
}

void cola_us :: encolar (usuario *e){
	insertar(ultimo, e);
	return;
}

void cola_us :: desencolar (){
    resto();
	return;
}

usuario* cola_us :: frente(){
    return(primero());
}

void cola_us :: mostrar_cola(){
    mostrar_lista();
    return;
}

#endif
