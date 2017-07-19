#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(Vector posicion) :
	Edificio(2500, 6, Color (215, 45, 109) ,CUADRADO, Vector (6, 15)),
	num_disparos(0),
	ataque(100),
	salpicadura(2)
{
	this -> posicion = posicion;
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

bool Ayuntamiento :: Atacar (Edificio** lista, Disparo** disparo)
{
	Vector objetivo;
	for(int n=0; lista[n]!=0;n++)
	{
		if((posicion-lista[n]->getPosicion()).modulo()<=rango)
		{
			if(objetivo==0)
				objetivo = lista[n]->getPosicion();
			else if ((objetivo-posicion).modulo()>(lista[n]->getPosicion()-posicion).modulo())
				objetivo= lista[n]->getPosicion();
		}
	}
	if (objetivo == 0)
		return false;
	if ( poderDisparar())
	{
		tiempo=0;
		*disparo= new Disparo (posicion,objetivo,ataque,salpicadura);
		return true;
	}
	return false;

}

void Ayuntamiento :: Timer (float t)
{
	Edificio :: Timer (t);
	tiempo+=t;
}

void Ayuntamiento :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, superficie, altura);
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