#include "Fabrica.h"


Fabrica::Fabrica(Type _tipo, unsigned int nivel):
	tipo(_tipo), 
	Edificio(1000,4,Color (),CUADRADO, Vector (4,4))
{
	switch(tipo){
	case F_ORO:		color.set(245, 208, 51); setPosicion(50,30);	break;
	case F_COMIDA:	color.set(234, 137, 154) ;setPosicion(30,50);	break;
	case F_HIERRO:	color.set(157, 161, 170); setPosicion(40,70);	
	}
	for(int n=0;n<nivel;n++)
		subirNivel();
}

Fabrica::~Fabrica(void)
{
}

void Fabrica :: subirNivel ()
{
	vida_max = vida_max*1.75f;
	vida= vida_max;
	//Si subes de nivel la vida se regenera
	produccion.set(produccion.getComida()+30,produccion.getHierro()+20,produccion.getOro()+20);
	altura+=4;
}

void Fabrica :: Timer (float t)
{
	Edificio :: Timer (t);
}

void Fabrica :: Dibuja (Color equipo)
{

	casita(posicion, equipo, color, superficie, altura);
}

