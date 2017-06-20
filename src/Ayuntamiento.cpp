#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(void) :
	Edificio(2500, 6, Color (215, 45, 109) ,CUADRADO, Vector (6, 6))
{
	rango_visibilidad=35;
	setPosicion(4, 35);
	rango=30;

}
 
Ayuntamiento :: ~Ayuntamiento(void)
{
}

bool Ayuntamiento :: Atacar (Edificio* objetivo, Edificio** lista)
{
	if ((objetivo->getPoscion()-posicion).modulo()>rango)
	{
		return false;
	}
	new Disparo (posicion,objetivo,ataque,salpicadura, lista);
	return true;
}

void Ayuntamiento :: Timer (float t)
{
	Edificio :: Timer (t);
}

void Ayuntamiento :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, superficie, altura);
}

void Ayuntamiento :: subirNivel (unsigned int tipo) 
{
	vida*=2;
	ataque*=1.35;
	altura+=4;
}