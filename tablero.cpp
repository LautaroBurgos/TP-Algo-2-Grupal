#include "tablero.hpp"
#include "coordenada.hpp"
#include <iostream>
using namespace std;
const int PRIMER_MAPA=1;
const int SEGUNDO_MAPA=2;
const int TERCER_MAPA=3;
const int CUARTO_MAPA=4;

Tablero::Tablero(int largo, int ancho, int alto, int nroMapa){
    this->largo = largo;
    this->ancho = ancho;
    this->alto = alto;
  
    this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();
    for(int x=1; x<=largo; x++){
        this->tablero->add(new Lista<Lista<Casillero*>*>(), x);
	    for(int y=1; y<=ancho; y++){
		    this->tablero->get(x)->add(new Lista<Casillero*>(), y);
		    for(int z=1; z<=alto; z++){

          switch(nroMapa){
            case PRIMER_MAPA:
              crearPrimerMapa(x,y,z,largo,ancho);
              break;
            case SEGUNDO_MAPA:
              crearSegundoMapa(x,y,z,largo,ancho);
              break;
            case TERCER_MAPA:
              crearTercerMapa(x,y,z,largo,ancho);
              break;
            case CUARTO_MAPA:
              crearCuartoMapa(x,y,z,largo,ancho);
              break;
          }
		    }
	    }
    }
}
void Tablero::crearPrimerMapa(int x,int y,int z,int largo,int ancho){
  if(x<largo/2 && y<ancho/2 && z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, agua), z);
  }else if(z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, tierra), z);
  }else{
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, aire), z);
  }
}
void Tablero::crearSegundoMapa(int x,int y,int z,int largo,int ancho){
  if(x>largo/3 && x<largo-(largo/3) && z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, agua), z);
  }else if(z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, tierra), z);
  }else{
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, aire), z);
  }
}
void Tablero::crearTercerMapa(int x,int y,int z,int largo,int ancho){
  if(x>largo/6 && x<largo-(largo/6) && y>ancho/6 && y<ancho-(ancho/6) && z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, tierra), z);
  }else if(z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, agua), z);
  }else{
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, aire), z);
  }
}
void Tablero::crearCuartoMapa(int x,int y,int z,int largo,int ancho){
  if(x>largo/4 && x<largo-(largo/4)&& z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, tierra), z);
  }else if(y>ancho/4 && y<ancho-(ancho/4) && z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, tierra), z);
  }else if(z==1){
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, agua), z);
  }else{
    this->tablero->get(x)->get(y)->add(new Casillero(x,y,z, aire), z);
  }
}

// NECESITA TERMINARSE 
Tablero::~Tablero(){
/*
	while(this->vacia() == false){
		while(this->get(1)->vacia() == false){
			while(this->get(1)->get(1)->vacia() == false){
				delete this->get(1)->get(1)->get(1);
				this->get(1)->get(1)->remover(1);
			}
			delete this->get(1)->get(1);
			this->get(1)->remover(1);
		}
		delete this->get(1);
		this->remover(1);
	}
*/
}

int Tablero::getLargo(){
  return this->largo;
}

int Tablero::getAncho(){
  return this->ancho;
}

int Tablero::getAlto(){
  return this->alto;
}

Casillero* Tablero::getCasillero(int largo, int ancho, int alto){
    if(largo<1|| ancho<1 || alto<1 || 
    largo>this->getLargo() || ancho>this->getAncho() || alto>this->getAlto() ){
      return NULL;
	    //throw "El casillero solicitado se va del rango.";
    }
    return this->tablero->get(largo)->get(ancho)->get(alto);
}
