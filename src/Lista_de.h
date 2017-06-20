#pragma once
#include "Personaje.h"
#include "Cuartel.h"
#include "Fabrica.h"
#include "Recursos.h"
#include "Interaccion.h"
//#include "Objeto.h" Personaje creo que ya incluye objetos


#define MAX 300
//Tamaño del vector de cosas
#define MAX_TIPOS 13 


class Lista_de
{
	int numero;
	Color equipo;
	//Estableces lo creado para tener un control
	unsigned int cuarteles, fabricas, personajes;
	//Estableces limites para crear
	unsigned int *max;
	unsigned int limite_tropas;// limite por unidad de tiempo

	//Numero de "cosas" generadas
	//Distinto del numero de tropas y demás
	Edificio  *lista [MAX];
	//Vector que contiene edificios y personajes
	Disparo *disparos[MAX];
	//Vector que contiene disparos del equipo


	//Atrinutos Type-Luchadores
	//Esta pirmero la info de las enumeraicones Type y seguidamente las de Luchadores
	//Toda la informacion la tiene el ayuntamiento, si se quieren saber estas cosas, 
	//vente al ayuntamiento y coge numero como en tu casa
	unsigned int max_Type[MAX_TIPOS];
	unsigned int numero_generado[MAX_TIPOS];
	unsigned int nivel[MAX_TIPOS];
	//tener cuidado que static este funcionaria tanto para nuestro ayuntamiento
	//como para el del rival en caso de que exista
	

public:
	Lista_de(unsigned char red=0, unsigned char green=0, unsigned char blue=0);
	~Lista_de(void);
	bool Agregar (Type tipo,Luchadores especifico=NINGUNO , unsigned int cuartel=0);	
	/*
		tipo es lo que quieres añadir:
			1-Cuartel
			2-Fábrica
			3-Personaje
		especifico de lo que haces
			Si es personaje:
				1-Prueba(todo1)
				2-...
			Si es Fábrica
				1-Prueba(todo1)
				2-...
		cuartel es la variable nombre del cuartel que quiere generar una tropa
	*/
	void Dibuja();
	//void rebote(Caja caja);
	//void rebote(Pared pared);
	void Choque();
	void Morir (); 
	//devuelve cuantos personajes han muerto en el bucle
	//los muertos se iguala la direccion a 0 para poder corroborar que no se ha borrado
	int getNumero(){return numero;}
	bool subirNivel (Type tipo, Luchadores especifico=NINGUNO);
	void Timer (float t);
	void Rebote();
	Edificio getPosN(int posicion){return lista[posicion];}
	Edificio** getLista() {return lista;}




	void prueba(int tipo);
};