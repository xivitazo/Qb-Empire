#include "Interaccion.h"


Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{
}

void Interaccion:: Ataque (Disparo* disparo)
{
	//Falta por programar, me faltan los apuntes de ayer
	//sin embargo solo falta programar el hecho de hacer daño en un área

}

float Interaccion :: Distancia (Objeto &a, Objeto &b)
{
	return sqrt((a.posicion.vx-b.posicion.vx)*(a.posicion.vx-b.posicion.vx)+(a.posicion.vy-b.posicion.vy)*(a.posicion.vy-b.posicion.vy));
}

bool Interaccion :: Choque (Objeto &a, Objeto &b)
{
	Vector dist=(a.posicion-b.posicion);
	float modulo=dist.modulo();
	float argumento=atan(dist.vy/dist.vx);
	switch (a.planta)
	{
	case CUADRADO:
		if (b.planta == CUADRADO)
		{
			if(argumento<45&&argumento>-45)
				return abs(a.superficie.vx)+abs(b.superficie.vx)<abs(modulo);
			else if (argumento>45&&argumento<-45)
				return abs(a.superficie.vy)+abs(b.superficie.vy)<abs(modulo);
			else if (argumento == 45 && argumento == -45)
				return sqrt(a.superficie.vx*a.superficie.vx+a.superficie.vy*a.superficie.vy)+sqrt(b.superficie.vx*b.superficie.vx+b.superficie.vy*b.superficie.vy)<abs(modulo);
		}
		else if (b.planta == REDONDO)
		{
			if(argumento<45&&argumento>-45)
				return abs(a.superficie.vx)+abs(b.superficie.vx)<abs(modulo);
			else if (argumento>45&&argumento<-45)
				return abs(a.superficie.vy)+abs(b.superficie.vy)<abs(modulo);
			else if (argumento == 45 && argumento == -45)
				return sqrt(a.superficie.vx*a.superficie.vx+a.superficie.vy*a.superficie.vy)+abs(b.superficie.vx)<abs(modulo);
		}
		break;
	case REDONDO:
		if (b.planta == CUADRADO)
		{
			if(argumento<45&&argumento>-45)
				return abs(a.superficie.vx)+abs(b.superficie.vx)<abs(modulo);
			else if (argumento>45&&argumento<-45)
				return abs(a.superficie.vy)+abs(b.superficie.vy)<abs(modulo);
			else if (argumento == 45 && argumento == -45)
				return sqrt(b.superficie.vx*b.superficie.vx+b.superficie.vy*b.superficie.vy)+abs(a.superficie.vx)<abs(modulo);
		}
		else if (b.planta == REDONDO)
			return abs(b.superficie.vx)+abs(b.superficie.vy)<modulo;
		break;
	}
	return false;

}

bool Interaccion :: Rebote (Objeto &a, Objeto &b)
{
	if(Choque(a,b))
	{
		if(!a.setVelocidad((a.posicion-b.posicion).perpendicular()))
			b.setVelocidad((a.posicion-b.posicion).perpendicular());
		return true;
	}
	return false;
}