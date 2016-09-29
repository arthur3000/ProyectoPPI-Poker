#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "carta.h"

#define TAMANO_MAZO 52
// Tipos de carta
#define CORAZONES 1
#define DIAMANTES 2
#define PICAS 3
#define TREBOLES 4
// Color de las cartas
#define NEGRO 1
#define ROJO 2
// valor de las cartas
#define AS 1
#define DOS 2
#define TRES 3
#define CUATRO 4
#define CINCO 5
#define SEIS 6
#define SIETE 7
#define OCHO 8
#define NUEVE 9
#define DIEZ 10
#define JOTO 11
#define REINA 12
#define REY 13



using namespace std;

class Mazo{
public:
	Carta mazo[TAMANO_MAZO]; // Las 52 cartas de la baraja 
	string nombreCorazones[REY];
	string nombreDiamantes[REY];
	string nombrePicas[REY];
	string nombreTreboles[REY];

	void inicializarNombresCartas();
	void inicializarMazo();
	Carta repartirCartaJugador();

	Mazo();
	
};

Mazo::Mazo(){

}
void Mazo::inicializarNombresCartas(){
	// Corazones 
	nombreCorazones[0] = "CA.png";
	nombreCorazones[1] = "C2.png";
	nombreCorazones[2] = "C3.png";
	nombreCorazones[3] = "C4.png";
	nombreCorazones[4] = "C5.png";
	nombreCorazones[5] = "C6.png";
	nombreCorazones[6] = "C7.png";
	nombreCorazones[7] = "C8.png";
	nombreCorazones[8] = "C9.png";
	nombreCorazones[9] = "C10.png";
	nombreCorazones[10] = "CJ.png";
	nombreCorazones[11] = "CQ.png";
	nombreCorazones[12] = "CK.png";
	// Diamantes
	nombreDiamantes[0] = "DA.png";
	nombreDiamantes[1] = "D2.png";
	nombreDiamantes[2] = "D3.png";
	nombreDiamantes[3] = "D4.png";
	nombreDiamantes[4] = "D5.png";
	nombreDiamantes[5] = "D6.png";
	nombreDiamantes[6] = "D7.png";
	nombreDiamantes[7] = "D8.png";
	nombreDiamantes[8] = "D9.png";
	nombreDiamantes[9] = "D10.png";
	nombreDiamantes[10] = "DJ.png";
	nombreDiamantes[11] = "DQ.png";
	nombreDiamantes[12] = "DK.png";
	// Picas
	nombrePicas[0] = "PA.png";
	nombrePicas[1] = "P2.png";
	nombrePicas[2] = "P3.png";
	nombrePicas[3] = "P4.png";
	nombrePicas[4] = "P5.png";
	nombrePicas[5] = "P6.png";
	nombrePicas[6] = "P7.png";
	nombrePicas[7] = "P8.png";
	nombrePicas[8] = "P9.png";
	nombrePicas[9] = "P10.png";
	nombrePicas[10] = "PJ.png";
	nombrePicas[11] = "PQ.png";
	nombrePicas[12] = "PK.png";
	// Treboles
	nombreTreboles[0] = "TA.png";
	nombreTreboles[1] = "T2.png";
	nombreTreboles[2] = "T3.png";
	nombreTreboles[3] = "T4.png";
	nombreTreboles[4] = "T5.png";
	nombreTreboles[5] = "T6.png";
	nombreTreboles[6] = "T7.png";
	nombreTreboles[7] = "T8.png";
	nombreTreboles[8] = "T9.png";
	nombreTreboles[9] = "T10.png";
	nombreTreboles[10] = "TJ.png";
	nombreTreboles[11] = "TQ.png";
	nombreTreboles[12] = "TK.png";

}
void Mazo::inicializarMazo(){
	inicializarNombresCartas();
	int contadorMazo = 0; // Lleva el control de las 52 cartas
	// Inicializar corazones 
	for(int i=0; i<REY ; i++,contadorMazo++){
		mazo[contadorMazo] = Carta(CORAZONES,ROJO,i+1,false,nombreCorazones[i]); // Constructor Carta
	}
	// Inicializar Diamantes
	for(int i=0;i < REY ; i++, contadorMazo++){
		mazo[contadorMazo] = Carta(TREBOLES,ROJO,i+1,false,nombreDiamantes[i]); // Constructor Diamante
	}
	// Inicializar picas
	for(int i=0;i < REY ; i++, contadorMazo++){
		mazo[contadorMazo] = Carta(PICAS,NEGRO,i+1,false,nombrePicas[i]); // Constuctor Picas
	}
	// Inicializar treboles
	for(int i=0 ; i< REY ; i++ , contadorMazo++){
		mazo[contadorMazo] = Carta(TREBOLES,NEGRO,i+1,false,nombreTreboles[i]); // Constructor Treboles
	}

}
Carta Mazo::repartirCartaJugador(){
	int cartaSeleccionada;
	bool salida;
	srand(time(NULL));
	do{
		cartaSeleccionada = rand() & 51 + 0;
		if(!mazo[cartaSeleccionada].utilizada){
			mazo[cartaSeleccionada].utilizada = true;
			salida = true;
		}

	}while(!salida);

	return mazo[cartaSeleccionada];

}

#endif
