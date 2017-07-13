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
#include "Personaje.h"
bool Interaccion:: rebote (Objeto &h1, Objeto &h2)			//Interaccion entre hombres
{																//ENTRE CABEZAS
																	//Vector que une los centros								
	Vector dif=h2.posicion-h1.posicion;
	float d=dif.modulo();
	float dentro=Interaccion :: dentro(h1,h2);
	Personaje *aux=dynamic_cast<Personaje *>(&h1);
	if(aux){
		aux->altura;
	}
	if(dentro>0.0f)													//si hay colision
	{
																	//El modulo y argumento de la velocidad de la pelota1
		float v1=h1.getVelocidad().modulo();
		float ang1=h1.getVelocidad().argumento();

																	//El modulo y argumento de la velocidad de la pelota2
		float v2=h2.getVelocidad().modulo();
		float ang2=h2.getVelocidad().argumento();
	
																		//el argumento del vector que une los centros
		float angd=dif.argumento();	
		
																	//Separamos las esferas, lo que se han incrustado
																	//la mitad cada una
		Vector desp(dentro/2*cos(angd),dentro/2*sin(angd));	
		h1.posicion=h1.posicion+desp;
		h2.posicion=h2.posicion-desp;
		return true;
	}
	return false;
}

float Interaccion :: dentro (Objeto &a, Objeto &b)
{
	Vector dist(b.posicion-a.posicion);
	if(a.planta==CUADRADO)
	{
		Vector superposicion=(a.superficie+b.superficie)/2.0F-dist;

		if((dist.vx < (a.superficie.vx+b.superficie.vx)/2.0)&&
			(dist.vy < (a.superficie.vy+b.superficie.vy)/2.0))
			if(abs(tan(dist.argumento()))<=1)
				return (a.superficie.vx/2+b.superficie.vx/2)-dist.vx;
			else if(abs(tan(dist.argumento()))>1)
				return (a.superficie.vy/2+b.superficie.vy/2)-dist.vy;
	}
	else if(a.planta == REDONDO)
	{
		if(b.planta == REDONDO)
		{
			return a.superficie.vx+b.superficie.vx-dist.modulo();
		}
		if(abs(tan(dist.argumento()))<=1)
			return (a.superficie.vx/2+b.superficie.vx/2)-dist.vx;
		else if(abs(tan(dist.argumento()))>1)
			return (a.superficie.vy/2+b.superficie.vy/2)-dist.vy;
	}
	return false;
}
