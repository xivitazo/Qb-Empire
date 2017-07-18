#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"
#include "ETSIDI.h"
#define G 9.8

using namespace ETSIDI;
Disparo::Disparo(Vector posicion, Vector destino,unsigned int daño, unsigned int salpicadura): 
	Objeto(1,Color(lanzaDado(1.0)*255,lanzaDado(1.0)*255,lanzaDado(1.0)*255),REDONDO,1),
	destino(destino),
	daño(daño),
	salpicadura(salpicadura)
{
	//radio pequeño (copiado de Pang)
	radio=0.3f;
	this -> posicion = posicion;
	//señuelo=destino[0];
	velocidad_max=20;
	tiempo=0;
	velocidad=(destino-posicion).unitario()*velocidad_max;
	z=0;
	velocidad_z=G/2*(destino-posicion).modulo()/velocidad_max;
}

Disparo::~Disparo(void)
{
}

bool Disparo::Mueve(void)
{
	/*if(*destino!=señuelo)
		destino=&muerto;*/
	Vector v;
	v=(destino-posicion).unitario();
//Hallas la direccion ue debe seguir el disparo de forma dinámica
	velocidad = v*velocidad_max;
	if((destino-posicion).modulo()<0.5f)
		velocidad=(destino-posicion)*(velocidad_max/0.5f);
	if (posicion==destino)
//Si esta dentro de los limites del objetivo
		return true;
	return false;

}

bool Disparo :: Timer_disparo(float t)
{
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

