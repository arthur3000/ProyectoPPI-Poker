#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include <iostream>
#include <string>
#include "carta.h"

#define CARTAS_JUGADOR 2
using namespace std;

class Jugador{ 
public:
	string nombre;	// El nombre con el que veran al jugador
	int numero; 	// El numero de jugador que es
	int dinero;		// El dinero que posee el jugador 
	Carta cartas[CARTAS_JUGADOR]; // Las dos cartas con el que jugara la partida
	Jugador(string nombrex,int numerox,int dinerox,Carta carta1, Carta carta2);
	~Jugador();

};

Jugador::Jugador(string nombrex, int numerox, int dinerox,Carta carta1 , Carta carta2){
	nombre = nombrex;
	numero = numerox;
	dinero = dinerox;
	cartas[0] = carta1;	// Duda si esta debe de estar, ya que cada partida las cartas cambian.
	cartas[1] = carta2;
}

#endif JUGADOR_H_INCLUDED