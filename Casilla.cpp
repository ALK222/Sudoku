/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#include "Casilla.h"

//INICIAR CASILLA A CASILLA VACIA

void iniciaCasilla(tCasilla &casilla) {
	casilla.numero = 0;
	casilla.estado = VACIO;
	cjto_lleno(casilla.posibles);
}

//RELLENAR CASILLA

void rellenaCasilla(tCasilla &casilla, char c, bool fija) {
	if (c == ' ') {
		casilla.estado = VACIO;
		casilla.numero = 0;
	}
	else {
		casilla.numero = c -'0';
		if (fija == true) {
			casilla.estado = FIJA;
			for (int i = 0; i < DIMENSION - 1; i++) {
				casilla.posibles.elementos[i] = false;
				casilla.posibles.nElem = 0;
			}
		}
		else {
			casilla.estado = RELLENO;
		}
	}
}

//DIBUJAR CASILLA

void dibujaCasilla(const tCasilla &casilla) {
	if (casilla.estado == FIJA) {
		colorFondo(PALETA[2]);
		cout << casilla.numero;
	}
	else {
		if (casilla.estado == RELLENO) {
			colorFondo(PALETA[0]);
			cout << casilla.numero;
		}
		else {
			if (casilla.estado == VACIO) {
				colorFondo(PALETA[1]);
				cout << casilla.numero;
			}
			else {
				if (casilla.estado == ACTUAL) {
					colorFondo(PALETA[3]);
					cout << casilla.numero;
				}
			}
		}
	}
	
}

//BOOL PARA CASILLAS SIMPLES

bool esSimple(tCasilla &casilla, int &numero) {
	bool ok = false;
	if (casilla.estado == VACIO) {
		if (esUnitario(casilla.posibles, numero) == true) {
			ok = true;
		}
	}
	return ok;
}
