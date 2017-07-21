#pragma once
#include "Lista_de.h"
#include "Mapa.h"
#include "Vector3D.h"
#include "Disparo.h"

class Mundo
{
	Mapa map;
	Lista_de jugador1, jugador2;
	Disparo* disparos[MAX];
	int numero;

public: 
	Mundo();
	~Mundo();
	void Tecla(unsigned char key);
	void Inicializa();
	void Timer(float t);
	void Dibuja();
	void Raton (int button, int state, Vector pos);
	void RatonPasivo(int x, int y);
	void atacar ();
	void morir();

	
	
	friend class Mapa;
	friend class Coordinador;
	friend class Menus;
};
