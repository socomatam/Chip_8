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
const unsigned int TAMANIO_SETFUENTES = 80;

Chip8::Chip8() {
	contadorPrograma = DIRECCION_INICIO;
	cargarSetFuentes();
}

/*
* Al inicial el emulador, este busca en la ROM 16 carácteres de 5 bytes
* para cargarlos en la memoria. Cada uno de estos carácteres, en binario,
* representan píxeles en pantalla.
*/
void cargarSetFuentes() {

	uint8_t setFuentes[TAMANIO_SETFUENTES] = {
		0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
		0x20, 0x60, 0x20, 0x20, 0x70, // 1
		0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
		0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
		0x90, 0x90, 0xF0, 0x10, 0x10, // 4
		0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
		0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
		0xF0, 0x10, 0x20, 0x40, 0x40, // 7
		0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
		0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
		0xF0, 0x90, 0xF0, 0x90, 0x90, // A
		0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
		0xF0, 0x80, 0x80, 0x80, 0xF0, // C
		0xE0, 0x90, 0x90, 0x90, 0xE0, // D
		0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
		0xF0, 0x80, 0xF0, 0x80, 0x80  // F
	};
}

/**
* Procedimiento que carga a la memoria el contenido de una ROM
* mete el contenido en un buffer y desde este lo vuelca a la memoria
* Por último borra el buffer.
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
			empezando desde la dirrección 0x200 de la memoria.
		*/
		for (long i = 0; i < tamanio; ++i) {
			memoria[DIRECCION_INICIO + i] = buffer[i];
		}

		/* Borra el buffer */
		delete[] buffer;
	}/* Fin if */

}/*Fin cargar rom*/



