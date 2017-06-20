#pragma once
#include "Edificio.h"

class Ayuntamiento : public Edificio
{
protected:
	unsigned int ataque, salpicadura;

public:
	Ayuntamiento(void);
	~Ayuntamiento(void);
	bool Atacar (Edificio* objetivo, Edificio** lista);
	//Devuelve un 1 cuando crea un disparo hacia el objetivo
	void Timer (float t);
	void Dibuja(Color equipo=0);
	void subirNivel(unsigned int tipo);


	friend class Interaccion;
};
