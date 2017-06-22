#include "Interaccion.h"


Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{
}

void Interaccion:: Ataque (Disparo* disparo)
{
	disparo ->radio=disparo -> salpicadura;
	for (int n=0;disparo->lista[n]!=0 ;n++)
	{

		if (Choque (*disparo, *disparo->lista[n]))
			disparo->lista[n]->vida-=disparo->daño;
	}
	return;
}

float Interaccion :: Distancia (Objeto &a, Objeto &b)
{
	return sqrt((a.posicion.vx-b.posicion.vx)*(a.posicion.vx-b.posicion.vx)+(a.posicion.vy-b.posicion.vy)*(a.posicion.vy-b.posicion.vy));
}

bool Interaccion :: Choque (Objeto &a, Objeto &b)
{
	Vector dist=(a.posicion-b.posicion);
	float argumento=atan((dist.vy/2)/(dist.vx/2));
	float modulo=dist.modulo();
	switch (a.planta)
	{
	case CUADRADO:
		if (b.planta == CUADRADO)
		{
			if(argumento<45&&argumento>-45)
				return abs(a.superficie.vx)/2+abs(b.superficie.vx)/2<abs(modulo);
			else if (argumento>45&&argumento<-45)
				return abs(a.superficie.vy)/2+abs(b.superficie.vy)/2<abs(modulo);
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
