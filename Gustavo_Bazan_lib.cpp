/*
  Name: Gustavo_Bazan_lib.cpp
  Copyright: 2006
  Author: Gustavo Bazán & Armando Bracho
  Date: 19/04/06
  Description:  La empresa “Aparatos Musicales C.A.” desea desarrollar un prototipo de Rockola para
				distribuirla entre sus clientes. La Rockola es un aparato del tipo Vending Machine que tiene la
				finalidad de ejecutar canciones sobre pedido; es decir, cuando una persona accede a la
				Rockola, le indica mediante algún mecanismo de interacción cuales canciones quiere oír y en
				que orden. Para activar el mecanismo de selección de canciones la persona debe primero
				depositar en una ranura la cantidad total de dinero (o fichas) que sea requerido según las
				especificaciones que generalmente se encuentran adosadas al aparato.
*/

#ifndef __GUSTAVO_BAZAN_LIB_CPP__
#define __GUSTAVO_BAZAN_LIB_CPP__

#include "Gustavo_Bazan_lib.h"

/******************************************************************************/

int compararcadenas(char *cad1, char *cad2){
	/*compara cadenas caracter a caracter con tolower*/   
	int i;   
	int resultado;   
	resultado=0;   
	
	if (strlen(cad1)!=strlen(cad2)) resultado=-1;   
	
	for (i=0;(unsigned)i<(unsigned)strlen(cad1) && resultado==0;i++) {      
		if (tolower(cad1[i])!=tolower(cad2[i])) resultado=-1;   
	}
	return resultado;/*devuelve 0 si son iguales, -1 si son distintos*/
}

/******************************************************************************/

void carga_artistas(lista<artista>* artistas){
	ifstream entrada;
	artista art;
	int i, codigo;
	char nombre[LONG];
	
	//Carga del archivo de entrada artistas.in
	entrada.open("artistas.in", ios:: in);
	if (entrada==NULL)/*SI NO SE PUEDE ABRIR EL FICHERO*/
		cerr << "\n\n\n***ERROR*** No se ha podido encontrar el archivo\n\b";
	else {
		i=0;
		while(entrada!=NULL){
			entrada >> codigo;
			if(entrada==NULL) break;
			entrada.get(nombre,LONG);
			art.set_codigo(codigo);
			art.set_nombre(nombre);
			if(!artistas->esta(art)){
				artistas->insertar(i, art);
			}
			i++;
		}
	}
	entrada.close();
	
}

/******************************************************************************/

void carga_albumes(lista<album>* albumes){
	ifstream entrada;
	album alb;
	int i, codigo;
	char  titulo[LONG];
	//Carga del archivo de entrada albumes.in
	entrada.open("albumes.in", ios:: in);
	if (entrada==NULL)/*SI NO SE PUEDE ABRIR EL FICHERO*/
		cerr << "\n\n\n***ERROR*** No se ha podido encontrar el archivo\n\b";
	else {
		i=0;
		while(entrada!=NULL && albumes->longitud()<100){
			entrada >> codigo;
			if(entrada==NULL) break;
			entrada.get(titulo,LONG);
			alb.set_codigo(codigo);
			alb.set_titulo(titulo);
			if(!albumes->esta(alb)){
				albumes->insertar(i, alb);
			}
			i++;
		}
	}
	entrada.close();
     
}

/******************************************************************************/

void carga_canciones(lista<cancion>* canciones){
    ifstream entrada;
    cancion can;
    int i, codigo;
    char  titulo[LONG];
    //Carga del archivo de entrada canciones.in
	entrada.open("canciones.in", ios:: in);
	if (entrada==NULL)/*SI NO SE PUEDE ABRIR EL FICHERO*/
		cerr << "\n\n\n***ERROR*** No se ha podido encontrar el archivo\n\b";
	else {		
		i=0;
		while(entrada!=NULL){
			entrada >> codigo;
			if(entrada==NULL) break;
			entrada.get(titulo,LONG);
			can.set_codigo(codigo);
			can.set_titulo(titulo);
			if(!canciones->esta(can)){
				canciones->insertar(i, can);
			}
			i++;
		}
	}
	entrada.close();
}

/******************************************************************************/

bool verificar_canciones(usuario* us, lista<cancion>* canciones){
     bool esta=true;
     
     for(int i=0; i < us->get_nro_canc() && esta; i++){
         cancion can(us->get_cancion(i), "");
         if(!canciones->esta(can)) esta=false;
     }
     return(esta);
}

/******************************************************************************/

