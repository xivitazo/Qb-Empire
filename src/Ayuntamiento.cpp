#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(Vector posicion) :
	Edificio(2500, 6, Color (215, 45, 109) ,CUADRADO, Vector (6, 15)),
	num_disparos(0),
	ataque(100),
	salpicadura(2)
{
	this -> posicion = posicion;
	for (int n=0;n<MAX_DISPAROS; n++)
	{
		disparos[n]=0;
	}
	tipo = AYUNTAMIENTO;
	especifico = NINGUNO;
//	rango_visibilidad=35;
	rango=50;
	vel_ataque=0.5f;
	tiempo=0;
}
 
Ayuntamiento :: ~Ayuntamiento(void)
{
}

bool Ayuntamiento :: Atacar (Edificio** lista)
{
	int objetivo=0;
	for(int n=0; lista[n]!=0;n++)
	{
		if((posicion-lista[n]->getPosicion()).modulo()<=rango)
		{
			if(objetivo==0)
				objetivo = n;
			else if ((lista[objetivo]->getPosicion()-posicion).modulo()>(lista[n]->getPosicion()-posicion).modulo())
				objetivo= n;
		}
	}
	if (objetivo == 0)
		return false;
	for (int n=0; n<MAX_DISPAROS; n++)
	{
		if (disparos[n]==0 && poderDisparar())
		{
			tiempo=0;
			disparos[n] = new Disparo (posicion,lista[objetivo],ataque,salpicadura, lista);
			return true;
		}
	}
	return false;

}

void Ayuntamiento :: Timer (float t)
{
	Edificio :: Timer (t);
	for(int n=0;n<MAX_DISPAROS;n++)
	{
		if(!disparos[n])
			continue;
		if(!disparos[n]->Timer_disparo(t))
		{
			delete disparos[n];
			disparos[n]=0;
		}
	}
	tiempo+=t;
}

void Ayuntamiento :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, superficie, altura);
	
	for (int n=0; n<MAX_DISPAROS;n++)
	{
		if (disparos[n]!=0)
		{
			disparos[n]->Dibuja();
		}
		
	}
}

void Ayuntamiento :: subirNivel () 
{
	vida_max*=2;
	vida=vida_max;
	ataque*=1.35;
	altura+=4;
}

bool Ayuntamiento :: poderDisparar()
{
	if(tiempo>=vel_ataque)
	{
		return true;
	}
	return false;
}