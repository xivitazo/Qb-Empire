#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"
#include "ETSIDI.h"

using namespace ETSIDI;
Disparo::Disparo(Vector posicion, Edificio* _destino,unsigned int daño, unsigned int salpicadura, Edificio** lista ): 
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
	if (abs(posicion.vx-destino->posicion.vx)<=destino->superficie.vx && abs(posicion.vy-destino->posicion.vy)<=destino->superficie.vy)
//Si esta dentro de los limites del objetivo
	{
		Interaccion :: Ataque (this);
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
	glColor3ub(lanzaDado(1.0)*color.getRed(), lanzaDado(1.0)*color.getGreen(), lanzaDado(1.0)*color.getBlue());
	glutSolidSphere(radio,10,10);
	glTranslatef(-posicion.vx,-posicion.vy,-5);
}

