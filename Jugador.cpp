/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#include "Jugador.h"

//AÑADIR PUNTOS A JUGADOR

void modificarJugador(tJugador &jugador, int puntos) {
	jugador.puntos += puntos;
}

//J1 MENOR QUE J2
 
bool menor(const tJugador &j1, const tJugador &j2) {
	bool menor = false;
	if (j1.identificador < j2.identificador) {
		menor = true;
	}
	else if (j1.identificador == j2.identificador) {
		if (j1.puntos < j2.puntos) {
			menor = true;
		}
		else {
			menor = false;
		}
	}
	return menor;
}
