#include "Personaje.h"
#include <stdio.h>
#include "Disparo.h"
#include <cstdio>

Personaje::Personaje(int tipo)
{
	if (tipo==0)
	{
		setStats(1,1,1);
	}
	if (tipo==1)
	{
		setStats(100,100,3);
	}
	setPosicion(2,18);
	destino.setValor(150,30);
}

Personaje::~Personaje(void)
{
}

void Personaje :: setStats ( unsigned int vida, unsigned int ataque,unsigned int velocidad)
{
	this -> vida_max = vida;
	this -> ataque = ataque;
	this -> velocidad_max = velocidad;
}

bool Personaje:: meMuevo()
{
	if ((destino-posicion).modulo()<=0.1f)
	{
		velocidad=0;
		return 1;
	}
	velocidad=(destino-posicion).unitario()*(float)velocidad_max;
	return 0;
}

bool Personaje :: Atacar (Edificio &objetivo)
{
	if ((posicion-objetivo.getPoscion()).modulo()> rango)
	{
		//meMuevo(posicion+((posicion-objetivo.getPoscion()).unitario()*((posicion-objetivo.getPoscion()).modulo()-rango)));
		return 0;
	}	
	new Disparo (posicion,objetivo,ataque,salpicadura);
	return 1;
}

void Personaje :: subirNivel (unsigned int tipo)
{
	if (tipo ==1)
	{
		setStats (vida_max*1.1f,ataque*1.1f,velocidad_max*1.1f);
		vida=vida_max;
	}
}

void Personaje :: Timer (float t) 
{
	posicion=posicion+velocidad*t;
	//velocidad=velocidad+aceleracion*t;
	meMuevo();
	printf("Posicion: %d\t%d\nVelocidad:%d\t%d", posicion.vx, posicion.vy, velocidad.vx, velocidad.vy);
}

void Personaje :: Dibuja (Color equipo)
{
	glPushMatrix();
	glColor3ub(equipo.getRed(),equipo.getGreen(),equipo.getBlue());
	glTranslatef(posicion.vx,posicion.vy, 0);
	glutSolidSphere(1,20,20);
	glPopMatrix();
}