#include "Objeto.h"
#include <cstdio>

Objeto :: Objeto (float _altura, Color _color , Planta _planta, Vector dimension ,bool _visible):
	color(_color),
	altura(_altura),
	planta(_planta),
	superficie(dimension),
	visible(_visible) 
{
	//no inicializo posicion y vector porque están ya a 0
	//al crearse la clase vector con ellos.
}

Objeto::~Objeto(void)
{
}

Vector Objeto :: getPosicion()
{
	return posicion;
}

void Objeto :: Dibuja(Color equipo)
{
}

void Objeto :: Timer (float t)
{
	if(posicion.vx>238)
		posicion.vx=238;
	else if(posicion.vx<2)
		posicion.vx=2;
	if(posicion.vy>78)
		posicion.vy=78;
	else if(posicion.vy<2)
		posicion.vy=2;
}

void Objeto :: setPosicion (int x, int y)
{
	posicion.vx = x;
	posicion.vy = y;
}