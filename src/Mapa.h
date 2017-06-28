#pragma once
#include <cstdio>
#include "Vector.h"
#include "Color.h"
enum Nombre {JUGADOR1, JUGADOR2, MAPA, MENU};

class Mapa
{
protected:
	Color cespedA[75][75], cespedB[75][75], barroA[75][75];
	unsigned int nombre;
	
public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	void cesped1();
	void cesped2();
	void barro();
	void montaña();
};

