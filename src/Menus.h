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
	static void inicio();
	static void game_over();
	static void opciones ();
	static void you_win();

	friend class Mundo;
};

