#pragma once
//la encargada de cualquier interaccion
#include "Edificio.h"
#include "Mapa.h"
#include "Vector.h"
#include "Disparo.h"
#include "Personaje.h"


class Interaccion
{
public:
	Interaccion(void);
	virtual ~Interaccion(void);
	static void Ataque(Vector posicion, unsigned int daño, unsigned int salpicadura); //Introduces donde atacar y cuando daño haces
	static void Choque ( Personaje &a, Objeto &p);
	//El personaje es el que se esta moviendo por tanto es el personaje
	//el que debe cambiar la trayectoria para evitar el obstaculo
	static float Distancia (Objeto &a, Objeto &b);
};