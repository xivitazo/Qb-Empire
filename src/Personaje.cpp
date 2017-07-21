#include "Personaje.h"
#include "Disparo.h"
#include <cstdio>
#include "Lista_de.h"

Personaje::Personaje(Luchadores tipo, unsigned int nivel, Vector posicion, Vector destino):
	destino(destino),
	huyendo(0),
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
		//Rect�ngulo como si fuera un caballo
		superficie.setValor(2, 1);
		rango=3.5;
		rango_visibilidad=12;
		altura=3;
		break;
	case ARQUERA:
		setStats(150,150, 0.75,0.1, 3);
		planta = CUADRADO;
		//Cono
		superficie.setValor(1,1);
		rango=30;
		rango_visibilidad=40;
		altura=2;
		break;
	case GIGANTE:
		setStats(1000,250, 2.5,3, 3);
		planta=CUADRADO;
		//La tetera asesina
		superficie.setValor(3,3);
		rango_visibilidad=4;
		rango=3;
		altura=5;
		break;
	case SOLDADO:
		setStats(200,100, 1, 0.5, 3);
		planta=CUADRADO;
		//cubo
		altura=2;
		superficie.setValor(1,1);
		rango_visibilidad=5;
		rango=1;
		
		break;
	case GUERRERO:
		setStats(300,300, 1.5,0.5, 4.5);
		planta=CUADRADO;
		//Prisma de base cuadrada de altura 2l
		altura=3;
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
		huyendo=0;
		velocidad=0;
		return true;
	}
	velocidad=(destino-posicion).unitario()*(float)velocidad_max;
	return false;
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
	if(objetivo!=0)
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
	Ayuntamiento :: Timer(t);
	meMuevo();
	posicion=posicion+velocidad*t;
		
	//velocidad=velocidad+aceleracion*t;
	//printf("Posicion: %d\t%d\nVelocidad:%d\t%d", posicion.vx, posicion.vy, velocidad.vx, velocidad.vy);
}

void Personaje :: Dibuja (Color equipo)
{	
	glPushMatrix();
	color_max=equipo;
	color_vida();
	glColor3ub(color.getRed(),color.getGreen(),color.getBlue());
	glTranslatef(posicion.vx,posicion.vy, 0);
	
	switch(especifico)
	{
	case CABALLERO:	
		//glutSolidSphere(altura, 30, 30);
		for(int n=0;n<altura;n++)
		{
		glPushMatrix();
		glTranslatef(-superficie.vx/4, 0,0.5+n);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(+superficie.vx/4, 0,0.5+n);
		glutSolidCube(1);
		glPopMatrix();
		}
		
		break;
		
	case ARQUERA:	
		glutSolidCone((double)superficie.vx,(double) altura, 20, 20);
		break;
	case GIGANTE:	
		glTranslatef(0,0,2);
		glRotatef(90,1, 0, 0);
		glutSolidTeapot(altura);		
		break;
	case SOLDADO:
		for(int n=0; n<altura; n++)
		{
			glPushMatrix();
			glTranslatef(0,0,0.5+n);
			glutSolidCube(1);
			glPopMatrix();
		}break;
	case GUERRERO:	
		for(int n=0; n<altura; n++)
		{
			glPushMatrix();
			glTranslatef(0,0,0.5+n);
			glutSolidCube(1);
			glPopMatrix();
		}break;
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
	memoria=destino;
	return true;
}
bool Personaje :: huir()
{
	huyendo=1;
	memoria.vx=posicion.vx-50;
	memoria.vy=posicion.vy;
	return true;
}