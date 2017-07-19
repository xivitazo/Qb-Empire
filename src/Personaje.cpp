#include "Personaje.h"
#include "Disparo.h"
#include <cstdio>
#include "Lista_de.h"

Personaje::Personaje(Luchadores tipo, unsigned int nivel, Vector posicion, Vector destino):
	destino(destino),
	Ayuntamiento(posicion)
{
	memoria=destino;
	this -> tipo=LUCHADOR;
	especifico = tipo;
//	rango_visibilidad=10;
	switch (tipo)
	{
	case CABALLERO:
		setStats(250,200, 1.5, 1, 10);
		planta= CUADRADO;
		//Rectángulo como si fuera un caballo
		superficie.setValor(2,1);
		rango=3;
		rango_visibilidad=10;
		break;
	case ARQUERA:
		setStats(150,150, 0.75,0.1, 3);
		planta = REDONDO;
		//Cono
		superficie.setValor(1,1);
		rango=30;
		rango_visibilidad=40;
		break;
	case GIGANTE:
		setStats(1000,250, 2.5,3, 3);
		planta=REDONDO;
		//La tetera asesina
		superficie.setValor(2,2);
		rango_visibilidad=4;
		rango=3;
		break;
	case SOLDADO:
		setStats(200,100, 1, 0.5, 3);
		planta=CUADRADO;
		//cubo
		superficie.setValor(1,1);
		rango_visibilidad=5;
		rango=1;
		break;
	case GUERRERO:
		setStats(300,300, 1.5,0.5, 4.5);
		planta=CUADRADO;
		//Prisma de base cuadrada de altura 2l
		superficie.setValor(1,1);
		rango_visibilidad=6;
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

void Personaje :: setStats ( unsigned int vida, unsigned int ataque,float vel_ataque ,float salpicadura, float velocidad)
{
	this -> vida = vida;
	vida_max = vida;
	this -> ataque = ataque;
	this -> velocidad_max = velocidad;
	this -> vel_ataque = vel_ataque;
	this -> salpicadura= salpicadura;
}

bool Personaje:: meMuevo()
{
	if (destino==posicion)
	{
		velocidad=0;
		return 1;
	}
	velocidad=(destino-posicion).unitario()*(float)velocidad_max;
	return 0;
}

bool Personaje :: Atacar (Edificio** lista, Disparo** disparos)
{

	if (Ayuntamiento :: Atacar (lista, disparos))
	{
		destino=posicion;
		return true;
	}
	if(!poderDisparar())
		return false;
	Edificio* objetivo=0;
	for(int n=0;lista[n]!=0;n++)
	{
		if ((posicion-lista[n]->getPosicion()).modulo()<= rango_visibilidad)
		{
			if(objetivo==0)
				objetivo=lista[n];
			else if((objetivo->getPosicion()-posicion).modulo()>(lista[n]->getPosicion()-posicion).modulo())
				objetivo=lista[n];
		}
	}
	if(objetivo)
	{
		destino=objetivo->getPosicion();
		return false;
	}
	destino=memoria;
	return false;
}


void Personaje :: subirNivel ()
{
	switch (especifico)
	{
	case CABALLERO:
		setStats(vida_max*1.15,ataque*1.15,vel_ataque,salpicadura,velocidad_max*1.1);
		break;
	case ARQUERA:
		setStats(vida_max*1.20,ataque*1.125,vel_ataque,salpicadura,velocidad_max*1.02);
		break;
	case GIGANTE:
		setStats(vida_max*1.3,ataque*1.2,vel_ataque,salpicadura,velocidad_max*1.3);
		break;
	case SOLDADO:
		setStats(vida_max*1.2,ataque*1.15,vel_ataque,salpicadura,velocidad_max*1.05);
		break;
	case GUERRERO:
		setStats(vida_max*1.25,ataque*1.175,vel_ataque,salpicadura,velocidad_max*1.15);
		break;
	}
		vida=vida_max;
}

void Personaje :: Timer (float t) 
{
	Edificio :: Timer(t);
	meMuevo();
	posicion=posicion+velocidad*t;
		
	//velocidad=velocidad+aceleracion*t;
	//printf("Posicion: %d\t%d\nVelocidad:%d\t%d", posicion.vx, posicion.vy, velocidad.vx, velocidad.vy);
}

void Personaje :: Dibuja (Color equipo)
{	
	glPushMatrix();
	glColor3ub(equipo.getRed(),equipo.getGreen(),equipo.getBlue());
	glTranslatef(posicion.vx,posicion.vy, 1);
	
	switch(especifico)
	{
	case CABALLERO:	glutSolidSphere(2,20,20);	break;
	case ARQUERA:	glutSolidCone((double)1,(double) altura, 20, 20);	break;
	case GIGANTE:	
		glRotatef(90,1, 0, 0);
		glutSolidTeapot(5);		break;
	case SOLDADO:	glutSolidSphere(1,20,20);	break;
	case GUERRERO:	glutSolidIcosahedron();		break;
	}
	glPopMatrix();
	
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

bool Personaje:: mover(Vector destino)
{
	if(huyendo)
		return false;
	destino=memoria;
	return true;
}