#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(Vector posicion) :
	Edificio(2500, 6, Color (215, 45, 109) ,CUADRADO, Vector (6, 15)),
	num_disparos(0)
{
	this -> posicion = posicion;
	for (int n=0;n<MAX_DISPAROS; n++)
	{
		disparos[n]=0;
	}
	tipo = AYUNTAMIENTO;
	especifico = NINGUNO;
	rango_visibilidad=35;
	rango=30;
}
 
Ayuntamiento :: ~Ayuntamiento(void)
{
}

bool Ayuntamiento :: Atacar (Edificio** lista)
{
	Edificio* objetivo=0;
	for(int n=0; lista[n]!=0;n++)
	{
		if((posicion-lista[n]->getPosicion()).modulo()<=rango)
		{
			if(objetivo==0)
				objetivo = lista[n];
			else if ((objetivo->getPosicion()-posicion).modulo()<(lista[n]->getPosicion()-posicion).modulo())
				objetivo= lista[n];
		}
	}
	if (objetivo == 0)
		return false;
	for (int n=0; n<MAX_DISPAROS; n++)
	{
		if (disparos[n]==0)
		{
			new Disparo (posicion,objetivo,ataque,salpicadura, lista);
			return true;
		}
	}
	return false;

}

void Ayuntamiento :: Timer (float t)
{
	Edificio :: Timer (t);
}

void Ayuntamiento :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, superficie, altura);
	for (int n=0; n<MAX_DISPAROS;n++)
	{
		if (disparos[0]==0)
		{
			break;
		}
		disparos[n]->Dibuja();
		continue;
	}
}

void Ayuntamiento :: subirNivel () 
{
	vida_max*=2;
	vida=vida_max;
	ataque*=1.35;
	altura+=4;
}