/*Programa de Alejandro Barrachina y Airam Mart�n
Practica 2: Sudokus*/
#pragma once
#include "Tablero.h"




//CONSTANTES Y TIPOS

typedef struct {
	string fichero; //nombre del archivo del tablero
	int nivel; //numero de puntos que permite conseguir
} tSudoku;

typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool terminado; //indica si el tablero est� lleno
}tJuego;


//Prototipos
int jugarUnSudoku(const tSudoku &sudoku);/*dada la informaci�n del sudoku elegido lleva a cabo todas las acciones correspondientes a haber
elegido la opci�n 1 de esta versi�n y devuelve la puntuaci�n
obtenida por el jugador (0 si aborta la resoluci�n antes de rellenar
el tablero o los puntos asociados al sudoku elegido en caso de
resolverlo)*/
void iniciaJuego(tJuego &juego, const tSudoku & sudoku); /* recibe en sudoku la informaci�n del sudoku elegido para jugar e inicializa el
par�metro juego a un juego no acabado con dicha informaci�n como
registro del sudoku a jugar y con un tablero inicializado seg�n se ha
indicado en el m�dulo anterior*/
bool cargaJuego(tJuego &juego, const tSudoku &sudoku); /*actualiza el tablero del par�metro juego con el contenido del archivo cuyo nombre
figura en el par�metro de tipo tSudoku recibido*/
void mostrarJuego(const tJuego &juego); /*muestra por pantalla la informaci�n del sudoku que se va a jugar as� como el tablero del mismo*/
void mostrarMenuJugada(tJuego &juego, int desventaja); /*Muestra las opciones de una jugada*/
void opcionJugada(tJuego &juego, int op, int desventaja); /*Switch con las opciones de la jugada*/
int filaColumna(int op); /*Switch para pedir los datos de fila y columna*/
