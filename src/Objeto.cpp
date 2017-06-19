#include "Objeto.h"
#include <cstdio>

/*Objeto::Objeto(float a,bool v)
{
	
	altura=a;
	visible=v;
	//no inicializo posicion y vector porque están ya a 0
	//al crearse la clase vector con ellos.
}*/

Objeto :: Objeto (float a, bool v, unsigned int red, unsigned int green, unsigned int blue):
	color(red, green, blue),
	altura(a),
	visible(v) 
{
	//no inicializo posicion y vector porque están ya a 0
	//al crearse la clase vector con ellos.
}

Objeto::~Objeto(void)
{
}

Vector Objeto :: getPoscion()
{
	return posicion;
}

void Objeto :: Dibuja(Color equipo)
{
	glColor3ub(color.getRed(),color.getGreen(),color.getBlue());    
    glTranslatef(posicion.vx, 0, posicion.vy);    
    glutSolidSphere(100,20,20);    
    glTranslatef(-posicion.vx,0,-posicion.vy); 
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