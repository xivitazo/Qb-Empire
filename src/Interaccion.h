#pragma once
//la encargada de cualquier interaccion
#include "Edificio.h"
#include "Mapa.h"
#include "Vector.h"
#include "Disparo.h"
//#include "Personaje.h"


class Interaccion
{
public:
	Interaccion(void);
	virtual ~Interaccion(void);
	static void Ataque(Disparo* disparo);
	static float dentro ( Objeto &a, Objeto &p); //Devuelve la distancia que estan dentro dos objetos, si sale negativo no chocan
	static bool rebote (Objeto &h1, Objeto&h2);
	//El personaje es el que se esta moviendo por tanto es el personaje
	//el que debe cambiar la trayectoria para evitar el obstaculo
	static float Distancia (Objeto &a, Objeto &b);
};