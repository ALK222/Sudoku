/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
//prototipos

#include "IA.h"


//PARTIDA ALEATORIA

void sudokuRandom(tListaSudokus &listaS, tListaJugadores &listaJ) {
	tJuego juego;
	tSudoku sudokuNuevo;
	sudokuNuevo.fichero = "random";
	sudokuNuevo.nivel = 3;
	bool pass = false;
	insertarS(listaS, sudokuNuevo, pass, pass);
	tTablero tablero;
	iniciaTablero(tablero);
	crearTablero(tablero);
	rellenarArchivo(tablero, sudokuNuevo);
	puntuarJugardor(listaJ, jugarUnSudoku(sudokuNuevo), 0);
}//Partida con un sudoku aleatorio

//CREACION DE SUDOKU ALEATORIO

bool crearTablero(tTablero &tablero) {
	for (int i = 0; i < 10; i++) {
		int fila = rand() % 8 + 0;
		int columna = rand() % 8 + 0;
		int cand = rand() % 9 + 1;
		if (esValido(tablero, fila, columna, cand)) {
			tablero[fila][columna].numero = cand;
			tablero[fila][columna].estado = RELLENO;
		}
		else {
			i--;
		}
	}
	resolucion(tablero);
	for (int i = 0; i < 50; i++) {
		int fila = rand() % 9 + 0;
		int columna = rand() % 9 + 0;
		if (tablero[fila][columna].numero != 0) {
			tablero[fila][columna].numero = 0;
			tablero[fila][columna].estado = VACIO;
		}
		else {
			i--;
		}
	}
	return true;
}//Creacion de un tablero aleatorio

//VALOR VALIDO?

bool esValido(tTablero tablero, int x, int y, int valor) {
	for (int i = 0; i < DIMENSION; i++) { //Recorrido de columna
		if (tablero[x][i].numero == valor) {
			return false;
		}
	}
	for (int k = 0; k < DIMENSION; k++) { //Recorrido de filas
		if (tablero[k][y].numero == valor) {
			return false;
		}
	}
	int	dimCaja = DIMENSION / 3;
	for (int rfila = (x / 3) * dimCaja; rfila < (((x / 3) * dimCaja) + dimCaja); rfila++) {
		for (int rcol = (y / 3) * dimCaja; rcol < (((y / 3) * dimCaja) + dimCaja); rcol++) {
			if (tablero[rfila][rcol].numero == valor) {
				return false;
			}
		}
	}
	return true;
}//Funcion para saber si un valor es valido para una casilla o no

//BUSCAR CASILLAS VACIAS

bool encontrar(tTablero tablero, int &x, int &y) {
	for (x = 0; x < DIMENSION; x++) {
		for (y = 0; y < DIMENSION; y++) {
			if (tablero[x][y].estado == VACIO) {
				return true;
			}
		}
	}
	return false;
}//Buscador de casillas vacias

//RESOLUCION AUTOMATICA

bool resolucion(tTablero &tablero) {
	int x, y;
	if (!encontrar(tablero, x, y)) {
		return true;
	}
	for (int cand = 1; cand < 10; cand++) {
		if (esValido(tablero, x, y, cand)) {
			tablero[x][y].numero = cand;
			tablero[x][y].estado = RELLENO;
			if (resolucion(tablero)) {
				return true;
			}
			tablero[x][y].numero = 0;
			tablero[x][y].estado = VACIO;
		}
	}
	return false;
} //Resolucion automatica del tablero