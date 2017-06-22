#pragma once
#include "Ayuntamiento.h"

class Personaje : public Ayuntamiento
{
protected:
	Vector velocidad;
	Vector aceleracion;	//introduzco aceleración de los personajes
	float velocidad_max;
	float tiempo_ataque;
	void setStats ( unsigned int vida,unsigned int ataque, float tiempo_ataque, float velocidad);
	Vector destino;

public:
	Personaje(Luchadores tipo, unsigned int nivel, Vector posicion, Vector destino);
	/*Lista de tipos:
		0-Prueba, todo 1 (subidas de nivel del 10%
		1-.........*/
	//Personaje(){} //constructor de oficio
	//Personaje (int x, int y, int z);
	virtual ~Personaje(void);
	bool meMuevo ();
	//devuele un 1 cuando llega a la posicion
	bool Atacar (Edificio** lista);
	//Ataca, o se mueve hasta donde pueda atacar para golpear al objetivo
	//Devuelve un 1 cuando crea un disparo hacia el objetivo
	void Dibuja(Color equipo=0);
	void Timer (float t);
	void subirNivel();
	bool setVelocidad (Vector velocidad);

	friend class Interaccion;
	friend class Lista_de;
};