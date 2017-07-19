#include "Fabrica.h"
#include <iostream>
using namespace std;


Fabrica::Fabrica(Type _tipo,Vector posicion, unsigned int nivel):
	tiempo(0),
	Edificio(1000,4,Color (),CUADRADO, Vector(4,4))
{
	this->tipo= _tipo;
	this -> posicion = posicion;
	especifico=NINGUNO;
	switch(tipo){
	case F_ORO:		color_max.set(245, 208, 51); produccion=2;	break;
	case F_COMIDA:	color_max.set(234, 137, 154); produccion=4;	break;
	case F_HIERRO:	color_max.set(157, 161, 170); produccion=3;	
	}
	color=color_max;
	for(unsigned int n=1;n<nivel;n++)
		subirNivel();
//	rango=-1;
}

Fabrica::~Fabrica(void)
{
}

void Fabrica :: subirNivel ()
{
	vida_max = vida_max*1.25f;
	vida= vida_max;
	altura+=4;
	//Si subes de nivel la vida se regenera
	switch (tipo)
	{
	case F_COMIDA:
		produccion+=2;
		break;
	case F_HIERRO:
		produccion+=1;
		break;
	case F_ORO:
		produccion+=1;
		break;
	}
}

void Fabrica :: Timer (float t)
{
	Edificio :: Timer (t);
	tiempo+=t;
}

void Fabrica :: Dibuja (Color equipo)
{
	casita(posicion, equipo, color, superficie, altura);
}

bool Fabrica :: generar (Recursos& almacen)
{
	if (poderGenerar())
	{
		switch (tipo)
		{
		case F_COMIDA:
			almacen.set(almacen.getComida()+produccion,almacen.getHierro(),almacen.getOro());
			break;
		case F_HIERRO:
			almacen.set(almacen.getComida(),almacen.getHierro()+produccion,almacen.getOro());
			break;
		case F_ORO:
			almacen.set(almacen.getComida(),almacen.getHierro(),almacen.getOro()+produccion);
			break;
		}
		tiempo=0;
	}
	return false;
}

bool Fabrica :: poderGenerar()
{
	if (tiempo>=3)
	{
		return true;
	}
	return false;
}
