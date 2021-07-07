#pragma once
//--------------------------
//Declaración de directivas
//--------------------------
#include <cstdint>
#include <string>
#include <string>

using namespace std;

//Valores fijos para los componentes del emulador
const unsigned int TAMANIO_MEMORIA = 2096;
const unsigned int TAMANIO_REGISTRO = 16;
const unsigned int TAMANIO_INDICE = 16;
const unsigned int TAMANIO_PILA = 16;
const unsigned int CANTIDAD_TECLAS = 16;
const unsigned int ANCHO_VIDEO = 64;
const unsigned int ALTO_VIDEO = 32;

class Chip8
{
public:
	Chip8();

	void cargarROM(string nombreROM);
	void cargarSetFuentes();


	//Componentes del emulador
	uint8_t memoria[TAMANIO_MEMORIA]{};         //Vector que almacena todas las instrucciones del programa.
	uint8_t registro[TAMANIO_REGISTRO]{};       //Vector que almacena instrucciones, llegasdas desde la memoria, para ser ejecutadas
	uint16_t indice[TAMANIO_INDICE]{};          //Vector que almacena direcciones de memoria para ser usadas en operaciones.
	uint16_t contadorPrograma{};                //Vector que almacena la dirección de la siguiente instrucción que será ejecutada.
	uint8_t temporizadorRetraso{};
	uint8_t temporizadorSonido{};
	uint16_t pila[TAMANIO_PILA]{};              //Almacena niveles de apilado (no comprendo, todavía) 
	uint8_t punteroPila{};
	uint8_t teclas[CANTIDAD_TECLAS]{};          //Almacena el número de teclas que usa el emulador.
	uint32_t video[ANCHO_VIDEO * ALTO_VIDEO]{}; //Determina el tamaño de la pantalla
	uint16_t opCode;
};

