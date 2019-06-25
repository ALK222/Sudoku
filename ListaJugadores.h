/*Programa de Alejandro Barrachina
Practica 2: Sudokus*/
#pragma once
#include "listaSudokus.h"
#include "Jugador.h"


const int MAX_JUGADORES = 10;

typedef tJugador tArrayJugadores[MAX_JUGADORES];
const int JUGADORES = 5;

typedef struct {
	tJugadorPtr *jugadores;
	int cont;
	int capacidad;
}tListaJugadores;


//PROTOTIPOS

void crearListaVacia(tListaJugadores &l, int capacidad); //Inicializa la lista de jugadores
bool cargarJ(tListaJugadores &l); //carga la lista de jugadores desde el archivo listaJugadores.txt
void mostrar(const tListaJugadores &l); // muestra la lista de jugadores
bool guardarJ(tListaJugadores &l); //guarda la lista de jugadores desde el archivo listaJugadores.txt
bool puntuarJugardor(tListaJugadores &l, int puntos, int desventaja); // Solicita el id. de un jugador y le añade la puntuación pertiente
void insertarJ(tListaJugadores &lista, const string &id, int puntos, bool& ok); // Inserta un jugador en la lista
int buscar(tListaJugadores &lista, const string &id, int ini, int fin); // Busca un jugadore y su posicion en la lista
tListaJugadores ordenarPorRanking(const tListaJugadores &lista); // Devuelve una copia de la lista ordenada por puntuación
tListaJugadores copia(const tListaJugadores &lista);//devuelve una copia de la lista
tListaJugadores ordenarPorID(const tListaJugadores &lista); // Devuelve una copia de la lista ordenada por identificador
void ampliar(tListaJugadores &lista); // Amplia la lista al doble de su capacidad manteniendo los datos que habia en la orginial
//void borrarListaJugadores(tListaJugadores &lista); //Libera la memoria dinamica usada por la lista
void borrarJugadores(tListaJugadores &lista); //Libera la memoria dinamica usada por un jugador
//void liberarArray(tListaJugadores &lista);  //Libera la memoria  consumida por el array
