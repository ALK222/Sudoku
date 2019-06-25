/*Programa de Alejandro Barrachina y Airam Martín
Practica 2: Sudokus*/
#pragma once
#include "Juego.h"



//CONSTANTES Y TIPOS

const int MAX_SUDOKUS = 20;

typedef tSudoku tSudokus[MAX_SUDOKUS];

typedef struct {
	tSudokus array; //array de sudokus
	int cont;
}tListaSudokus; //lista de longitud variable de sudokus

void crearListaVacia(tListaSudokus &lista); // Inicializa lista a lista vacía
bool cargarS(tListaSudokus &lista); //guardar 
void mostrar(const tListaSudokus &lista);// visualiza por pantalla la lista de Sudokus dada.
bool guardar(const tListaSudokus &lista); //almacena en el archivo listasudokus.txt el contenido de la lista y devuelve un bool que indica si se ha podido actualizar o no
bool registrarSudoku(tListaSudokus &lista); //solicita los datos de un nuevo sudoku y lo inserta en lista en su orden correspondiente a no ser de que ya haya un sudoku de mismo nombre.
void insertarS(tListaSudokus &lista, const tSudoku &sudoku, bool &lleno, bool &encontrado); //inserta un sudoku en la lista de sudokus
bool buscarFichero(const tListaSudokus &lista, string nombreFich); //devuelve un booleano que indica si existe o no un sudoku en lista con nombre de fichero igual a nombreFich
bool operator<(const tSudoku &opIzq, const tSudoku &opDer); /* sobrecarga del operador < para los sudokus. Devuelve true si el nivel del sudoku opIzq es menor que el nivel del sudoku 
															opDery, a igual nivel, devuelve true si el fichero del Sudoku opIzq es menor que el fichero del Sudoku opDer*/
int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku); /* devuelve la posición de lista en la que debería insertarse sudoku para respetar el orden existente en la lista.
																	Debe implementar una búsqueda binaria */
//void borrarArchivo(tListaSudokus &lista);
bool suficientesVacios(tTablero &tablero);
void rellenarArchivo(tTablero &tablero, tSudoku &sudoku);
void borrarArchivo(tListaSudokus &Lista, string &archivo);