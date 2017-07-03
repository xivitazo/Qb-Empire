#pragma once
#include <iostream>
#include <cstdio>
#include "Vector.h"
<<<<<<< HEAD
#include "Color.h"

using namespace std;

enum Nombre {JUGADOR1, JUGADOR2, MAPA, MENU};
=======
#include "ETSIDI.h"

using namespace ETSIDI;
>>>>>>> refs/remotes/origin/master

class Mapa
{
protected:
<<<<<<< HEAD
	Color cespedA[75][75], cespedB[75][75], barroA[75][75];
	unsigned int nombre;
	
=======
	Sprite *nube01;
	Sprite *nube02;
	Sprite *nube03;

>>>>>>> refs/remotes/origin/master
public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	void cesped1();
	void cesped2();
	void barro();
	void montaña();
	void nubes();
	void inicializa ();
};

