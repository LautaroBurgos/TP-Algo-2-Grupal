#include "visuales.hpp"
#include "EasyBMP.h"
#include <iostream>

void pintarArea(BMP &Tablero,int xInicial,int xFinal,int yInicial,int yFinal,int r,int g,int b){
		for(int x=0;x<Tablero.BMP::TellWidth();x++){
			for(int y=0;y<Tablero.BMP::TellHeight();y++){
				if(((x>=xInicial)&&(x<xFinal))&&((y>=yInicial)&&(y<yFinal))){
					Tablero(x,y)->Red=r;
					Tablero(x,y)->Green=g;
					Tablero(x,y)->Blue=b;
				}
			}
		}
}

void crearBMPSoldado(BMP &Soldado){
	Soldado.SetSize(9,9);
	pintarArea(Soldado,0,10,0,10,113,85,52);
	pintarArea(Soldado,4,5,2,7,3,90,5);
	pintarArea(Soldado,2,7,4,5,3,90,5);
	pintarArea(Soldado,3,4,7,9,3,90,5);
	pintarArea(Soldado,5,6,7,9,3,90,5);
}

void crearBMPAvion(BMP &Avion){
	Avion.SetSize(9,9);
	pintarArea(Avion,0,10,0,10,255,255,255);
	pintarArea(Avion,4,5,2,7,0,0,0);
	pintarArea(Avion,3,6,7,8,0,0,0);
	pintarArea(Avion,2,7,4,5,0,0,0);
	pintarArea(Avion,3,6,3,4,0,0,0);
}

void crearBMPBarco(BMP &Barco){
	Barco.SetSize(9,9);
	pintarArea(Barco,0,10,0,10,0,0,255);
	pintarArea(Barco,4,5,2,8,0,0,0);
	pintarArea(Barco,3,4,3,7,0,0,0);
	pintarArea(Barco,5,6,3,7,0,0,0);
}
void crearBMPUnidades(BMP &Soldado,BMP &Barco,BMP &Avion){
	crearBMPSoldado(Soldado);
	crearBMPBarco(Barco);
	crearBMPAvion(Avion);
}