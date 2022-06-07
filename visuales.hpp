#ifndef VISUALES_H_ 
#define VISUALES_H_
#include "EasyBMP.h"
#include <iostream>
/*
		PRE:Todas las variables de coordenadas x e y deben tener un valor valido acorde al tamaño del tablero BMP.
		Las variables r,g y b deben tener un valor entre 0 y 255.
		POST:colorea una imagen BMP en las coordenadas marcadas,
		Desde un x a otro(sin incluir el final)
		Desde un y a otro(sin incluir el final)
		Y del color deseado segun las variables r,g,b que segun sus distintos valores formaran un color.
*/
void pintarArea(BMP &Tablero,int xInicial,int xFinal,int yInicial,int yFinal,int r,int g,int b);
/*
	PRE:
	POST:dibuja un soldado en el objeto BMP "Soldado".
*/
void crearBMPSoldado(BMP &Soldado);
/*
	PRE:
	POST:dibuja un avion en el objeto BMP "Avion".
*/
void crearBMPAvion(BMP &Avion);
/*
	PRE:
	POST:dibuja un barco en el BMP "Barco"
*/
void crearBMPBarco(BMP &Barco);
/*
	PRE:
	POST: Los objetos bmp de soldado,barco y avion quedan con su correcto dibujo.
*/
void crearBMPUnidades(BMP &Soldado,BMP &Barco,BMP &Avion);
#endif