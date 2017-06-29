#pragma once
#include "Coordinador.h"

class Menus
{
public:
	Menus();
	virtual ~Menus(void);

	static void construccion(Mundo &mundo);
	static void seleccion(Type tipo, Mundo &mundo);
	static void superior(Mundo &mundo);
	static void Timer (float t);

	friend class Mundo;
};

