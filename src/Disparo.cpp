#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"
#include "ETSIDI.h"
#define G 9.8

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
	muerto=*destino;
	this -> posicion = posicion;
	//señuelo=destino[0];
	velocidad_max=20;
	tiempo=0;
	z=0;
	muerto=*destino;
	velocidad_z=G/2*(destino->getPosicion()-posicion).modulo()/velocidad_max;
}

Disparo::~Disparo(void)
{
}

bool Disparo::Mueve(void)
{
	/*if(*destino!=señuelo)
		destino=&muerto;*/
	Vector v;
	v=(destino->posicion-posicion).unitario();
//Hallas la direccion ue debe seguir el disparo de forma dinámica
	velocidad = v*velocidad_max;
	if((destino->posicion-posicion).modulo()<0.5f)
		velocidad=(destino->posicion-posicion)*(velocidad_max/0.5f);
	if (abs(posicion.vx-destino->posicion.vx)<=destino->superficie.vx/2 && abs(posicion.vy-destino->posicion.vy)<=destino->superficie.vy/2)
//Si esta dentro de los limites del objetivo
	{
		Interaccion :: Ataque (this);
		return 0;
	}
	if(velocidad.modulo()<=0.001f)
	{
		Interaccion :: Ataque (this);
		return 0;
	}
	return true;

}

bool Disparo :: Timer_disparo(float t)
{
	muerto=*destino;
	posicion=posicion+velocidad*t;
	z=velocidad_z*t-G/2*t*t;
	tiempo+=t;
	return Mueve();
}

void Disparo :: Dibuja(void)
{
	glPushMatrix();
		glTranslatef(posicion.vx,posicion.vy,z);
		glColor3ub(lanzaDado(1.0)*color.getRed(), lanzaDado(1.0)*color.getGreen(), lanzaDado(1.0)*color.getBlue());
		glutSolidSphere(radio,10,10);
	glPopMatrix();
}

