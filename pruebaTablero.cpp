#include "EasyBMP.h"
#include "unidad.hpp"
#include "casillero.hpp"
#include "visuales.hpp"
#include "carta.hpp"
#include "coordenada.hpp"
#include "jugador.hpp"
#include "soldado.hpp"
#include "tablero.hpp"
#include "partida.hpp"
#include <iostream>

using namespace std;
const int PRIMER_MAPA= 1;
const int SEGUNDO_MAPA= 2;
const int TERCER_MAPA =3;
const int CUARTO_MAPA =4;
const int MAX_ANCHO_CASILLERO=10;
const int MAX_ALTO_CASILLERO=10;

/*
	PRE:
	POST:Dibuja las lineas que verticales de los casilleros
*/
void dibujarCasillerosVertical(BMP &Tablero){
	for(int x=0;x<Tablero.TellWidth();x+=10){
		for(int y=0;y<Tablero.TellHeight();y++){
			Tablero(x,y)->Red=0;
			Tablero(x,y)->Green=0;
			Tablero(x,y)->Blue=0;
		}
	}
}
/*
	PRE:
	POST:dibuja las lineas horizontales de los casilleros.
*/
void dibujarCasillerosHorizontal(BMP &Tablero){
	for(int y=0;y<Tablero.TellHeight();y+=10){
		for(int x=0;x<Tablero.TellWidth();x++){
			Tablero(x,y)->Red=0;
			Tablero(x,y)->Green=0;
			Tablero(x,y)->Blue=0;
		}
	}
}

/*
	PRE:
	POST:dibuja los casilleros de 10x10 pixeles en el tablero bmp
*/
void dibujarCasilleros(BMP &Tablero){
	dibujarCasillerosHorizontal(Tablero);
	dibujarCasillerosVertical(Tablero);
}

/*
	PRE:
	POST:Crea un Tablero 50% tierra y 50% agua.
*/
void crearPrimerMapa(BMP &Tablero){
	unsigned int ancho=Tablero.TellWidth();
	unsigned int largo=Tablero.TellHeight();
	pintarArea(Tablero,0,ancho,0,largo/2,113,85,52);
	pintarArea(Tablero,0,ancho,largo/2,largo,0,0,255);
	dibujarCasilleros(Tablero);
}
/*
	PRE:
	POST:Crea un Tablero rodeado de agua con una isla en forma de cruz en el centro.
		
*/
void crearSegundoMapa(BMP &Tablero){
	unsigned int ancho=Tablero.TellWidth();
	unsigned int largo=Tablero.TellHeight();
	pintarArea(Tablero,0,ancho,0,largo,0,0,255);
	pintarArea(Tablero,ancho/4,ancho-(ancho/4),0,largo,113,85,52);
	pintarArea(Tablero,0,ancho,largo/4,largo-(largo/4),113,85,52);
	dibujarCasilleros(Tablero);
}
/*
	PRE:
	POST:Crea un Tablero totalmente de tierra con una masa de agua en el centro.
			
*/
void crearTercerMapa(BMP &Tablero){
	unsigned int ancho=Tablero.TellWidth();
	unsigned int largo=Tablero.TellHeight();
	pintarArea(Tablero,0,ancho,0,largo,113,85,52);
	pintarArea(Tablero,ancho/4,ancho-(ancho/4),largo/4,largo-(largo/4),0,0,255);
	dibujarCasilleros(Tablero);
}
/*
	PRE:
	POST:Crea un Tablero totalmente de tierra con un rio en el medio que lo cruza por completo.

*/
void crearCuartoMapa(BMP &Tablero){
	unsigned int ancho=Tablero.TellWidth();
	unsigned int largo=Tablero.TellHeight();
	pintarArea(Tablero,0,ancho,0,largo,113,85,52);
	pintarArea(Tablero,0,ancho,largo/4,largo-(largo/4),0,0,255);
	dibujarCasilleros(Tablero);
}

