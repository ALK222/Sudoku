/*Programa de Alejandro Barrachina y Airam Martín
Practica 2: Sudokus*/
#include "Conjuntos.h"

//INICIALIZACION A CONJUNTO VACIO

void cjto_vacio(tConjunto &c) {
	for (int i = 1; i < DIMENSION; i++) {
		c.elementos[i] = false;
		c.nElem = 0;
	}
} 

//INICIALIZACION A UN CONJUNTO LLENO

void cjto_lleno(tConjunto &c) {
	for (int i = 0; i < DIMENSION; i++) {
		c.elementos[i] = true;
		c.nElem = 9;
	}
}

//BOOL DE PERTENENCIA A UN CONJUNTO DE RANGO [1,9]

bool pertenece(const tConjunto &c, int e) {
	bool pertenece = false;
	if (c.elementos[e] == true) {
			pertenece = true;
	}
	else {
		pertenece = false;
	}

	return pertenece;
}

//AÑADIR UN ELEMENTO DE [1,9] AL CONJUNTO

void annadeElemento(tConjunto &c, int e) {
	if (!c.elementos[e - 1]) {
		c.elementos[e - 1] = true;
		c.nElem++;
	}
}

//BORRA UN ELEMENTO DEL [1,9] DEL CONJUNTO

void borrarElemento(tConjunto &c, int e) {
	if (c.elementos[e - 1]) {
		c.elementos[e - 1] = false;
		c.nElem--;
	}
}

//DEVUELVE EL NUMERO DE ELEMENTOS QUE TIENE C

int numElems(tConjunto &c) {
	int Cardinal = 0;
	Cardinal = c.nElem;
	return Cardinal;
}

//DEVUELVE SI C ES UNITARIO O NO Y CUAL ES SU UNICO ELEMENTO

bool esUnitario(const tConjunto &c, int &e) {
	bool ok = false;
	if (c.nElem == 1) {
		for (int i = 0; i < DIMENSION; i++) {
			if (c.elementos[i] == true) {
				e = i + 1;
			}
		}
		ok = true;
	}
	else {
		ok = false;
	}
	return ok;
}

//MUESTRA LOS ELEMENTOS DE C

void mostrar(const tConjunto &c) {
	for (int i = 0; i < c.nElem; i++) {
		if (c.elementos[i] == true) {
			cout << i << endl;
		}
	}
}