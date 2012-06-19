/*
  Name: Gustavo_Bazan.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description: La empresa “Aparatos Musicales C.A.” desea desarrollar un prototipo de Rockola para
               distribuirla entre sus clientes. La Rockola es un aparato del tipo Vending Machine que tiene la
               finalidad de ejecutar canciones sobre pedido; es decir, cuando una persona accede a la
               Rockola, le indica mediante algún mecanismo de interacción cuales canciones quiere oír y en
               que orden. Para activar el mecanismo de selección de canciones la persona debe primero
               depositar en una ranura la cantidad total de dinero (o fichas) que sea requerido según las
               especificaciones que generalmente se encuentran adosadas al aparato.
*/

#include "Gustavo_Bazan_lib.h"
#include "Gustavo_Bazan_lib.cpp"
#include "Gustavo_Bazan_artista.cpp"
#include "Gustavo_Bazan_album.cpp"
#include "Gustavo_Bazan_cancion.cpp"
#include "Gustavo_Bazan_cd.cpp"
#include "Gustavo_Bazan_rockola.cpp"
#include "Gustavo_Bazan_usuario.cpp"

int main()
BEGIN
	
	//Artistas
	lista<artista> artistas;
	//Albumes
	lista<album> albumes;
	//Canciones
	lista<cancion> canciones;
	//Usuarios
	cola_us usuarios, prioridad;
	//Rockola
	rockola cds;
	
	//Contadores y Acumuladores
	int canc_pri, canc_nor, total;
	
	//Carga del archivo de entrada artistas.in
	carga_artistas(&artistas);
	/*
	artistas.mostrar_lista();
	system("PAUSE");
	system("CLS");
	*/
	
	//Carga del archivo de entrada albumes.in
	carga_albumes(&albumes);
	/*
	albumes.mostrar_lista();
	system("PAUSE");
	system("CLS");	
	*/
	
	//Carga del archivo de entrada canciones.in
	carga_canciones(&canciones);
	/*
	canciones.mostrar_lista();
	system("PAUSE");
	system("CLS");
	*/
	
	//Carga del archivo de entrada rockola.in
	carga_rockola(&usuarios, &prioridad, &canciones);
	/*
	usuarios.mostrar_cola();
	system("PAUSE");
	system("CLS");
	
	prioridad.mostrar_cola();
	system("PAUSE");
	system("CLS");
	*/
	
	//Carga la rockola con todos los datos
	cds.set_data(&artistas, &albumes, &canciones);
	/*
	cds.mostrar_data();
	system("PAUSE");
	system("CLS");
	*/
	
	cout<<"Procesando...\n"<<endl;
	
	ofstream salida("reporte.out");
	
	//Proceasar las canciones solicitadas
	total=0;
	canc_pri=0;
	total+=procesar_usuarios(&cds, &prioridad, &canc_pri, &salida, 1);
	canc_nor=0;
	total+=procesar_usuarios(&cds, &usuarios, &canc_nor, &salida, 0);
	
	salida << endl << "Numero de Canciones Sin Prioridad: " << canc_nor << endl;
	salida << "Numero de Canciones Con Prioridad: " << canc_pri << endl;
	salida << "Numero de Canciones: " << canc_pri + canc_nor << endl ;
	salida << endl << "Total: " << total <<" Bs." << endl;
	
	salida.close();
	
	cout<<"\n\n\nReproduccion Terminada."<<endl;
	cout<<"\nPara Detalles Consulte: \"reporte.out\" y \"log.out\". \n\n\n"<<endl;
	system("PAUSE");
	return EXIT_SUCCESS;
END
