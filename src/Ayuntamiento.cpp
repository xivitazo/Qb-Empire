#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(void) :
	Edificio(2500, 6, Color (215, 45, 109) ,CUADRADO, Vector (6, 6))
{
	setPosicion(4, 35);

}
 
Ayuntamiento :: ~Ayuntamiento(void)
{
}

bool Ayuntamiento :: Atacar (Edificio* objetivo)
{
	if ((objetivo->getPoscion()-posicion).modulo()>rango)
	{
		return 0;
	}
	new Disparo (posicion,objetivo,ataque,salpicadura);
	return 1;
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