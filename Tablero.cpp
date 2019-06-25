/*Programa de Alejandro Barrachina y Airam Martín
Practica 2: Sudokus*/
#include "Tablero.h"


//TABLERO VARIO

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int k = 0; k < DIMENSION; k++) {
			iniciaCasilla(tablero[i][k]);
		}
	}
}

//CARGA DE TABLERO DESDE ARCHIVO

bool cargarTablero(string nombreFichero, tTablero tablero) {
	fstream archivo;
	bool ok = false;
	char dato;
	archivo.open(nombreFichero);
	if (archivo.is_open()) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int k = 0; k < DIMENSION; k++) {
				archivo >> noskipws;
				archivo >> dato;
				if (dato != '\n') {
					rellenaCasilla(tablero[i][k], dato, true);
					if (tablero[i][k].estado != VACIO) {
						quitarPosible(tablero, i, k);
					}
				}
				else {
					k--;
				}
			}
		}
		ok = true;
		archivo.close();
	}
	else {
		archivo.close();
		ok = false;
	}
	return ok;
}

//DIBUJO EN PANTALLA DEL TABLERO

void dibujarTablero(const tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		if (i % 3 == 0) {
			for (int k = 0; k < DIMENSION * 3 + 3 + 1; k++) {
				colorFondo(PALETA[0]);
				cout << "-";
			}
			cout << endl;
		}
		for (int j = 0; j < DIMENSION; j++) {
			if (j % 3 == 0) {
				colorFondo(PALETA[0]);
				cout << "|";
			}
			colorFondo(PALETA[0]);
			cout << " ";
			dibujaCasilla(tablero[i][j]);
			colorFondo(PALETA[0]);
			cout << " ";
		}
		colorFondo(PALETA[0]);
		cout << "|" << endl;
		for (int k = 0; k < DIMENSION * 3 + 3 + 1; k++) {
			colorFondo(PALETA[0]);
			cout << "-";
		}
		cout << endl;
	}
}

//ELIMINACION DE POSIBLES
// x e y se consideran cordenadas de 1 a DIMENSION

void quitarPosible(tTablero tablero, int x, int y) {
	int num = tablero[x][y].numero; 
	if (tablero[x][y].estado == FIJA) {
		for (int z = 0; z <= DIMENSION; z++) {
			borrarElemento(tablero[x][y].posibles, z);
		}
		annadeElemento(tablero[x][y].posibles, num);
	}
	for (int i = 0; i < DIMENSION; i++) { //Recorrido de columna
		if (tablero[x][i].estado != FIJA) {
			borrarElemento(tablero[x][i].posibles, num);
		}
	}
	for (int k = 0; k < DIMENSION; k++) { //Recorrido de filas
		if (tablero[k][y].estado != FIJA) {
			borrarElemento(tablero[k][y].posibles, num);
		}
	}
	int	dimCaja	= DIMENSION / 3;
	for (int rfila = (x / 3) * dimCaja; rfila < (((x / 3) * dimCaja) + dimCaja); rfila++) {
		for (int rcol = (y / 3) * dimCaja; rcol < (((y / 3) * dimCaja) + dimCaja); rcol++) {
			borrarElemento(tablero[rfila][rcol].posibles, num);
		}
	}
}

//PONER NUMERO

bool ponerNum(tTablero tablero, int fila, int columna, int c) {
	bool ok = false;
	if ((tablero[fila - 1][columna - 1].estado != VACIO) || (pertenece(tablero[fila - 1][columna - 1].posibles, c - 1) == false)) {
		ok = false;
	}
	else {
		rellenaCasilla(tablero[fila - 1][columna - 1], '0' + c, false);
		quitarPosible(tablero, fila - 1, columna - 1);
			ok = true;
	}
	return ok;
}

//BORRAR NUMERO

bool borrarNum(tTablero tablero, int fila, int columna) {
	int f = fila - 1;
	int c = columna - 1;
	bool posible = true;
	if (tablero[f][c].estado == RELLENO) {
		int borrado = tablero[f][c].numero;
		rellenaCasilla(tablero[f][c], ' ', false);
		for (int i = 0; i < DIMENSION; i++) { //Recorrido de columna
			if (tablero[f][i].numero != borrado) {
				posible = true;
			}
			else {
				posible = false;
				i = DIMENSION;
			}
		}
		if (posible == true) {
			rellenarPosible(tablero, f, c, borrado, 1); //rellena la columna
		}
		
		for (int k = 0; k < DIMENSION; k++) { //Recorrido de filas
			if (tablero[k][c].numero != borrado) {
				posible = true;
			}
			else {
				posible = false;
				k = DIMENSION;
			}
		}
		if (posible == true) {
			rellenarPosible(tablero, f, c, borrado, 2); //rellena la fila
		}
		int	dimCaja = DIMENSION / 3;
		for (int rfila = (f / 3)* dimCaja; rfila < (f / 3)*dimCaja + dimCaja; rfila++) {
			for (int rcol = (c / 3)*dimCaja; rcol < (c / 3)*dimCaja + dimCaja; rcol++) {
				if (tablero[rfila][rcol].numero != borrado) {
					posible = true;
				}
				else {
					posible = false;
					rfila = DIMENSION;
				}
			}
		}
		if (posible == true) {
			rellenarPosible(tablero, f, c, borrado, 3); //rellena la fila
		}
	}
	return posible;
}


//ADICION DE VALORES POSIBLES

void rellenarPosible(tTablero tablero, int fila, int columna, int nuevo, int opcion) {
	switch (opcion)	{
	case 1:
		for (int i = fila; i < DIMENSION; i++) {
			annadeElemento(tablero[i][columna].posibles, nuevo);
		}
		break;
	case 2:
		for (int i = columna; i < DIMENSION; i++) {
			annadeElemento(tablero[fila][i].posibles, nuevo);
		}
		break;
	case 3:
		int	dimCaja = DIMENSION / 3;
		for (int rfila = (fila / 3)* dimCaja; rfila < (fila / 3)*dimCaja + dimCaja; rfila++) {
			for (int rcol = (columna / 3)*dimCaja; rcol < (columna / 3)*dimCaja + dimCaja; rcol++) {
				annadeElemento(tablero[rfila][rcol].posibles, nuevo);
			}
		}
	}
}


//TABLERO LLENO

bool tableroLleno(const tTablero tablero) {
	bool lleno = false;
	int total = 0;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (tablero[i][j].estado == RELLENO) {
				total = total + 1;
			}
			else {
				if (tablero[i][j].estado == FIJA) {
					total = total + 1;
				}
				else {
					if (tablero[i][j].estado == VACIO) {
						total = total - 1;
					}
				}
			}

		}
	}
	if (total == DIMENSION * DIMENSION) {
		lleno = true;
	}
	else {
		lleno = false;
	}
	return lleno;
}

//MOSTRAR POSIBLES
//Fila y columna van de 1 a DIMENSION

void mostrarPosibles(const tTablero tablero, int fila, int columna) {
	int f = fila - 1;
	int c = columna - 1;
	cout << "Los valores posibles para esta casilla son: ";
	for (int i = 0; i < DIMENSION; i++) {
		if (tablero[f][c].posibles.elementos[i] == true) {
			cout << i +1 << " ";
		}
	}
	cout << endl;
}

//RELLENAR CASILLAS SIMPLES

void rellenarSimples(tTablero tablero) {
	int numero = 0;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if ((esSimple(tablero[i][j], numero) == true) && (tablero[i][j].estado == VACIO)) {
				rellenaCasilla(tablero[i][j], '0' + numero, false);		
				quitarPosible(tablero, i, j);
			}
		}
	}
}
