#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"

Disparo::Disparo(Vector posicion, Edificio* _destino,unsigned int daño, unsigned int salpicadura ): 
	Objeto(1,Color(rand(),rand(),rand()),REDONDO,1)
{
	//radio pequeño (copiado de Pang)
	radio=0.1f;
	this ->daño=daño;
	this ->destino = destino;
	this ->posicion = posicion;
	this -> salpicadura = salpicadura;
}

Disparo::~Disparo(void)
{
}

bool Disparo::Mueve(void)
{
	Vector v;
	v=(destino->posicion-posicion).unitario();
//Hallas la direccion ue debe seguir el disparo de forma dinámica
	velocidad = v*velocidad_max;
	if (abs(posicion.vx-destino->posicion.vx)<=destino->superficie.vx && abs(posicion.vy-destino->posicion.vy)<=destino->superficie.vy)
//Si esta dentro de los limites del objetivo
	{
		return true;
	}
	return 0;

}

void Disparo :: Timer(float t)
{
	posicion=posicion+velocidad*t;
	Mueve();
}

void Disparo :: Dibuja(void)
{
	glTranslatef(posicion.vx,posicion.vy,5);
	glColor3ub(rand(), rand(), rand());
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.vx,-posicion.vy,-5);
}

