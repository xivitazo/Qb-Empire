#pragma once
#include "Coordinador.h"

class Menus
{
public:
	Menus();
	virtual ~Menus(void);

	static void construccion(Lista_de &player);
	static void seleccion(Type tipo, Lista_de &player);
	static void superior(Lista_de &player);
	static void Timer (float t);

	friend class Mundo;
};

