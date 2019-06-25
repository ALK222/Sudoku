/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#pragma once
#include "header.h"


typedef struct {
	string identificador;
	int puntos;
}tJugador;

typedef tJugador *tJugadorPtr;

//Prototipos
void modificarJugador(tJugador &jugador, int puntos); //modifica un jugador para añadirle puntos
bool operator<(tJugador &opIzq, tJugador &opDe); //sobrecarga del operador < para comparar dos jugadores
bool menor(const tJugador &j1, const tJugador &j2); /*Devuelve true si los puntos de j1 son menores que los de j2 o si tienen los mismos puntos pero el id. de j2
													es menor que el de j1, false en caso anterior*/

