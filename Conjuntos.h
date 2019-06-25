/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#pragma once
#include "Header.h"


//CONSTANTES Y TIPOS
const int DIMENSION = 9;
typedef bool tElementos[DIMENSION];//Subconjunto del conjunto de elementos {1,2,3,4,5,6,7,8,9}
typedef struct {
	int nElem;//Cardinal del conjunto
	tElementos elementos;//Elementos contenidos en el conjunto
}tConjunto;



//PROTOTIPOS

void cjto_vacio(tConjunto &c); //inicializa cjto c al vacio
void cjto_lleno(tConjunto &c); //inicializa c con todos los valores a 1
bool pertenece(const tConjunto &c, int e); //Devuelve si e(numero entero entre [1,9]) pertenece a c
void annadeElemento(tConjunto &c, int e); //Añade un elemento e(entero entre [1,9]) al conjunto
void borrarElemento(tConjunto &c, int e); //Borrar un elemento e(entero entre [1,9]) al conjunto
int numElems(tConjunto &c);//Devuelve el numero de elementos que tiene c
bool esUnitario(const tConjunto &c, int &e); //Dice si el cjto tiene un solo valor y lo devuelve
void mostrar(const tConjunto &c);//devuelve los elementos de c
