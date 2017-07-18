#pragma once
#include "Personaje.h"
#include "Cuartel.h"
#include "Fabrica.h"
#include "Recursos.h"
#include "Interaccion.h"


//Tama�o del vector de cosas
#define MAX_TIPOS 13 
#define MAX_GENERAL 2
enum General {EDIFICIOS, COMBATIENTES};


class Lista_de
{
	int numero;
	
	Recursos almacen;

	Color equipo;
	unsigned int *max;
	unsigned int limite_tropas;// limite por unidad de tiempo

	//Numero de "cosas" generadas
	//Distinto del numero de tropas y dem�s
	Edificio  *lista [MAX];
	//Vector que contiene edificios y personajes


	//Atrinutos Type-Luchadores
	//Esta pirmero la info de las enumeraicones Type y seguidamente las de Luchadores
	//Toda la informacion la tiene el ayuntamiento, si se quieren saber estas cosas, 
	//vente al ayuntamiento y coge numero como en tu casa
	unsigned int max_Type[MAX_GENERAL];
	unsigned int numero_generado[MAX_GENERAL];
	unsigned int nivel[MAX_TIPOS];
	//tener cuidado que static este funcionaria tanto para nuestro ayuntamiento
	//como para el del rival en caso de que exista
	

public:
	Lista_de(Vector ayuntamiento, Color equipo);
	~Lista_de(void);
	bool Agregar (Type tipo, Vector posicion);	
	bool Agregar (Luchadores especifico, Vector destino);	
	/*
		tipo es lo que quieres a�adir:
			1-Cuartel
			2-F�brica
			3-Personaje
		especifico de lo que haces
			Si es personaje:
				1-Prueba(todo1)
				2-...
			Si es F�brica
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
	bool subirNivel (Type tipo);
	bool subirNivel(Luchadores tipo);
	void Timer (float t);
	void Rebote();
	bool generarRecursos();
	Edificio* getPosN(int posicion){return lista[posicion];}
	Edificio** getLista() {return lista;}
	Recursos getAlmacen(){return almacen;}
	int getNivel(Type tipo){return nivel[tipo];}
	int getNivel(Luchadores tipo){return nivel[LUCHADOR+tipo];}
	int getMax (General tipo){return max_Type[tipo];}
	int atacar(Disparo** disparos, Edificio** enemigos);




	void prueba(int tipo);
};