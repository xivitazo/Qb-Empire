#include "Ayuntamiento.h"
#include "Disparo.h"

Ayuntamiento :: Ayuntamiento(void) :
	Edificio(100)
{
	color.set(215, 45, 109);
	setPosicion(4, 35);
}
 
Ayuntamiento :: ~Ayuntamiento(void)
{
}

bool Ayuntamiento :: Atacar (Edificio &objetivo)
{
	if ((objetivo.getPoscion()-posicion).modulo()>rango)
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
	casita(posicion, equipo, color, 8, 8);
}

void Ayuntamiento :: subirNivel (unsigned int tipo) 
{
}