#pragma once
#include "Edificio.h"
#include "Interaccion.h"
#define MAX_DISPAROS 10

class Ayuntamiento : public Edificio
{
protected:
	unsigned int ataque, salpicadura, num_disparos;
	Disparo *disparos[MAX_DISPAROS];
	//Vector que contiene disparos del equipo

public:
	Ayuntamiento(Vector posicion);
	~Ayuntamiento(void);
	bool Atacar (Edificio** lista);
	//Devuelve un 1 cuando crea un disparo hacia el objetivo
	void Timer (float t);
	void Dibuja(Color equipo=0);
	void subirNivel(unsigned int tipo);


	friend class Interaccion;
};
