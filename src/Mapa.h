#pragma once
#include <cstdio>
#include "Vector.h"
#include "ETSIDI.h"
#include "glut.h"

using namespace ETSIDI;

class Mapa
{
protected:
	Sprite *nube01;
	Sprite *nube02;
	Sprite *nube03;

public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	void cesped();
	void rio();
	void montaña();
	void nubes();
	void inicializa ();
};

