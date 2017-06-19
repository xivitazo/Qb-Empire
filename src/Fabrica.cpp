#include "Fabrica.h"


Fabrica::Fabrica(Type _tipo):
	tipo(_tipo), 
	Edificio(100)
{
	switch(tipo){
	case oro:		color.set(245, 208, 51); setPosicion(50,30);	break;
	case comida:	color.set(234, 137, 154) ;setPosicion(30,50);	break;
	case hierro:	color.set(157, 161, 170); setPosicion(40,70);	
	}
}

Fabrica::~Fabrica(void)
{
}

void Fabrica :: subirNivel (unsigned int tipo)
{
	vida = vida*1.75f;
	produccion.set(produccion.getComida()*1.1f,produccion.getHierro()*1.1f,produccion.getOro()*1.1f);
}

void Fabrica :: Timer (float t)
{
	Edificio :: Timer (t);
}

void Fabrica :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, 4,  5);
}

