#pragma once
#include "Personaje.h"
#include "Cuartel.h"
#include "Fabrica.h"
#include "Recursos.h"
#include "Interaccion.h"

//Tamaño del vector de cosas
#define MAX_TIPOS 13 
#define MAX_GENERAL 2
#define COLA 100
enum General {EDIFICIOS, COMBATIENTES};


class Lista_de
{
	int numero;
	
	Recursos almacen;

	Color equipo;
	unsigned int *max;
	unsigned int limite_tropas;// limite por unidad de tiempo

	//Numero de "cosas" generadas
	//Distinto del numero de tropas y demás
	Edificio  *lista [MAX];
	//Vector que contiene edificios y personajes
	Luchadores cola_generar[COLA];
	int numero_cola;


	//Atrinutos Type-Luchadores
	//Esta pirmero la info de las enumeraicones Type y seguidamente las de Luchadores
	//Toda la informacion la tiene el ayuntamiento, si se quieren saber estas cosas, 
	//vente al ayuntamiento y coge numero como en tu casa
	unsigned int max_Type[MAX_GENERAL];
	unsigned int numero_generado[MAX_GENERAL];
	unsigned int numero_actual[MAX_GENERAL ];
	unsigned int nivel[MAX_TIPOS];
	Recursos coste[MAX_TIPOS];
	int coste_nivel[MAX_TIPOS];
	Vector destino;
	//tener cuidado que static este funcionaria tanto para nuestro ayuntamiento
	//como para el del rival en caso de que exista
	

public:
	Lista_de(Vector ayuntamiento, Color equipo);
	~Lista_de(void);
	bool Agregar (Type tipo, Vector posicion);	
	bool Agregar (Luchadores especifico, Vector destino);	
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
	int Morir (); 
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
	void inicializarCostes();
	bool generarCombatientes();
	void AñadirOro(int n){almacen.set(almacen.getComida(),almacen.getHierro(),almacen.getOro()+n);}
	void AñadirComida(int n){almacen.set(almacen.getComida()+n,almacen.getHierro(),almacen.getOro());}
	void AñadirHierro(int n){almacen.set(almacen.getComida(),almacen.getHierro()+n,almacen.getOro());}
	




	void prueba(int tipo);
	friend class Menus;
};