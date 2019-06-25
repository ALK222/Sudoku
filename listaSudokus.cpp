/*Programa de Alejandro Barrachina y Airam Martín
Practica 2: Sudokus*/
#include "listaSudokus.h"

//CREAR LISTA VACIA DE SUDOKUS

void crearListaVacia(tListaSudokus &lista) {
	lista.cont = 0;
}

//CARGAR LISTA DE SUDOKUS

bool cargarS(tListaSudokus &lista) {
	ifstream archivo;
	int centinela = (-1);
	int dato;
	char aux;
	string resto_linea;
	bool ok = false;
	archivo.open("listaSudokus");
	crearListaVacia(lista);
	if (archivo.is_open()) {
		ok = true;
		archivo >> dato;
		while ((dato != centinela) && (lista.cont < MAX_SUDOKUS)) {
			lista.array[lista.cont].nivel = dato;
			archivo >> noskipws;
			archivo >> aux;
			getline(archivo, lista.array[lista.cont].fichero);
			archivo >> dato;
			lista.cont++;
		}
	}
	return ok;
}

//MOSTRAR LISTA DE SUDOKUS

void mostrar(const tListaSudokus &lista) {
	for (int i = 0; i < lista.cont; i++) {
		colorLetra(10);
		if (i % 2 == 0) {
			cout << i + 1 << ".- Sudoku: ";
			colorLetra(14);
			cout << lista.array[i].fichero;
		}
		else {
			cout << "                   " << i + 1 << ".- Sudoku: ";
			colorLetra(14);
			cout << lista.array[i].fichero << endl;
		}
	}
}

//REGISTRAR SUDOKU

bool registrarSudoku(tListaSudokus &lista) {
	tSudoku sudokun; //Sudoku a insertar
	ofstream archivo;
	bool lleno = false;
	bool repetido = false;
	mostrar(lista);
	colorLetra(10);
	cout << endl << "¿Cómo se llama el sudoku que quiere añadir? ";
	colorLetra(14);
	cin >> sudokun.fichero;
	colorLetra(10);
	cout << "¿Cuántos puntos se pueden conseguir? ";
	colorLetra(14);
	cin >> sudokun.nivel;
	insertarS(lista, sudokun, lleno, repetido);
	colorLetra(12);
	if (lleno) {
		cout << "La lista de sudokus ya está llena" << endl;
		system("pause");
	}
	else if (repetido) {
		cout << "Ya hay un archivo con el mismo nombre en la lista" << endl;
		system("pause");
	}
	else {
		tTablero tablero;
		iniciaTablero(tablero);
		int num = 0;
		archivo.open(sudokun.fichero);
		if (archivo.is_open()) {
			for (int i = 0; i < DIMENSION; i++) {
				for (int j = 0; j < DIMENSION; j++) {
					tablero[i][j].estado = RELLENO;
					dibujarTablero(tablero);
					cin >> tablero[i][j].numero;
					if (tablero[i][j].numero == 0) {
						tablero[i][j].estado = VACIO;
						archivo << ' ';
					}
					else {
						archivo << tablero[i][j].numero;
						tablero[i][j].estado = FIJA;
					}
					system("cls");
				}
				archivo << endl;
			}
		}
		archivo.close();
	}
	guardar(lista);
	return (!lleno) && (!repetido);
}

//GUARDADO DE LISTA

bool guardar(const tListaSudokus &lista) {
	ofstream archivo;
	bool ok = false;
	archivo.open("listaSudokus");
	if (!archivo.is_open()){
		ok = false;
		colorLetra(12);
		cout << "Error al guardar" << endl;
	}
	else {
		for (int i = 0; i < lista.cont; i++) {
			archivo << lista.array[i].nivel;
			archivo << " ";
			archivo << lista.array[i].fichero;
			archivo << endl;
		}
		archivo << "-1";
		ok = true;
	}
	archivo.close();
	return ok;
}

//INSERCION DEL SUDOKU EN LISTA

void insertarS(tListaSudokus &lista, const tSudoku &sudoku, bool &lleno, bool &encontrado){
	int pos = 0;
	if (lista.cont == MAX_SUDOKUS) {
		lleno = true;
	}
		encontrado = buscarFichero(lista, sudoku.fichero);
	if ((!encontrado) && (!lleno)){
		pos = buscarPos(lista, sudoku);
		lista.cont++;
		for(int i = lista.cont; i > pos; i--){
			lista.array[i] = lista.array[i - 1];
		}
		lista.array[pos] = sudoku;
	}
}

//BUSCAR FICHERO

bool buscarFichero(const tListaSudokus &lista, string nombreFich) {
	bool encontrado = false;
	for (int i = 0; i < lista.cont; i++) {
		if (nombreFich == lista.array[i].fichero) {
			encontrado = true;
			i = lista.cont;
		}
	}
	return encontrado;
}

//BUSCAR POSICION

int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku) {
	int ini = 0, fin = lista.cont - 1, mitad;
	while (ini <= fin){
		mitad = (ini + fin) / 2; //Division entera
		if (operator<(sudoku.fichero, lista.array[mitad].fichero)) {
			fin = mitad - 1;
		}
		else {
			ini = mitad + 1;
		}
	}
	return ini;
}





bool suficientesVacios(tTablero &tablero) {
	int totalVacios = 0;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (tablero[i][j].estado == VACIO) {
				totalVacios++;
			}
		}
	}
	if (totalVacios == 0) {
		return false;
	}
	else {
		return true;
	}
}

void rellenarArchivo(tTablero &tablero, tSudoku &sudoku) {
	ofstream archivo;
	archivo.open(sudoku.fichero);
	if (archivo.is_open()) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				if (tablero[i][j].numero == 0) {
					archivo << " ";
				}
				else {
					archivo << tablero[i][j].numero;
				}
			}
			archivo << endl;
		}
	}
}

void borrarArchivo(tListaSudokus &Lista, string &archivo) {
	int pos = 0;
	for (int i = 0; i < Lista.cont; i++) {
		if (archivo == Lista.array[i].fichero) {
			pos = i;
			i = Lista.cont;
		}
	}
	for (int i = pos; i < Lista.cont; i++) {
		Lista.array[i] = Lista.array[i + 1];
	}
	Lista.cont--;
}