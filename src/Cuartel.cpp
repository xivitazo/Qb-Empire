#include "Cuartel.h"


Cuartel :: Cuartel(void):
	tiempo(0), 
	limite_tropas(100), 
	numero_tropas(0), 
	Edificio(100)
{
	color.set(139,69,19);
}

Cuartel :: ~Cuartel(void)
{
}

void Cuartel :: subirNivel(unsigned int tipo)
{
	limite+=20;
}

bool Cuartel :: poderGenerar(void)
{
	return numero_tropas<= limite_tropas;
}

void Cuartel :: Timer (float t)
{
	Edificio :: Timer (t);
	if (tiempo>=60)
	{
		numero_tropas=0;
	}
	else tiempo++;
}

void Cuartel :: Dibuja (Color equipo) 
{
	setPosicion(5, 5);
	casita(posicion, equipo, color , 4, 5);
}
