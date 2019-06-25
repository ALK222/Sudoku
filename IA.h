#pragma once
/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/

#include "ListaJugadores.h"
#include "juego.h"



bool resolucion(tTablero &tablero); //Resolucion automatica del tablero
void sudokuRandom(tListaSudokus &listaS, tListaJugadores &listaJ); //Partida con un sudoku aleatorio
bool crearTablero(tTablero &tablero);//Creacion de un tablero aleatorio
bool esValido(tTablero tablero, int x, int y, int valor);//Funcion para saber si un valor es valido para una casilla o no
bool encontrar(tTablero tablero, int &x, int &y);//Buscador de casillas vacias
