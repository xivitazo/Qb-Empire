#pragma once
#include "Mundo.h"

class Menus
{
public:
	Menus(void);
	virtual ~Menus(void);

	static void construccion();
	static void seleccion(Type tipo);
	static void superior(Mundo &mundo);
	static void Timer (float t);

	friend class Mundo;
};

