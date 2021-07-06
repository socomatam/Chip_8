/*
* Carga el contenido de la ROM al emulador
* 
* 
*/

//-------Declaración de directivas-------//
#include "Chip8.h"
#include <fstream>

//--------Variables globales-------------//
const unsigned int DIRECCION_INICIO = 0x200; //Dirección desde la que empezará a ejecutar instruccions la cpu   

/**
* Procedimiento que carga a la memoria el contenido 
*/
void Chip8::cargarROM(string nombreROM) {
	/* Abre la ROM como un archivo binario y mueve el puntero del archivo hasta el final*/
	ifstream file(nombreROM, ios::binary | ios::ate);

	if (file.is_open()) {
		/* Obtiene el tamaño del archivo y Crea un buffer para almacenar el contenido*/
		streampos tamanio = file.tellg();
		char* buffer = new char[tamanio];

		/* Vuelve al inicio del archivo y llena el buffer */
		file.seekg(0, ios::beg);
		file.read(buffer, tamanio);
		file.close();

		/* Todo el contenido de la rom, en el buffer, se vuelca a la memoria del emulador 
			empezando desde la dirrección 0x200.
		*/
		for (long i = 0; i < tamanio; ++i) {
			memoria[DIRECCION_INICIO + i] = buffer[i];
		}

		/* Borra el buffer */
		delete[] buffer;
	}

}/*Fin cargar rom*/



