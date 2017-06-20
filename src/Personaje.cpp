#include "Personaje.h"
#include <stdio.h>
#include "Disparo.h"
#include <cstdio>

Personaje::Personaje(Luchadores tipo, unsigned int nivel)
{
	switch (tipo)
	{
	case CABALLERO:
		setStats(250,200, 1.5, 10);
		break;
	case ARQUERA:
		setStats(150,150, 0.75, 3);
		break;
	case GIGANTE:
		setStats(1000,250, 2.5, 3);
		break;
	case SOLDADO:
		setStats(200,100, 1, 3);
		break;
	case GUERRERO:
		setStats(300,300, 1.5, 4.5);
		break;
	}
	for (int n=1; n<nivel; n++)
	{
		subirNivel();
	}
	destino.setValor(rand(),rand());
}

Personaje::~Personaje(void)
{
}

void Personaje :: setStats ( unsigned int vida, unsigned int ataque,float tiempo_ataque ,float velocidad)
{
	this -> vida_max = vida;
	this -> ataque = ataque;
	this -> velocidad_max = velocidad;
	this -> tiempo_ataque = tiempo_ataque;
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

bool Personaje :: Atacar (Edificio* objetivo)
{
	if ((posicion-objetivo->getPoscion()).modulo()> rango)
	{
		//meMuevo(posicion+((posicion-objetivo.getPoscion()).unitario()*((posicion-objetivo.getPoscion()).modulo()-rango)));
		return 0;
	}	
	new Disparo (posicion,objetivo,ataque,salpicadura);
	return 1;
}

void Personaje :: subirNivel ()
{
	if (tipo ==1)
	{
		switch (especifico)
		{
		case CABALLERO:
			setStats(vida_max*1.15,ataque*1.15,tiempo_ataque,velocidad_max*1.1);
			break;
		case ARQUERA:
			setStats(vida_max*1.20,ataque*1.125,tiempo_ataque,velocidad_max*1.02);
			break;
		case GIGANTE:
			setStats(vida_max*1.3,ataque*1.2,tiempo_ataque,velocidad_max*1.3);
			break;
		case SOLDADO:
			setStats(vida_max*1.2,ataque*1.15,tiempo_ataque,velocidad_max*1.05);
			break;
		case GUERRERO:
			setStats(vida_max*1.25,ataque*1.175,tiempo_ataque,velocidad_max*1.15);
			break;
		}
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

bool Personaje :: setVelocidad (Vector velocidad)
{
	this -> velocidad = velocidad;
	return true;
}