/*	
	PRE:
	POST:coloca una unidad en el casillero asignado,Se cambia
		
*/
void colocarUnidadEnMapa(BMP &Tablero,Unidad* unidad,BMP Avion){
	
	int x,y,xInicial,yInicial,xFinal,yFinal;

	Coordenada* posicion= unidad->getPosicion();
	xInicial=posicion->getAncho()*MAX_ANCHO_CASILLERO+1;
	yInicial=posicion->getAlto()*MAX_ALTO_CASILLERO+1;


 	xFinal=xInicial+MAX_ANCHO_CASILLERO-1;
 	yFinal=yInicial+MAX_ALTO_CASILLERO-1;
 	x=0;

	for(;xInicial<xFinal;xInicial++){
		y=0;
		for(;yInicial<yFinal;yInicial++){
			PixelToPixelCopy(Avion,x,y,Tablero,xInicial,yInicial);
			y++;

		}
		x++;
		yInicial=(posicion->getAlto()*MAX_ALTO_CASILLERO)+1;
	}
}
/*
	PRE:
	POST: Multiplica por 10 el largo y el ancho del tablero. 
*/
void adaptarMedidas(unsigned int &ancho,unsigned int &largo){
	largo=largo*10;
	ancho=ancho*10;
}
/*
	PRE:
	POST:Establece las medidas en pixeles que va a tener el bmp del tablero.
*/
void establecerMedidas(BMP &Tablero,unsigned int &ancho,unsigned int &largo){
	adaptarMedidas(ancho,largo);
	Tablero.SetSize(ancho,largo);
}
/*

	
	PRE:largo y ancho deben ser valores enteros.
		Numero mapa debe ser un numero entre 1 y 4 inclusive.
	POST:segun los valores que reciba de las dimensiones alto y ancho ,elige un Tablero al azar de los 4 tipos 
	prediseñados y lo crea del tamaño deseado.
	.
		
*/
void crearBMPTablero(BMP &TableroVisual,unsigned int ancho,unsigned int largo,unsigned int numeroMapa){

	establecerMedidas(TableroVisual,ancho,largo);

	switch(numeroMapa){
		case(PRIMER_MAPA):
			crearPrimerMapa(TableroVisual);
			break;
		case(SEGUNDO_MAPA):
			crearSegundoMapa(TableroVisual);
			break;
		case(TERCER_MAPA):
			crearTercerMapa(TableroVisual);
			break;
		case(CUARTO_MAPA):
			crearCuartoMapa(TableroVisual);
			break;
	}

	TableroVisual.WriteToFile("Tablero");
}

void exportarTableroBMP(Tablero* tablero,unsigned int numeroMapa){
	
	Casillero* casillero= tablero->getCasillero(2,2,1);

	//Unidad* unidad=new Unidad(avion,1,casillero->getCoordenada());
	//casillero->setUnidad(unidad);

	//Coordenada* coordenada=casillero->getCoordenada();
	//Casillero* casillero2=tablero->getCasillero(coordenada->getLargo(),coordenada->getAncho(),coordenada->getAlto());

	BMP TableroVisual,Soldado,Barco,Avion;

	crearBMPTablero(TableroVisual,tablero->getAncho(),tablero->getLargo(),numeroMapa);
	crearBMPUnidades(Soldado,Barco,Avion);
	//colocarUnidadEnMapa(TableroVisual,casillero2->getUnidad(),Avion);

}
/*
void exportarTableroBMP(Tablero* tablero){
	BMP TableroVisual,Soldado,Barco,Avion;
	crearBMPTablero(TableroVisual,20,20,4);
	crearBMPUnidades(Soldado,Barco,Avion);
}*/
int main(){

	try{
		Tablero* tablero=new Tablero(200,200,20,4);

		exportarTableroBMP(tablero,2);
	}
	catch(const char* Excepcion){
		cout<<Excepcion;
	}



	
	
	return 0;
}