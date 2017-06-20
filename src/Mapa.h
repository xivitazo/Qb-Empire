#pragma once
#include <cstdio>
#include "Vector.h"

class Mapa
{
protected:
	
public:
	Mapa(void);
	virtual ~Mapa(void);
	void Dibuja ();
	void cesped();
	void rio();
	void montaña();
};

