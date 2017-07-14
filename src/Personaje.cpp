#include "Personaje.h"
#include <stdio.h>
#include "Disparo.h"
#include <cstdio>

Personaje::Personaje(Luchadores tipo, unsigned int nivel, Vector posicion, Vector destino):
	destino(destino),
	Ayuntamiento(posicion)
{
	this -> tipo=LUCHADOR;
	especifico = tipo;
	rango_visibilidad=10;
	switch (tipo)
	{
	case CABALLERO:
		setStats(250,200, 1.5, 10);
		planta= CUADRADO;
		//Rectángulo como si fuera un caballo
		superficie.setValor(2,1);
		rango=2;
		break;
	case ARQUERA:
		setStats(150,150, 0.75, 3);
		planta = CUADRADO;
		//Pirámide de 4 lados
		superficie.setValor(1,1);
		rango=8;
		break;
	case GIGANTE:
		setStats(1000,250, 2.5, 3);
		planta=REDONDO;
		//La tetera asesina
		superficie.setValor(2,2);
		rango=3;
		break;
	case SOLDADO:
		setStats(200,100, 1, 3);
		planta=CUADRADO;
		//cubo
		superficie.setValor(1,1);
		rango=1;
		break;
	case GUERRERO:
		setStats(300,300, 1.5, 4.5);
		planta=CUADRADO;
		//Prisma de base cuadrada de altura 2l
		superficie.setValor(1,1);
		rango=1;
		break;
	}
	for (unsigned int n=1; n<nivel; n++)
	{
		subirNivel();
	}
	//destino.setValor(100,50);
	//velocidad.setValor(0,0);
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
	if (destino==posicion)
	{
		velocidad=0;
		return true;
	}
	velocidad=(destino-posicion).unitario()*(float)velocidad_max;
	return false;
}

bool Personaje :: Atacar (Edificio** lista)
{
	if (Ayuntamiento :: Atacar (lista))
		return true;
	Edificio* objetivo=0;
	if ((posicion-objetivo->getPosicion()).modulo()> rango && (posicion-objetivo->getPosicion()).modulo()<= rango_visibilidad)
	{
		destino = posicion+((posicion-objetivo->getPosicion()).unitario()*((posicion-objetivo->getPosicion()).modulo()-rango));
		return false;
	}
	return false;
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
	Ayuntamiento :: Timer(t);
	meMuevo();
	posicion=posicion+velocidad*t;
	for(int n=0;n<MAX_DISPAROS;n++)
	{
		if(disparos[n]==0)
			continue;
		if(disparos[n]->Mueve())
		{
			delete disparos[n];
			disparos[n]=0;
		}

	}
	
	//velocidad=velocidad+aceleracion*t;
	//printf("Posicion: %d\t%d\nVelocidad:%d\t%d", posicion.vx, posicion.vy, velocidad.vx, velocidad.vy);
}

void Personaje :: Dibuja (Color equipo)
{
	//glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3ub(equipo.getRed(),equipo.getGreen(),equipo.getBlue());
	glTranslatef(posicion.vx,posicion.vy, 0);
	glutSolidSphere(1,20,20);
	glPopMatrix();
	for (int n=0; n<MAX_DISPAROS;n++)
	{
		if (disparos[0]!=0)
		{
			disparos[n]->Dibuja();
		}
		
	}
	//glEnable(GL_LIGHTING);
}

bool Personaje :: setVelocidad (Vector velocidad)
{
	this -> velocidad = velocidad;
	return true;
}

Vector Personaje :: getVelocidad ()
{
	return velocidad;
}