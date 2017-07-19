#include "Disparo.h"
#include "Interaccion.h"
#include "glut.h"
#include "ETSIDI.h"
#define G 9.8

using namespace ETSIDI;
Disparo::Disparo(Vector posicion, Vector destino,unsigned int daño, unsigned int salpicadura): 
	Objeto(1,Color(100+lanzaDado(1.0)*155,100+lanzaDado(1.0)*155,100+lanzaDado(1.0)*155),REDONDO,1),
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
	z0=1;
	z=z0;
	velocidad_z=(-z0+G/2*(destino-posicion).modulo()/velocidad_max*(destino-posicion).modulo()/velocidad_max)/((destino-posicion).modulo()/velocidad_max);
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
	z=z0+velocidad_z*tiempo-G/2*tiempo*tiempo;
	tiempo+=t;
	return Mueve();
}

void Disparo :: Dibuja(void)
{
	glPushMatrix();
		glTranslatef(posicion.vx,posicion.vy,z);
		glColor3ub(200-lanzaDado(1.0)*color.getRed(), 200-lanzaDado(1.0)*color.getGreen(), 200-lanzaDado(1.0)*color.getBlue());
		glutSolidSphere(radio,10,10);
	glPopMatrix();
}

