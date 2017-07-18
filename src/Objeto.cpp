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
	/*
	glColor3ub(color.getRed(),color.getGreen(),color.getBlue());    
    glTranslatef(posicion.vx, 0, posicion.vy);    
    glutSolidSphere(100,20,20);    
    glTranslatef(-posicion.vx,0,-posicion.vy); 
	*/
	//printf("x: %f", posicion.vx);
}

void Objeto :: Timer (float t)
{
}

void Objeto :: setPosicion (int x, int y)
{
	posicion.vx = x;
	posicion.vy = y;
}