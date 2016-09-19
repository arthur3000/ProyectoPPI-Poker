#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

#include <iostream>

using namespace std;
class Carta{
public:
	int tipo; // Corazones, diamantes, picas o treboles
	int color; // Este atributo no se si sea necesario, pero se puede manejar ganar por color
	int valor; //  El valor de la carta, ya sea As, 2 , 3 etc
	bool utilizada; // Para saber si esta carta ya ha sido utilizada dentro de la partida.


	Carta(int tipox, int colox, int valox, bool utilizadax);
	~carta();
	
};
// Se tendrian que inializar las 52 cartas de una vez para que se les asigne correctamente todo;
Carta::Carta(int tipox, int colox, int valox, bool utilizadax){ // No me acorde de como hacer el this -> :P por eso estos nombres feos
	tipo = tipox;
	color = colox;
	valor = valox;
	utilizada = utilizadax;
}



#endif
