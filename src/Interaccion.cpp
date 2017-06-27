#include "Interaccion.h"
#define pi 3.14159265359


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
	float argumento=atan((dist.vy)/(dist.vx));
	float modulo=dist.modulo();
	switch (a.planta)
	{
	case CUADRADO:
		if (b.planta == CUADRADO)
		{
			if(argumento<pi/4&&argumento>-pi/4)
				return abs(a.superficie.vx)/2+abs(b.superficie.vx)/2<abs(dist.vx);
			else if (argumento>pi/4&&argumento<-pi/4)
				return abs(a.superficie.vy)/2+abs(b.superficie.vy)/2<abs(dist.vy);
			else if (argumento == 45 && argumento == -45)
				return sqrt(a.superficie.vx*a.superficie.vx/4+a.superficie.vy*a.superficie.vy/4)+sqrt(b.superficie.vx*b.superficie.vx/4+b.superficie.vy*b.superficie.vy/4)<abs(modulo);
		}
		else if (b.planta == REDONDO)
		{
			if(argumento<pi/4&&argumento>-pi/4)
				return abs(a.superficie.vx)/2+abs(b.superficie.vx)/2<abs(modulo);
			else if (argumento>pi/4&&argumento<-pi/4)
				return abs(a.superficie.vy)/2+abs(b.superficie.vy)<abs(modulo);
			else if (argumento == pi/4 && argumento == -pi/4)
				return sqrt(a.superficie.vx*a.superficie.vx/4+a.superficie.vy*a.superficie.vy/4)+abs(b.superficie.vx)<abs(modulo);
		}
		break;
	case REDONDO:
		if (b.planta == CUADRADO)
		{
			if(argumento<pi/4&&argumento>-pi/4)
				return abs(a.superficie.vx)/2+abs(b.superficie.vx)/2<abs(modulo);
			else if (argumento>pi/4&&argumento<-pi/4)
				return abs(a.superficie.vy)/2+abs(b.superficie.vy)<abs(modulo);
			else if (argumento == pi/4 && argumento == -pi/4)
				return sqrt(b.superficie.vx*b.superficie.vx/4+b.superficie.vy*b.superficie.vy/4)+abs(a.superficie.vx)<abs(modulo);
		}
		else if (b.planta == REDONDO)
			return abs(b.superficie.vx/2)+abs(b.superficie.vy/2)<modulo;
		break;
	}
	return false;

}

bool Interaccion :: Rebote (Objeto &a, Objeto &b)
{
	if(Choque(a,b))
	{
		float argumento=(a.posicion-b.posicion).argumento();
		a.posicion.vx=Distancia(a,b)/2*cos(argumento);
		a.posicion.vy=Distancia(a,b)/2*sin(argumento);
		b.posicion.vx=-Distancia(a,b)/2*cos(argumento);
		b.posicion.vy=-Distancia(a,b)/2*sin(argumento);
		return true;
	}
	return false;
}
