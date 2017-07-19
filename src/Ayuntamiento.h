#pragma once
#include "Edificio.h"

class Ayuntamiento : public Edificio
{
protected:
	unsigned int ataque, salpicadura, num_disparos;
	float vel_ataque;
	float tiempo;
	//Vector que contiene disparos del equipo

public:
	Ayuntamiento(Vector posicion);
	~Ayuntamiento(void);
	bool Atacar (Edificio** lista, Disparo** disparos);
	//Devuelve un 1 cuando crea un disparo hacia el objetivo
	void Timer (float t);
	void Dibuja(Color equipo=0);
	void subirNivel();
	bool poderDisparar();


	friend class Interaccion;
};
