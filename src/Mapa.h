#pragma once
#include <iostream>
#include <cstdio>
#include "Vector.h"
#include "Color.h"
#include "ETSIDI.h"
using namespace std;
using namespace ETSIDI;
enum Nombre {JUGADOR1, JUGADOR2, MAPA, MENU};

class Mapa
{
protected:
	Color cespedA[75][75], cespedB[75][75], barroA[75][75];
	unsigned int nombre;

	Sprite *nube01;
	Sprite *nube02;
	Sprite *nube03;

public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	//void cesped1();
	//void cesped2();
	void cesped();
	void barro();
	void montaña();
	void nubes();
	void inicializa ();
};

