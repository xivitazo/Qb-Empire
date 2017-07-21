#pragma once
#include "Mundo.h"

class Menus
{
	Sprite *disparos;
	Sprite *personajes;
	Sprite *edificios;
public:
	Menus();
	virtual ~Menus(void);

	void construccion(Mundo &mundo);
	void seleccion(Type tipo, Mundo &mundo);
	void superior(Mundo &mundo, float tiempo);
	//void cola(Mundo &mundo);
	void Timer (float t);
	void inicio();
	void game_over();
	void opciones ();
	void you_win();
	void inicializa();
	void creacion ();
	void bandera(Color& equipo);
	


	friend class Mundo;
	friend class Coordinador;
};

