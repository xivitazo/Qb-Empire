#include "Fabrica.h"


Fabrica::Fabrica(Type _tipo,Vector posicion, unsigned int nivel):
	tipo(_tipo), 
	Edificio(1000,4,Color (),CUADRADO, Vector(4,4))
{
	this -> posicion = posicion;
	this -> tipo= tipo;
	especifico=NINGUNO;
	switch(tipo){
	case F_ORO:		color.set(245, 208, 51);	break;
	case F_COMIDA:	color.set(234, 137, 154) ;	break;
	case F_HIERRO:	color.set(157, 161, 170);	
	}
	for(unsigned int n=0;n<nivel;n++)
		subirNivel();
	rango=-1;
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
bool Fabrica :: generar (Edificio ** tropa, int nivel, Luchadores tipo)
{
	if (poderGenerar())
		;
	return true;
}

