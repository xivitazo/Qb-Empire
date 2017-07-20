#pragma once
#include <iostream>
#include <cstdio>
#include "Vector.h"
#include "Color.h"
#include "ETSIDI.h"
#include "glut.h"
//using namespace std;
using namespace ETSIDI;
enum Nombre {NINGUNA_SEL,JUGADOR1, JUGADOR2, MAPA, MENU};

class Mapa
{
protected:
	Color cespedA[25][25], cespedB[25][25], barroA[25][25];
	unsigned int nombre;

	Sprite *nube01;
	Sprite *nube02;
	Sprite *nube03;
	Sprite *help;

public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	void cesped1();
	void cesped2();
	//void cesped();
	void barro();
	void montaña();
	void nubes();
	void inicializa ();
	void sprites();
};

