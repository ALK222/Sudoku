/*Programa creado por Alejandro Barrachina y Airam Martín
Practica 2: sudokus*/
#pragma once
#include "Conjuntos.h"


//CONSTANTES Y TIPOS

const int PALETA[4] = { 0,1,4,7 };
typedef enum {VACIO, FIJA, RELLENO, ACTUAL}tEstadoCasilla;// colores asociados a los estados
typedef struct {
	int numero;
	tEstadoCasilla estado;
	tConjunto posibles;//valores posibles de una casilla
}tCasilla;


//Zona de inclusiones 
void iniciaCasilla(tCasilla &casilla);// inicializa el estado de la casilla dada a vacío y su conjunto de valores posibles al conjunto{ 1,2,3,4,5,6,7,8,9 }
void rellenaCasilla(tCasilla &casilla, char c, bool fija);/*rellena el estado y el nº de casilla de acuerdo con los valores de fija 
y c.Si c es el carácter espacio en blanco se tratará de una casilla vacía; si c['0', '9'] el nº que almacena esa casilla será el entero
equivalente(c–'0')y fija indicará si se trata de una casilla fija(valor true para fija) o rellenada(valor por defecto false).*/
void dibujaCasilla(const tCasilla &casilla); //Dibuja cada casilla del sudoku
bool esSimple(tCasilla &casilla, int &numero); //Devuelve si una casilla tiene un unico valor posible