int monto(int cant, int prio){
    if(prio == 1){
        switch(cant)
        BEGIN
            case 1: return(1500); break;
            case 2: return(3000); break;
            case 3: return(4500); break;
            case 4: return(5250); break;
            case 5: return(6000); break;
        END
    }
    else{
        switch(cant)
        BEGIN
            case 1: return(1000); break;
            case 2: return(2000); break;
            case 3: return(3000); break;
            case 4: return(3500); break;
            case 5: return(4000); break;
        END
    }
	return(-1);
}

/******************************************************************************/

int crearlog(usuario* us, int prio, lista<cancion>* canciones, ofstream *salida){
    
    int rial = 0, dinero = 0;
    		
    if(us->get_nro_canc() > 5){
        *salida << "Transaccion cancelda, Motivo: Limite de canciones excedido.\n";
        return(0);
    }
    else if(verificar_canciones(us, canciones)== false){
        *salida << "Transaccion cancelda, Motivo: Codigo de cancion incorrecto.\n";
        return(0);
    }
    else{
        rial = monto(us->get_nro_canc(), prio);
        dinero = us->get_dinero();
        if(dinero >= rial){
            rial = dinero - rial;
            *salida << "Transaccion exitosa, vuelto: " << rial << " Bs.\n";
            return(1);
        }
        else{
            *salida << "Transaccion cancelda, Motivo: Pago Insuficiente.\n";
            return(0);
        }
    }

}

/******************************************************************************/

void carga_rockola(cola_us* usuarios, cola_us* prioridad, lista<cancion>* canciones){
    ifstream entrada;
    int i, j, money;
    char  titulo[LONG];
	//Carga del archivo de entrada rockola.in
	entrada.open("rockola.in", ios:: in);
	if (entrada==NULL)/*SI NO SE PUEDE ABRIR EL FICHERO*/
    	cerr << "\n\n\n***ERROR*** No se ha podido encontrar el archivo\n\b";
	else {		
		i=0;
		ofstream salida("log.out");
		while(entrada!=NULL){
			usuario us;
                              
			entrada >> money;
			if(entrada==NULL) break;
			us.set_dinero(money);
			entrada >> titulo;
			j=0;
			while(compararcadenas(titulo,"ACEPTAR")==-1){
                us.set_cancion(j, atoi(titulo));
                entrada >> titulo;
                j++;                                                   
            }
            entrada >> titulo;
            us.set_modo_reproduccion(titulo);
            entrada >> titulo;
            if(compararcadenas(titulo,"FINALIZAR")==-1){
                if(crearlog(&us, 1, canciones, &salida) == 1){//determina si es una solisitud valida y procede a escribirla en log
				    prioridad->encolar(&us);
                }
                entrada >> titulo;
            }
            else{
				if(crearlog(&us, 0, canciones, &salida) == 1){//determina si es una solisitud valida y procede a escribirla en log
                    usuarios->encolar(&us);
				}
            }
            i++;
		}
		salida.close();
	}
	entrada.close();
	
}

/******************************************************************************/

bool por_tomar(bool tomado[5], int limite){
     int i;
     bool A=false;
     for(i=0; i<limite && !A; i++){
         if(tomado[i]==false)A=true;
     }
     return(A);
}

/******************************************************************************/

int procesar_usuarios(rockola* cds, cola_us* usuarios, int* canc, ofstream* salida, int prio){
    int i, codigo, costo, dinero, vuelto, total=0;
    
    while(!usuarios->es_vacia()){
        cout<<"...";
        usuario us;
        us.copiar(usuarios->frente());
        usuarios->desencolar();
        
        costo = monto(us.get_nro_canc(), prio);
        dinero = us.get_dinero();
        vuelto = dinero - costo;
        total+=dinero - vuelto;
               
        if(compararcadenas(us.get_modo_reproduccion(), "ALEATORIO")==0){
            i=0;
            clock_t comienzo;
	        bool tomado[]={0,0,0,0,0};

            while(por_tomar(tomado, us.get_nro_canc())){
                comienzo=clock();
                while(clock()/(double)CLOCKS_PER_SEC < (comienzo/(double)CLOCKS_PER_SEC)+0.25){
                    i++;
                    if(i>=us.get_nro_canc()) i=0;
                }
                cout<<"...";
                if(i<us.get_nro_canc() && tomado[i]==0){
                    codigo=us.get_cancion(i);
                    cds->reproducir(codigo, salida);
                    tomado[i]=1;                    
                }       
            }
            
        }
        else{
            for(i=0; i<us.get_nro_canc(); i++){
                codigo=us.get_cancion(i);
                cds->reproducir(codigo, salida);                
            }
        }
        *canc = *canc + us.get_nro_canc();
    }
    return(total);
}

#endif
