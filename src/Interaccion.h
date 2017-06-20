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
	static void Ataque(Disparo* disparo);
	static bool Choque ( Objeto &a, Objeto &p);
	static bool Rebote (Objeto &a, Objeto&b);
	//El personaje es el que se esta moviendo por tanto es el personaje
	//el que debe cambiar la trayectoria para evitar el obstaculo
	static float Distancia (Objeto &a, Objeto &b);
};