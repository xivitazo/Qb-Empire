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

		if (dentro (*disparo, *disparo->lista[n])>-1.0f)
			disparo->lista[n]->vida-=disparo->daño;
	}
	return;
}

float Interaccion :: Distancia (Objeto &a, Objeto &b)
{
	return sqrt((a.posicion.vx-b.posicion.vx)*(a.posicion.vx-b.posicion.vx)+(a.posicion.vy-b.posicion.vy)*(a.posicion.vy-b.posicion.vy));
}

bool Interaccion:: rebote (Objeto &h1, Objeto &h2)			//Interaccion entre hombres
{
	Vector dentro=Interaccion :: dentro(h1,h2);
	Personaje *aux1=dynamic_cast<Personaje *>(&h1);
	Personaje *aux2=dynamic_cast<Personaje *>(&h2);
	if(aux1&&aux2){
		aux1->posicion=aux1->posicion-dentro/2.0f;
		aux2->posicion=aux2->posicion+dentro/2.0f;
		return true;
	}
	else if(aux1)
	{
		aux1->posicion=aux1->posicion+dentro;
		return true;
	}
	else if(aux2)
	{
		aux2->posicion=aux2->posicion+dentro;
		return true;
	}
	else
	{
		h1.posicion=h1.posicion-dentro/2.0f;
		h2.posicion=h2.posicion+dentro/2.0f;
		return true;
	}
	/*if(dentro.modulo())	
	{
		float v1=h1.getVelocidad().modulo();
		float ang1=h1.getVelocidad().argumento();
		float v2=h2.getVelocidad().modulo();
		float ang2=h2.getVelocidad().argumento();
		float angd=dif.argumento();
		Vector desp(dentro/2*cos(angd),dentro/2*sin(angd));	
		h1.posicion=h1.posicion+desp;
		h2.posicion=h2.posicion-desp;
		return true;
	}*/
	return false;
}

Vector Interaccion :: dentro (Objeto &a, Objeto &b)
{
	Vector dist=a.posicion-b.posicion;
	if(a.planta==CUADRADO)
	{
		if(b.planta==CUADRADO)
		{
			Vector superposicion=(a.superficie+b.superficie)/2.0F-dist;

			if((abs(dist.vx) < (a.superficie.vx+b.superficie.vx)/2.0)&&
				(abs(dist.vy) < (a.superficie.vy+b.superficie.vy)/2.0))
			{
				return superposicion;
		
				/*if(abs(tan(dist.argumento()))<=1)
					return (a.superficie.vx/2+b.superficie.vx/2)-dist.vx;
				else if(abs(tan(dist.argumento()))>1)
					return (a.superficie.vy/2+b.superficie.vy/2)-dist.vy;*/
			}
		}
		else if(b.planta==REDONDO)
		{
			Vector superposicion=(a.superficie+b.superficie)/2.0F-dist;

			if((abs(dist.vx) < (a.superficie.vx+b.superficie.vx)/2.0)&&
				(dist.vy < (a.superficie.vy+b.superficie.vy)/2.0))
			{
				return superposicion;
			}
		}
	}
	else if(a.planta == REDONDO)
	{
		if(b.planta == REDONDO)
		{
			float modulo=-dist.modulo()+(a.superficie.vx+b.superficie.vx);
			float argumento=dist.argumento();
			if(modulo>0)
				return Vector(modulo*cos(argumento),modulo*sin(argumento));;
			//return a.superficie.vx+b.superficie.vx-dist.modulo();
		}
		else if(b.planta==CUADRADO)
		{
			Vector superposicion=(a.superficie+b.superficie)/2.0F-dist;

			if((abs(dist.vx) < (a.superficie.vx+b.superficie.vx)/2.0)&&
				(dist.vy < (a.superficie.vy+b.superficie.vy)/2.0))
			{
				return superposicion;
			}
		}

		/*
		if(abs(tan(dist.argumento()))<=1)
			return (a.superficie.vx/2+b.superficie.vx/2)-dist.vx;
		else if(abs(tan(dist.argumento()))>1)
			return (a.superficie.vy/2+b.superficie.vy/2)-dist.vy;*/
	}
	return Vector(0,0);
}
