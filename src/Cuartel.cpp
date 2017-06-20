#include "Cuartel.h"


Cuartel :: Cuartel(unsigned int nivel):
	tiempo(0), 
	limite_tropas(100), 
	numero_tropas(0), 
	Edificio(1000,4, Color (139,69,19), CUADRADO, Vector (4, 4))
{
	for(int n=0;n<nivel; n++)
		subirNivel();
	rango=-1;
}

Cuartel :: ~Cuartel(void)
{
}

void Cuartel :: subirNivel()
{
	vida_max=vida_max*1.25f;
	vida=vida_max;
	limite+=20;
	altura+=4;
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
	casita(posicion, equipo, color , superficie, altura);
}
