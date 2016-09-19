#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED

#include <iostream>
#include "cartas.h"

#define TAMANO_MAZO 52
using namaspace std;

class Mazo{
public:
	Carta mazo[TAMANO_MAZO]; // Las 52 cartas de la baraja 
	void inicializarMazo();
	Mazo();
	~Mazo();
	
};

#endif
