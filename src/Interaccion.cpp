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

		if (dentro (*disparo, *disparo->lista[n]).modulo())
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
		
		/*
		Vector dif=aux1->posicion-aux2->posicion;
		float d=dif.modulo();
		float dentro=d-(aux1->superficie.vx+aux2->superficie.vx);

		if(dentro < 0.0f)	
		{
			//El módulo y argumento de la pelota 1
			Vector v1f=aux1->getVelocidad();
			float v1=v1f.modulo();
			Vector ang1f=aux2->getVelocidad();
			float ang1=ang1f.argumento();

			//El módulo y argumento de la pelota 2
			Vector v2f=aux2->getVelocidad();
			float v2=v2f.modulo();
			Vector ang2f=aux2->getVelocidad();
			float ang2=ang2f.argumento();

			//El argumento del vector que une los centros:
			float angd=dif.argumento();

			//Separamos las esferas, lo que se han incrustado
			//La mitad cada una 
			Vector desp(dentro/2*cos(angd), dentro/2*sin(angd));
			
			aux1->posicion=aux1->posicion+dentro;
			aux2->posicion=aux2->posicion-dentro;

			angd=angd-3.14159f/2;//la normal al choque

			//El angulo de las velocidades en el sistema relativo antes del choque
			float th1=ang1-angd;	
			float th2=ang2-angd;

			//Las componentes de las velocidades en el sistema relativo ANTES del choque
			float u1x=v1*cos(th1);
			float u1y=v1*sin(th1);
			float u2x=v2*cos(th2);
			float u2y=v2*sin(th2);	

			//Las componentes de las velocidades en el sistema relativo DESPUES del choque
			//la componente en X del sistema relativo no cambia
			float v1x=u1x;
			float v2x=u2x;

				
			//en el eje Y, rebote elastico
			float m1=aux1->superficie.vx;
			float m2=aux2->superficie.vx;
			float py=m1*u1y+m2*u2y;//Cantidad de movimiento inicial ejey
			float ey=m1*u1y*u1y+m2*u2y*u2y;//Energia cinetica inicial ejey

			//los coeficientes y discriminante de la ecuacion cuadrada
			float _a=m2*m2+m1*m2;
			float _b=-2*py*m2;
			float _c=py*py-m1*ey;	
			float disc=_b*_b-4*_a*_c;
			if(disc<0)	disc=0;

			//las nuevas velocidades segun el eje Y relativo
			float v2y=(-_b+sqrt(disc))/(2*_a);
			float v1y=(py-m2*v2y)/m1;
	
			//Modulo y argumento de las velocidades en coordenadas absolutas
			float modv1,modv2,fi1,fi2;
			modv1=sqrt(v1x*v1x+v1y*v1y);
			modv2=sqrt(v2x*v2x+v2y*v2y);
			fi1=angd+atan2(v1y,v1x);
			fi2=angd+atan2(v2y,v2x);

			//Velocidades en absolutas despues del choque en componentes
			aux1->velocidad.vx=modv1*cos(fi1);
			aux1->velocidad.vy=modv1*sin(fi1);
			aux2->velocidad.vx=modv2*cos(fi2);
			aux2->velocidad.vy=modv2*sin(fi2);

		}*/
		
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
				return Vector(modulo*cos(argumento),modulo*sin(argumento));
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
