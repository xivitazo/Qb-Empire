#include "Disparo.h"


Disparo::Disparo(Vector posicion, Edificio* _destino,unsigned int da�o, unsigned int salpicadura, Edificio** lista ): 
	Objeto(1,Color(rand(),rand(),rand()),REDONDO,1)
{
	//radio peque�o (copiado de Pang)
	radio=0.1f;
	this ->da�o=da�o;
	this ->destino = destino;
	this ->posicion = posicion;
	this -> salpicadura = salpicadura;
	this -> lista = lista;
}

Disparo::~Disparo(void)
{
}

bool Disparo::Mueve(void)
{
	Vector v;
	v=(destino->posicion-posicion).unitario();
//Hallas la direccion ue debe seguir el disparo de forma din�mica
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
}

void Disparo :: Dibuja(void)
{
	glTranslatef(posicion.vx,posicion.vy,5);
	glColor3ub(255, 255, 255);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.vx,-posicion.vy,-5);
}

