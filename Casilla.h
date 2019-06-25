/*Programa creado por Alejandro Barrachina y Airam Mart�n
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
void iniciaCasilla(tCasilla &casilla);// inicializa el estado de la casilla dada a vac�o y su conjunto de valores posibles al conjunto{ 1,2,3,4,5,6,7,8,9 }
void rellenaCasilla(tCasilla &casilla, char c, bool fija);/*rellena el estado y el n� de casilla de acuerdo con los valores de fija 
y c.Si c es el car�cter espacio en blanco se tratar� de una casilla vac�a; si c['0', '9'] el n� que almacena esa casilla ser� el entero
equivalente(c�'0')y fija indicar� si se trata de una casilla fija(valor true para fija) o rellenada(valor por defecto false).*/
void dibujaCasilla(const tCasilla &casilla); //Dibuja cada casilla del sudoku
bool esSimple(tCasilla &casilla, int &numero); //Devuelve si una casilla tiene un unico valor posible