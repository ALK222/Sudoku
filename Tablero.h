/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#pragma once
#include "Casilla.h"

//CONSTANTES Y TIPOS

typedef tCasilla tTablero[DIMENSION][DIMENSION];

//PROTOTIPOS

void iniciaTablero(tTablero tablero);/* inicializa el tablero tablerode forma que todas las casillas 
sean vacías y tengan como valores posibles todos los del intervalo[1, 9].*/
bool cargarTablero(string nombreFichero, tTablero tablero); /* recibe el tablero tableroinicializado
como hace el subprograma anterior, lo actualiza con la información almacenada en el archivo de nombre
nombreFichero que contiene el tablero del sudoku a jugar y devuelve un booleano que indica si la carga se ha podido 
realizar.Los valores posibles de las casillas deberán quedar convenientemente actualizados.*/
void dibujarTablero(const tTablero tablero); // muestra por pantalla el tablero dado.
void quitarPosible(tTablero tablero, int x, int y);//Procesa los valores posibles de la casilla (x,y) [x e y entre 0 y 8]
bool ponerNum(tTablero tablero, int fila, int columna, int c);//Pone el numero en la casilla (fila, columna) si es posible
bool borrarNum(tTablero tablero, int fila, int columna);//Borra un numero de la casilla con las coordenadas (fila, coluna)
void rellenarPosible(tTablero tablero, int fila, int columna, int nuevo, int opcion);//rellena el valor posible con el numero dado
bool tableroLleno(const tTablero tablero);// Devuelve si el tablero está lleno o no
void mostrarPosibles(const tTablero tablero, int fila, int columna); // Muestra los valores posibles de una casilla
void rellenarSimples(tTablero tablero); //Rellena las casillas con solo un valor porsible
