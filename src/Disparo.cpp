#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"
#include "ETSIDI.h"

using namespace ETSIDI;
Disparo::Disparo(Vector posicion, Edificio* destino,unsigned int daño, unsigned int salpicadura, Edificio** lista ): 
	Objeto(1,Color(lanzaDado(1.0)*255,lanzaDado(1.0)*255,lanzaDado(1.0)*255),REDONDO,1),
	destino(destino),
	daño(daño),
	salpicadura(salpicadura),
	lista(lista)
{
	//radio pequeño (copiado de Pang)
	radio=0.3f;
	this -> posicion = posicion;
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
	if((destino->posicion-posicion).modulo()<10)
		velocidad=(destino->posicion-posicion)*(velocidad_max/10);
	if (abs(posicion.vx-destino->posicion.vx)<=destino->superficie.vx && abs(posicion.vy-destino->posicion.vy)<=destino->superficie.vy)
//Si esta dentro de los limites del objetivo
	{
		Interaccion :: Ataque (this);
		return 0;
	}
	return true;

}

bool Disparo :: Timer_disparo(float t)
{
	posicion=posicion+velocidad*t;
	return Mueve();
}

void Disparo :: Dibuja(void)
{
	glPushMatrix();
	glTranslatef(posicion.vx,posicion.vy,5);
	glColor3ub(lanzaDado(1.0)*color.getRed(), lanzaDado(1.0)*color.getGreen(), lanzaDado(1.0)*color.getBlue());
	glutSolidSphere(radio,10,10);
	glPopMatrix();
}

