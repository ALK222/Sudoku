/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/

#include "Juego.h"
#include "IA.h"

// INICIO DEL JUEGO

int jugarUnSudoku(const tSudoku &sudoku) {
	tJuego juego;
	juego.sudoku = sudoku;
	int puntos = 0;
	int desventaja = 0;
	iniciaJuego(juego, sudoku); //Inicio del juego
	if (cargaJuego(juego, sudoku)) {
		juego.terminado = false;
		while (!juego.terminado) {
			mostrarJuego(juego);
			mostrarMenuJugada(juego, desventaja);
			if (tableroLleno(juego.tablero)) {
				mostrarJuego(juego);
				colorLetra(13);
				cout << "Sudoku terminado!" << endl;
				system("pause");
				juego.terminado = true;
			}
		}
	}
	else {
		colorFondo(PALETA[2]);
		cout << "Error al iniciar el juego, compruebe el archivo del tablero" << endl;
		system("cls");
		system("exit");
	}
	return sudoku.nivel;
}

//INICIO DE CASILLAS Y DEL TABLERO

void iniciaJuego(tJuego &juego, const tSudoku &sudoku) {
	iniciaTablero(juego.tablero);
	cargaJuego(juego, sudoku);
}

//CARGA DE TABLEROS

bool cargaJuego(tJuego &juego, const tSudoku &sudoku) {
	bool carga = false;
	if (cargarTablero(sudoku.fichero, juego.tablero)) {
		carga = true;
	}
	else {
		carga = false;
	}
	return carga;
}

//MOSTRAR TABLERO

void mostrarJuego(const tJuego &juego) {
	dibujarTablero(juego.tablero);
}

//MENU DE CADA JUGADA

void mostrarMenuJugada(tJuego &juego, int desventaja) {
	colorLetra(10);
	int opcion = -1;
		cout << "¿Qué desea hacer? " << endl;
		cout << "1.- Poner numero         2.- Quitar numero" << endl;
		cout << "3.- Resolver simples     4.- Mostrar posibles" << endl;
		cout << "5.-Reiniciar tablero     6.- Resolver" << endl;
		cout << "0.-Salir" << endl << "Opcion: ";
		colorLetra(14);
		cin >> opcion;
		opcionJugada(juego, opcion, desventaja);
}

//OPCIONES DE JUGADA

void opcionJugada(tJuego &juego, int op, int desventaja) {
	int numero, fila, columna;
	colorLetra(10);
	switch (op){
	case 1: cout << "¿Qué numero desea poner? ";
		colorLetra(14);
		cin >> numero;
		fila = filaColumna(1);
		columna = filaColumna(2);
		if (!ponerNum(juego.tablero, fila, columna, numero)) {
			colorLetra(12);
			cout << "No es posible introducir el número en la casilla" << endl;
			system("pause");
		}
		break;
	case 2:	fila = filaColumna(1);
		columna = filaColumna(2);
		borrarNum(juego.tablero, fila, columna);
		break;
	case 3: rellenarSimples(juego.tablero);
		desventaja++;
		break;
	case 4: fila = filaColumna(1);
		columna = filaColumna(2);
		mostrarPosibles(juego.tablero, fila, columna);
		break;
	case 5: iniciaJuego(juego, juego.sudoku);
		break;
	case 6:if (!resolucion(juego.tablero)) {
		colorLetra(12);
		cout << "Este sudoku no tiene solucion" << endl;
		system("pause");
	}
		break;
	case 0: juego.terminado = true;
		break;
	}
}

//AUXILIAR DEL MENU DE OPCIONES PARA COGER DATOS DE FILA Y COLUMNA

int filaColumna(int op) {
	int dato;
	colorLetra(10);
	switch (op) {
	case 1: cout << "fila: ";
		colorLetra(14);
		cin >> dato;
		break;
	case 2: cout << "Columna: ";
		colorLetra(14);
		cin >> dato;
		break;
	}
	return dato;
}



