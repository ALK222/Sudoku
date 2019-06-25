/*Programa de Alejandro Barrachina y Airam Martín
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
	bool terminado; //indica si el tablero está lleno
}tJuego;


//Prototipos
int jugarUnSudoku(const tSudoku &sudoku);/*dada la información del sudoku elegido lleva a cabo todas las acciones correspondientes a haber
elegido la opción 1 de esta versión y devuelve la puntuación
obtenida por el jugador (0 si aborta la resolución antes de rellenar
el tablero o los puntos asociados al sudoku elegido en caso de
resolverlo)*/
void iniciaJuego(tJuego &juego, const tSudoku & sudoku); /* recibe en sudoku la información del sudoku elegido para jugar e inicializa el
parámetro juego a un juego no acabado con dicha información como
registro del sudoku a jugar y con un tablero inicializado según se ha
indicado en el módulo anterior*/
bool cargaJuego(tJuego &juego, const tSudoku &sudoku); /*actualiza el tablero del parámetro juego con el contenido del archivo cuyo nombre
figura en el parámetro de tipo tSudoku recibido*/
void mostrarJuego(const tJuego &juego); /*muestra por pantalla la información del sudoku que se va a jugar así como el tablero del mismo*/
void mostrarMenuJugada(tJuego &juego, int desventaja); /*Muestra las opciones de una jugada*/
void opcionJugada(tJuego &juego, int op, int desventaja); /*Switch con las opciones de la jugada*/
int filaColumna(int op); /*Switch para pedir los datos de fila y columna*/
