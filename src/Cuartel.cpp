#include "Cuartel.h"


Cuartel :: Cuartel(Vector posicion, unsigned int nivel):
	tiempo(0), 
	limite_tropas(100), 
	numero_tropas(0), 
	Edificio(1000,4, Color (139,69,19), CUADRADO, Vector(4,4))
{
	this->posicion=posicion;
	tipo = CUARTEL;
	especifico = NINGUNO;
	for(unsigned int n=0;n<nivel; n++)
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
	return true;
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
	casita(posicion, equipo, color , superficie, altura);
}

Edificio* Cuartel :: generar (int nivel, Luchadores tipo, Vector destino)
{
	if (tipo == NINGUNO || destino<0)
		return false;
	return new Personaje(tipo, nivel, posicion+superficie+5, destino);
	
}
