/*
  Name: Gustavo_Bazan_rockola.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: Implementacion de los metodos de la clase rockola.
*/

#ifndef __ROCKOLA_CPP__
#define __ROCKOLA_CPP__

#include "Gustavo_Bazan_lib.h"

/************************************ROCKOLA***********************************/

void rockola :: set_data(lista<artista> *artistas, lista<album> *albumes, lista<cancion> *canciones){
    int i, j, k;
    cancion can;     
     
    for(j=albumes->longitud()-1; j>=0; j--){
		cd temp;
		temp.set_codigo(albumes->consultar(j).get_pos());
		for(k=0; k<artistas->longitud(); k++){
            if(artistas->consultar(k).get_codigo()==albumes->consultar(j).get_codigo_art()){
                temp.set_artista(artistas->consultar(k).get_nombre());
                break;
            }     
        }
        temp.set_titulo(albumes->consultar(j).get_titulo());
		for(i=0; i<canciones->longitud() && temp.get_nro_canc() < 25; i++){
			can=canciones->consultar(i);
			if(can.get_codigo_cd()== temp.get_codigo()){
				temp.set_canciones(can);
			}
		}
		
		temp.ordenar_canciones();
		cds.empilar(&temp);
    }
    return;
}

void rockola :: mostrar_data(){
     cds.mostrar_pila();
}

void rockola :: reproducir(int cod_canc, ofstream *salida){
     int pos_canc, cod_cd;
     cancion aux;
     cd repro;
     
     cod_cd=(cod_canc DIV 100)MOD 1000;
     pos_canc = cod_canc MOD 100;
     
     if(cod_cd>=cds.tope()->get_codigo()){
         do{
             repro.copiar(cds.tope());
             cds.desempilar();
             if(repro.get_codigo()==cod_cd){
                 aux=repro.get_cancion(pos_canc-1);
                 *salida <<  "Codigo: " << aux.get_codigo() << ", Artista:" <<repro.get_artista();
                 *salida << ", Album:" << repro.get_titulo() << ", Cancion:" << aux.get_titulo() << endl;
                 cds.empilar(&repro);
             }
             else{
                 temp.empilar(&repro);
             }
         }while(cod_cd != repro.get_codigo());
     }
     else{
         do{
             repro.copiar(temp.tope());
             temp.desempilar();
             if(repro.get_codigo()==cod_cd){
                 aux=repro.get_cancion(pos_canc-1);
                 *salida <<  "Codigo: " << aux.get_codigo() << ", Artista:" <<repro.get_artista();
                 *salida << ", Album:" << repro.get_titulo() << ", Cancion:" << aux.get_titulo() << endl;
                 cds.empilar(&repro);
             }
             else{
                 cds.empilar(&repro);
             }
         }while(cod_cd != repro.get_codigo());
     }     
}

#endif
