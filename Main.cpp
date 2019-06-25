/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
//prototipos
#include "IA.h"
void mainaux(int op, tListaSudokus &listaS, tListaJugadores &ListaJ);//Switch de seleccion de opciones de menú
void menuListaSudokus(tListaSudokus &lista, tListaJugadores &listaJ);//Muestra el menú de la lista de sudokus
void auxListaSudokus(tListaSudokus &lista, int opcion, tListaJugadores &listaJ);//Switch de seleccion de opciones de la lista de sudokus


//MAIN

int main(){
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(LC_ALL, "spanish");
	bool okJ = false;
	tListaJugadores listaJ;
	tListaSudokus listaS;
	int op = 1;
	if ((!cargarJ(listaJ)) || (!cargarS(listaS))) {
		colorLetra(12);
		cout << "No se pudo cargar la lista de jugadores" << endl;
	}
	else {
		while (op != 0) {
			system("cls");
			colorLetra(132);
			cout << "SUDOKU" << endl;
			colorLetra(15);
			cout << "1.- Jugar/opciones de sudokus" << endl;
			colorLetra(10);
			cout << "2.- Jugadores ordenados por identificador" << endl;
			cout << "3.- Jugadores ordenados por puntos" << endl;
			cout  << "0.- Salir" << endl;
			cout << "=================================================" << endl;
			cout << "Introduce una opción: ";
			colorLetra(14);
			cin >> op;
			mainaux(op, listaS, listaJ);
		}

	}
	borrarJugadores(listaJ);
	delete[] listaJ.jugadores;
	return 0;
}

//OPCIONES MAIN

void mainaux(int op, tListaSudokus &listaS, tListaJugadores &ListaJ) {
	switch (op)
	{
	case 1: menuListaSudokus(listaS, ListaJ);
		guardar(listaS);
		guardarJ(ListaJ);
		break;
	case 2: tListaJugadores OrdenadaID = ordenarPorID(ListaJ);
		mostrar(OrdenadaID);
		delete[] OrdenadaID.jugadores;
		system("pause");
		break;
	case 3: tListaJugadores OrdenadaPuntos = ordenarPorRanking(ListaJ);
		mostrar(OrdenadaPuntos);
		delete[] OrdenadaPuntos.jugadores;
		system("pause");
	case 0:	colorLetra(13);
		cout << "Guardando datos, espere..." << endl;
		for (int i = 0; i < 4; i++) {
			cout << "." << endl;
			Sleep(100);
		}
		guardar(listaS);
		guardarJ(ListaJ);
		cout << "Guardado completado, cerrando programa" << endl;
		break;
	}
}

//MENÚ LISTA SUDOKUS

void menuListaSudokus(tListaSudokus &lista, tListaJugadores &listaJ) {
	int opcion = -1;
	while (opcion != 0) {
		system("cls");
		mostrar(lista);
		colorLetra(10);
		cout << endl << "======================================================================";
		cout << endl << "¿Qué desea hacer?" << endl;
		cout << "1.- Jugar un sudoku              2.- Añadir un sudoku" << endl;
		cout << "3.- Eliminar sudoku              4.- Sudoku aleatorio" << endl;
		cout << "0.- Salir" << endl;
		cout << "Opción: ";
		colorLetra(14);
		cin >> opcion;
		auxListaSudokus(lista, opcion, listaJ);
	}

}

//OPCIONES LISTA SUDOKUS

void auxListaSudokus(tListaSudokus &lista, int opcion, tListaJugadores &listaJ) {
	colorLetra(10);
	bool comp = false;
	string archivo;
	switch (opcion) {
	case 1:cout << "¿Qué tablero desea jugar? ";
		colorLetra(14);
		cin >> opcion;
		for (int i = 0; i < lista.cont; i++) {
			if (opcion != i + 1) {
				comp = false;
			}
			else {
				comp = true;
				i = lista.cont;
			}
		}
		if (!comp) {
			colorLetra(12);
			cout << "No se pudo detectar la opción, pruebe de nuevo" << endl;
			system("pause");
		}
		else {
			puntuarJugardor(listaJ, jugarUnSudoku(lista.array[opcion - 1]), 0);
			guardarJ(listaJ);
		}
		break;
	case 2: registrarSudoku(lista);
		break;
	case 3:	cout << "¿Qué archivo desea borrar? ";
		cin >> archivo;
		borrarArchivo(lista, archivo);
		break;
	case 4: archivo = "random";
		sudokuRandom(lista, listaJ);
		borrarArchivo(lista, archivo);
		break;
	case 0: break;
	}
}


void colorFondo(int	color) {
	HANDLE handle =	GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void colorLetra(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}




